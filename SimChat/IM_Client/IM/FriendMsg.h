#pragma once

#include <QWidget>
namespace Ui { class FriendMsg; };

class FriendMsg : public QWidget
{
	Q_OBJECT

public:
	FriendMsg(int pic,int num,QWidget *parent);
	~FriendMsg();

private:
	Ui::FriendMsg *ui;
	int jkNum;//���ͷŵ�Num
private slots:
	void on_agree_triggered();
	void on_decline_triggered();
};
