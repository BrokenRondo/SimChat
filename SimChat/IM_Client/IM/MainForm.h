#pragma once

#include <QWidget>
#include "moveableframelesswindow.h"
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "socketRecvTools.h"
#include "FriendMsg.h"
#include "Search.h"
#include <string>
#include "CollapseView.h"

using namespace std;

namespace Ui { class MainForm; };

class MainForm : public MoveableFramelessWindow
{
	Q_OBJECT

public:
	explicit MainForm(QWidget *parent = Q_NULLPTR);
	~MainForm();

	void result(int pic, std::string name, char result);
	//void showFriendMsg(int pic, int Num, std::string name, std::string src_listName);

private:
	Ui::MainForm *ui;
	CollapseView* collapse_view;
	QVBoxLayout *page4_layout;
	QSystemTrayIcon *mSysTrayIcon;
	QMenu *m_menu;
	QAction * m_action;
	socketRecvTools *srt;
	std::vector<FriendMsg *>friend_msg;//用来存放n个添加好友消息的数组
	int friendMsgCount;//好友消息个数
	Search* search;
	
protected:
	QWidget* getDragnWidget() override;
	void showMenu();
	void m_exit();
private slots:
	void on_PB_minimize_clicked();
	void on_PB_shutdown_clicked();
	void onActivitedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
	void initchat(int, QString);
	void showMSGBox(int, QString);
	void refreshFriendList(int jkNum, bool online);
	void showFriendMsg(int, int);
	void searchWidget();
	void addfriendConfirm(int, int, char*,char*);
	//void result(int pic, std::string name, char result);
};
