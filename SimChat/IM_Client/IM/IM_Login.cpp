#include "IM_Login.h"
#include <QMovie>
#include <QMessageBox>
#include <QString>
#include <QWaitCondition>
#include <QDebug>
#include <queue>
#include "connecting.h"
#include "ui_connecting.h"
#include "Msg_H.h"
#include "osapi/osapi.h"
#include "tools/PackageTool.h"
#include "socket_waitPackage.h"
#include "parseTool.h"
#include "MainForm.h"
#include "socketSendTools.h"
#include "MsgText.h"
#include "RegisterDia.h"

#define serverJK 111112222
OS_TcpSocket client_socket;
bool Connecting = false;
queue<MsgText*> MsgQueue;
int myJKNum;
int isOpen;
IM_Login::IM_Login(QWidget *parent)
	: MoveableFramelessWindow(parent)
{
	
	ui->setupUi(this);
	//QMovie *movie = new QMovie(":/sys/img/blue70-2.gif");
	QPixmap pix = QPixmap(":/sys/img/top.png");
	//ui->label->setMovie(movie);
	ui->label->setPixmap(pix);
	ui->label->show();
	ui->label_minimize->installEventFilter(this);
	ui->label_shutdown->installEventFilter(this);
	//ע���˺�label
	ui->label_1->installEventFilter(this);
	//movie->start();
	isOpen = 0;
	
	
	connect(ui->pushButton_login, SIGNAL(clicked(bool)), this, SLOT(process()));
}

IM_Login::~IM_Login()
{
}
QWidget *IM_Login::getDragnWidget()
{
	return ui->login_top_widget;
}
bool IM_Login::eventFilter(QObject *object, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress&&object == ui->label_shutdown)
	{
		if (isOpen)
		{
			client_socket.Close();
		}
		ExitProcess(0);
		//return true;
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_minimize) {
		showMinimized();
		return true;//ֹͣת��
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_1) {
		RegisterDia *rg_dialog = new RegisterDia;
		rg_dialog->show();
	}
	return false; //����ת��
}
void IM_Login::startConnecting()
{
	//con=new connecting();
	//con->show();
	//this->hide();
	ui->pushButton_login->setText(QString::fromLocal8Bit("��¼��......"));
	qApp->processEvents();
	
}

void IM_Login::Connecting()
{
	//��ȡ�û�������˺ź�����
	
	/*Ӧ��ֻҪ����˾ͻ�����¼���棬����ɹ���������棬������ɹ��򷵻ص�½����*/
	
	int iscorrect = UserAuthentication();
	if (iscorrect == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("�û������������"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("��¼"));
		//Connecting = false;
		this->show();
	}
	if (iscorrect==-1)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("�޷����ӷ�����"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("��¼"));
		//Connecting = false;
		this->show();
	}
	if (iscorrect==2)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("�û�������"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("��¼"));
		//Connecting = false;
		this->show();
	}
	else
	{
		MainForm *m = new MainForm;
		//Connecting = false;
		m->show();
		//con->hide();
		this->hide();
		myJKNum = ui->lineEdit_un->text().toInt();
		socketSendTools *sstools = new socketSendTools();//�½��������͵��߳�
		sstools->start();
	}

}
void IM_Login::connected()
{
	//con->hide();
}

void IM_Login::process()
{
	if (ui->lineEdit_un->text().length()>9)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ȷ�ĺ���"));
		return;
	}
	startConnecting();
	Connecting();
	connected();
}

int IM_Login::UserAuthentication()
{
	QString userNum = ui->lineEdit_un->text();
	QString userpwd = ui->lineEdit_pass->text();
	std::string user_num_str=userNum.toStdString();
	std::string user_pwd_str=userpwd.toStdString();
	MsgLogin msg_login;
	//msg_login.setJKNum(user_num_str);
	msg_login.setPwd(user_pwd_str);
	int len = 23;
	char type = 0x02;
	msg_login.setTotalLen(len);
	msg_login.setType(type);
	msg_login.setDest(serverJK);
	msg_login.setSrc(std::stoi(user_num_str));
	OS_SockAddr serv_addr("172.93.43.191", 10086);
	client_socket.Open();
	if (client_socket.Connect(serv_addr) < 0)
	{
		qDebug("�޷����ӷ�����\n");
		return -1;
	}

	
	char buf[50];
	PackageTools pgt;
	pgt.packMsgLogin(buf, msg_login);
	client_socket.Send(buf, len);
	memset(buf, 0xff, 50);
	//����Ҫ�жϳ���
	client_socket.Recv(buf, 4);
	int pack_len[1];
	memcpy(pack_len, buf, 4);
	pack_len[0] = ntohl(pack_len[0])-4;//��ȥ������ʾ���ȵ���λ
	//Ȼ���ٶ�ȡһ������
	socket_waitPackage socket_wait;
	socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
	//�����Ժ����
	//�����ж���ʲô���͵İ�,����һ���ֽ�
	parseTool parse_tool;
	if (buf[0]!=0x22)
	{
		qDebug("�޷�����������ݰ�\n");
		return -1;
	}
	char *buf_s = buf;
	MsgLoginResp mlr = parse_tool.parse_msg_login_resp(buf_s, pack_len[0]);
	if (mlr.getState() == 0)return 1;//����1��ʾ��֤ͨ��
	if (mlr.getState()==2)
	{
		return 2;
	}
	
	return 0;
}

