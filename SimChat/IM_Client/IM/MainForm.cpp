#include "MainForm.h"
#include "ui_MainForm.h"
#include "CollapseView.h"
#include <QDesktopWidget>
#include <QString>
#include "socketRecvTools.h"
#include "LitterIem.h"
#include <string>

using namespace std;
//主窗口贴边，与屏幕边缘的距离
int MAIN_FORM_OADDING = 10;
extern std::vector<LitterIem*> litterIems;
MainForm *mainform;
string src_listName;
extern GroupList groupList;
MainForm::MainForm(QWidget *parent)
	: MoveableFramelessWindow(parent)
{
	ui = new Ui::MainForm();
	ui->setupUi(this);
	friendMsgCount = 0;
	page4_layout = new QVBoxLayout(this);
	page4_layout->setContentsMargins(0, 0, 0, 0);//设置四边边距都为0
	page4_layout->setSpacing(0);//This property holds the spacing between widgets inside the layout.
	ui->page_4->setLayout(page4_layout);

	//在布局中加入联系人列表
	collapse_view = new CollapseView();
	page4_layout->addWidget(collapse_view);

	//获取屏幕
	this->setAttribute(Qt::WA_DeleteOnClose);

	srt = new socketRecvTools();//开启recv线程
	srt->start();

	
	//connect(srt, SIGNAL(ShowResult(int, std::string, char)), this, SLOT(result(int, std::string, char)));
	

	QDesktopWidget* desktopWidget = QApplication::desktop();

	//得到屏幕宽度
	int screenWidth = desktopWidget->width();
	this->move(screenWidth - MAIN_FORM_OADDING - this->width(), MAIN_FORM_OADDING);

	
	m_menu = new QMenu(this);
	m_action = new QAction(m_menu);
	m_action->setText(QString::fromLocal8Bit("退出"));
	m_menu->addAction(m_action);

	//新建QSystemTrayIcon对象
	mSysTrayIcon = new QSystemTrayIcon(this);
	//新建托盘要显示的icon
	QIcon icon = QIcon(":/sys/QQ.png");
	//将icon设到QSystemTrayIcon对象中
	mSysTrayIcon->setIcon(icon);
	//当鼠标移动到托盘上的图标时，会显示此处设置的内容
	mSysTrayIcon->setToolTip(QObject::trUtf8("QQ"));
	mSysTrayIcon->setContextMenu(m_menu);
	//在系统托盘显示此对象
	mSysTrayIcon->show();


	search = new Search();
	connect(m_action, &QAction::triggered, this, &MainForm::m_exit);//关联右击的操作
	connect(mSysTrayIcon, &QSystemTrayIcon::activated, this, &MainForm::onActivitedSysTrayIcon);//关联左击或者右击的操作

	connect(srt, SIGNAL(initChat(int, QString)), this, SLOT(initchat(int, QString)));
	connect(srt, SIGNAL(Messagebox(int, QString)), this, SLOT(showMSGBox(int, QString)));
	connect(srt, SIGNAL(FriendBox(int, int)), this, SLOT(showFriendMsg(int, int)));
	connect(srt, SIGNAL(AddFriendConfirm(int, int, char*,char*)), this, SLOT(addfriendConfirm(int, int, char*,char*)));
	connect(ui->pushButton_minimize, SIGNAL(pressed()), this, SLOT(on_PB_minimize_clicked()));
	connect(ui->pushButton_shutdown, SIGNAL(pressed()), this, SLOT(on_PB_shutdown_clicked()));
	connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(searchWidget()));
	mainform = this;
}

MainForm::~MainForm()
{
	delete ui;
}
QWidget *MainForm::getDragnWidget()
{
	return ui->main_top;
}

void MainForm::on_PB_minimize_clicked()
{
	this->showMinimized();
}
void MainForm::m_exit()
{
	exit(0);
}

void MainForm::on_PB_shutdown_clicked()
{
	ExitProcess(0);
}
void MainForm::showMenu()
{
	m_menu->show();
}
void MainForm::initchat(int jkNum,QString msg)
{
	int i = 0;
	for	(i=0;i<litterIems.size();i++)
	{
		if (litterIems[i]->getJkNum()==jkNum)
		{
			break;
		}
	}
	//找到是哪个litteritem后
	litterIems[i]->init();
	litterIems[i]->chat->recvShowMsg(msg);
}
void MainForm::showMSGBox(int jkNum, QString msg)
{
	int i = 0;
	for (i = 0; i < litterIems.size(); i++)
	{
		if (litterIems[i]->getJkNum() == jkNum)
		{
			break;
		}
	}
	litterIems[i]->m_mbox = true;
	litterIems[i]->showMsgBox(msg);
}

void MainForm::onActivitedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
		this->showNormal();
	case QSystemTrayIcon::Context:
		showMenu();
	}
}

void MainForm::refreshFriendList(int jkNum,bool online)//如果有好友上线或者离线
{
	//找到这个好友的item
	int i = 0;
	for (int i = 0; i < litterIems.size(); i++)
	{
		if (litterIems[i]->getJkNum()==jkNum)
		{
			break;
		}
	}
	//找到后设置头像
	
	litterIems[i]->refreshPic(online);
	
}
void MainForm::showFriendMsg(int pic, int Num)
{
 	FriendMsg* Friend= new FriendMsg(pic, Num,this);
	friend_msg.push_back(Friend);
	friend_msg[friendMsgCount]->show();
	friendMsgCount++;
}
void MainForm::searchWidget()
{
	search->show();
}

void MainForm::addfriendConfirm(int jkNum, int pic, char * itemname, char* listname)
{
	//找到是第几个分组
	char itemName[11];
	memcpy(itemName, itemname, 10);
	std::string nickname = itemName;
	int i = 0;
	for (i = 0; i < groupList.groupList.size(); i++)
	{
		if (groupList.groupList[i].listName == listname)
			break;
	}
	if (i == groupList.groupList.size())
	{
		qDebug() << "Not from server or other error";
		return;
	}
	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg(QString::number(pic));
	LitterIem* item = new LitterIem(pic, 1, listname, jkNum, nickname, collapse_view->collapse_view_List[i]);
	collapse_view->collapse_view_List[i]->addSubItem(item);
	litterIems.push_back(item);
	//delete item;
}


void MainForm::result(int pic, std::string name, char result)
{
	qDebug("showRes");
	search->showResult(pic, name, result);
}


