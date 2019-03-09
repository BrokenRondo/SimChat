#pragma once

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include "osapi/Mutex.h"

namespace Ui { class Search; };

class Search : public QWidget
{
	Q_OBJECT

public:
	Search(QWidget *parent = Q_NULLPTR);
	~Search();
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
	void doSearch(QString message);
	void showResult(int pic, std::string name,char result);
protected:
	void showEvent(QShowEvent *event);

private slots:
	void on_pushButton_2_ckecked();
	void on_pushButton_clicked();
private:
	Ui::Search *ui;
	OS_Mutex mtx;
	int jkNum;
};
