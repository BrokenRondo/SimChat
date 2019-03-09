#pragma once

#include <QWidget>
#include "msgboxWidget.h"
class SingleItem;

namespace Ui { class MyMessageBox; };

class MyMessageBox : public QWidget
{
	Q_OBJECT

public:
	explicit MyMessageBox(int pic, int state, int jkNum, std::string nickName,QString msg,QWidget *parent = Q_NULLPTR);
	~MyMessageBox();
	bool eventFilter(QObject* object, QEvent* e) override;
	msgboxWidget* m;
signals:
	void m_mboxclose();
private slots:
	void mboxClicked();
private:
	Ui::MyMessageBox *ui;
	int jkNum;
	char state;
	int pic;
	std::string nickName;
};
