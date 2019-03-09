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
