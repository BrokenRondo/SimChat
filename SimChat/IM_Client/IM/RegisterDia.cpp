#include "RegisterDia.h"
#include "ui_RegisterDia.h"
#include <QMessageBox>
#include "Msg/MsgReg.h"
#include "osapi/Socket.h"
#include "tools/PackageTool.h"
#include "parseTool.h"
#include "socket_waitPackage.h"

extern OS_TcpSocket client_socket;
RegisterDia::RegisterDia(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::RegisterDia();
	ui->setupUi(this);
	connect(ui->PB_sure, SIGNAL(clicked()), this, SLOT(PB_sure_clicked()));
	connect(ui->PB_cancel, SIGNAL(clicked()), this, SLOT(PB_cancle_clicked()));
	setAttribute(Qt::WA_DeleteOnClose);
}

RegisterDia::~RegisterDia()
{
	delete ui;
}
void RegisterDia::PB_sure_clicked()
{

	OS_SockAddr serv_addr("172.93.43.191", 10086);
	OS_TcpSocket client;
	client.Open();
	if (client.Connect(serv_addr) < 0)
	{
		qDebug("无法连接服务器\n");
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("无法连接服务器"));
		this->close();
		//return ;
	}
	QString userNameQ = ui->LE_username->text();
	QString userpwd = ui->LE_pwd->text();

	if (userNameQ.isEmpty() || userpwd.isEmpty())
	{
		QMessageBox::information(this, tr("提示"), tr("请输入完整信息"));
		return;
	}
	MsgReg *mreg = new MsgReg(); 
	mreg->setName(userNameQ.toStdString());
	mreg->setPasswd(userpwd.toStdString());
	mreg->setTotalLen(33);
	mreg->setType(0x01);
	mreg->setDest(111112222);
	mreg->setSrc(222221111);
	PackageTools *ptools = new PackageTools();
	char buf[50] = { 0 };
	ptools->packMsgReg(buf, mreg);
	client.Send(buf, 33);
	memset(buf, 0xff, 50);
	//首先要判断长度
	client.Recv(buf, 4);
	int pack_len[1];
	memcpy(pack_len, buf, 4);
	pack_len[0] = ntohl(pack_len[0]) - 4;//减去用来表示长度的四位
	//然后再读取一定长度
	socket_waitPackage socket_wait;
	socket_wait.WaitBytes(client, buf, pack_len[0], 0);
	//读完以后解析
	//首先判断是什么类型的包,读第一个字节
	parseTool parse_tool;
	char* buf_s = buf;
	if (buf[0] != 0x06)
	{
		qDebug("无法解析这个数据包\n");
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("无法连接服务器"));
		client.Close();
		this->close();
		return;
	}
	MsgRegResp* mrrsp = parse_tool.parse_RegResp(buf_s);
	if (mrrsp->state==1)
	{
		QString text = QString::fromLocal8Bit("注册成功！获得的号码为%1，请妥善保管！").arg(QString::number(mrrsp->JKNum));
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), text);
	}
	ui->PB_sure->setEnabled(false);
	client.Close();
}
void RegisterDia::PB_cancle_clicked()
{
	this->deleteLater();
}

