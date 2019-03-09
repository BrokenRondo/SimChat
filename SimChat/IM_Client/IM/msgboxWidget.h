#pragma once

#include <QWidget>
namespace Ui { class msgboxWidget; };

class msgboxWidget : public QWidget
{
	Q_OBJECT

public:
	msgboxWidget(int jkNum,QString nickName,QString msg,QString picPath,QWidget *parent = Q_NULLPTR);
	~msgboxWidget();
	void addMsg(QString msg);//δ����Ϣ+1
protected:
	void mouseDoubleClickEvent(QMouseEvent* event);
signals:
	void msgboxClicked();
private:
	Ui::msgboxWidget *ui;
	QString picPath;
	QString nickName;
	QString msg;
	int jkNum;
	int msgNum;//�м���δ����Ϣ
};
