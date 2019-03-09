#include "FriendMsg.h"
#include "GeneratedFiles/ui_FriendMsg.h"
#include "GroupList.h"
#include "MsgAddFriendResp.h"
#include "MsgText.h"
#include <Queue>
#include <QDesktopWidget>
#include "parseTool.h"
#include "tools/PackageTool.h"

extern GroupList groupList;
extern int myJKNum;
extern std::queue<MsgText*> MsgQueue;
extern string src_listName;
FriendMsg::FriendMsg(int pic, int num, QWidget *parent = Q_NULLPTR)
	: QWidget(parent)
{
	ui = new Ui::FriendMsg();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg(QString::number(pic));
	QPixmap p(picPath);
	ui->label_4->setPixmap(p);
	ui->label_6->setText(QString::fromLocal8Bit("ÐÂµÄºÃÓÑ"));
	ui->label_7->setText(QString::number(num));
	this->jkNum = num;
	for (int i = 0; i < groupList.groupList.size(); i++)
	{
		ui->comboBox->addItem(QString::fromLocal8Bit(groupList.groupList[i].listName.data()));
	}
	QRect rect = QApplication::desktop()->availableGeometry();
	move(rect.width() - width() - 10, rect.height() - height() - 3);
	connect(ui->pushButton_agree, SIGNAL(clicked()), this, SLOT(on_agree_triggered()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_decline_triggered()));
}

FriendMsg::~FriendMsg()
{
	delete ui;
}
void FriendMsg::on_agree_triggered()
{
	int listloc = ui->comboBox->currentIndex();
	MsgAddFriendResp *add_friend_resp = new MsgAddFriendResp();
	add_friend_resp->setType(0x44);
	add_friend_resp->setTotalLen(42);
	add_friend_resp->setDest(jkNum);
	add_friend_resp->setSrc(myJKNum);
	add_friend_resp->setlist_name(src_listName);
	add_friend_resp->setAgreeListName(groupList.groupList[listloc].listName);
	add_friend_resp->setAgreeId(myJKNum);
	add_friend_resp->setAdd_id(jkNum);
	add_friend_resp->setState(0x01);
	PackageTools *ptool = new PackageTools();
	char* buf = new char[50];
	memset(buf,0,50);
	ptool->packMsgAddFriendResp(buf, add_friend_resp);
	MsgText *mtext = new MsgText(buf,42);
	MsgQueue.push(mtext);
	delete[] buf;
	this->close();
}
void FriendMsg::on_decline_triggered()
{
	this->close();
}
