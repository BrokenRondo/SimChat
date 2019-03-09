#include "MainForm.h"
#include "ui_MainForm.h"
#include "CollapseView.h"
#include <QDesktopWidget>
#include <QString>
#include "socketRecvTools.h"
#include "LitterIem.h"
#include <string>

using namespace std;
//���������ߣ�����Ļ��Ե�ľ���
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
	page4_layout->setContentsMargins(0, 0, 0, 0);//�����ı߱߾඼Ϊ0
	page4_layout->setSpacing(0);//This property holds the spacing between widgets inside the layout.
	ui->page_4->setLayout(page4_layout);

	//�ڲ����м�����ϵ���б�
	collapse_view = new CollapseView();
	page4_layout->addWidget(collapse_view);

	//��ȡ��Ļ
	this->setAttribute(Qt::WA_DeleteOnClose);

	srt = new socketRecvTools();//����recv�߳�
	srt->start();

	
	//connect(srt, SIGNAL(ShowResult(int, std::string, char)), this, SLOT(result(int, std::string, char)));
	

	QDesktopWidget* desktopWidget = QApplication::desktop();

	//�õ���Ļ���
	int screenWidth = desktopWidget->width();
	this->move(screenWidth - MAIN_FORM_OADDING - this->width(), MAIN_FORM_OADDING);

	
	m_menu = new QMenu(this);
	m_action = new QAction(m_menu);
	m_action->setText(QString::fromLocal8Bit("�˳�"));
	m_menu->addAction(m_action);

	//�½�QSystemTrayIcon����
	mSysTrayIcon = new QSystemTrayIcon(this);
	//�½�����Ҫ��ʾ��icon
	QIcon icon = QIcon(":/sys/QQ.png");
	//��icon�赽QSystemTrayIcon������
	mSysTrayIcon->setIcon(icon);
	//������ƶ��������ϵ�ͼ��ʱ������ʾ�˴����õ�����
	mSysTrayIcon->setToolTip(QObject::trUtf8("QQ"));
	mSysTrayIcon->setContextMenu(m_menu);
	//��ϵͳ������ʾ�˶���
	mSysTrayIcon->show();


	search = new Search();
	connect(m_action, &QAction::triggered, this, &MainForm::m_exit);//�����һ��Ĳ���
	connect(mSysTrayIcon, &QSystemTrayIcon::activated, this, &MainForm::onActivitedSysTrayIcon);//������������һ��Ĳ���

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
	//�ҵ����ĸ�litteritem��
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

void MainForm::refreshFriendList(int jkNum,bool online)//����к������߻�������
{
	//�ҵ�������ѵ�item
	int i = 0;
	for (int i = 0; i < litterIems.size(); i++)
	{
		if (litterIems[i]->getJkNum()==jkNum)
		{
			break;
		}
	}
	//�ҵ�������ͷ��
	
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
	//�ҵ��ǵڼ�������
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


