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
	QPoint move_point; //�ƶ��ľ���

	bool mouse_press; //��갴��
	//��갴���¼�
	void mousePressEvent(QMouseEvent *event);
	//����ͷ��¼�
	void mouseReleaseEvent(QMouseEvent *event);
	//����ƶ��¼�
	void mouseMoveEvent(QMouseEvent *event);
	//��С�����ر�
	bool eventFilter(QObject *object, QEvent *e);
	void recvShowMsg(QString msg);
	void alert();//������ͼ����˸
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
