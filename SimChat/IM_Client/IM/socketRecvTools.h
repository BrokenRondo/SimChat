#pragma once
#include <mutex>
#include <QThread>
#include <QObject>
#include "SingleItem.h"
#include<string>
using namespace::std;
class socketRecvTools:public QThread
{
	Q_OBJECT
public:
	socketRecvTools() :stopped(false) {}
signals:
	void initChat(int,QString);
	void Messagebox(int, QString);
	void FriendBox(int, int);
	void AddFriendConfirm(int, int, char*,char*);
	//void ShowResult(int pic,std::string name,char result);

private:
	void run() override;
	bool stopped;
	std::mutex mtx;
};
