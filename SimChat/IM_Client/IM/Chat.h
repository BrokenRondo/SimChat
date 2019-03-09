#pragma once

#include <QWidget>
#include<QMouseEvent>
#include<QtGui>
#include<QDebug>
#include<QScrollBar>
#include<QFile>
#include "Emotion.h"
#include "SingleItem.h"
#include <osapi/Mutex.h>
#include <QtMultimedia/QSound>



namespace Ui { class Chat; };

class Chat : public QWidget
{
	Q_OBJECT

public:
	explicit 	Chat(int jkNum, char state, int pic, std::string nickName, QWidget *parent = Q_NULLPTR);
	~Chat();
	QPoint move_point; //移动的距离

	bool mouse_press; //鼠标按下
	//鼠标按下事件
	void mousePressEvent(QMouseEvent *event);
	//鼠标释放事件
	void mouseReleaseEvent(QMouseEvent *event);
	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent *event);
	//最小化及关闭
	bool eventFilter(QObject *object, QEvent *e);
	void recvShowMsg(QString msg);
	void alert();//任务栏图标闪烁
signals:
	void sendClose();
protected:
	void showEvent(QShowEvent *event);

private slots:
	void on_pushButton_2_clicked();
	void sendemotion(QString s);
	void refreshText();
private:
	Ui::Chat *ui;
	Emotion* emotion;
	int jkNum;
	char state;
	int pic;
	std::string nickName;
	OS_Mutex mutex;
	QSoundEffect *m_pEffect;
};
