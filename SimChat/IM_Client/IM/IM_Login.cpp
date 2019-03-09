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
	//注册账号label
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
		return true;//停止转发
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_1) {
		RegisterDia *rg_dialog = new RegisterDia;
		rg_dialog->show();
	}
	return false; //继续转发
}
void IM_Login::startConnecting()
{
	//con=new connecting();
	//con->show();
	//this->hide();
	ui->pushButton_login->setText(QString::fromLocal8Bit("登录中......"));
	qApp->processEvents();
	
}

void IM_Login::Connecting()
{
	//获取用户输入的账号和密码
	
	/*应该只要点击了就会进入登录界面，如果成功则打开主界面，如果不成功则返回登陆界面*/
	
	int iscorrect = UserAuthentication();
	if (iscorrect == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("用户名或密码错误！"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("登录"));
		//Connecting = false;
		this->show();
	}
	if (iscorrect==-1)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("无法连接服务器"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("登录"));
		//Connecting = false;
		this->show();
	}
	if (iscorrect==2)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("用户已在线"));
		ui->pushButton_login->setText(QString::fromLocal8Bit("登录"));
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
		socketSendTools *sstools = new socketSendTools();//新建用来发送的线程
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
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("请输入正确的号码"));
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
		qDebug("无法连接服务器\n");
		return -1;
	}

	
	char buf[50];
	PackageTools pgt;
	pgt.packMsgLogin(buf, msg_login);
	client_socket.Send(buf, len);
	memset(buf, 0xff, 50);
	//首先要判断长度
	client_socket.Recv(buf, 4);
	int pack_len[1];
	memcpy(pack_len, buf, 4);
	pack_len[0] = ntohl(pack_len[0])-4;//减去用来表示长度的四位
	//然后再读取一定长度
	socket_waitPackage socket_wait;
	socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
	//读完以后解析
	//首先判断是什么类型的包,读第一个字节
	parseTool parse_tool;
	if (buf[0]!=0x22)
	{
		qDebug("无法解析这个数据包\n");
		return -1;
	}
	char *buf_s = buf;
	MsgLoginResp mlr = parse_tool.parse_msg_login_resp(buf_s, pack_len[0]);
	if (mlr.getState() == 0)return 1;//返回1表示认证通过
	if (mlr.getState()==2)
	{
		return 2;
	}
	
	return 0;
}

