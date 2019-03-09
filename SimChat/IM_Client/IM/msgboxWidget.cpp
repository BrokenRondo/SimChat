#include "msgboxWidget.h"
#include "ui_msgboxWidget.h"
#include "LitterIem.h"

extern std::vector<LitterIem*> litterIems;
msgboxWidget::msgboxWidget(int jknum,QString nickName, QString msg, QString picPath, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::msgboxWidget();
	ui->setupUi(this);
	msgNum = 1;
	QPixmap p(picPath);
	this->jkNum = jknum;
	this->nickName = nickName;
	this->msg = msg;
	this->picPath = picPath;
	ui->label_2->setPixmap(p);
	ui->label_4->setText(msg);
	ui->label_3->setText(nickName);
	ui->label->setText(QString::number(msgNum));

}

msgboxWidget::~msgboxWidget()
{
	delete ui;
}
void msgboxWidget::addMsg(QString msg)
{
	if (msgNum<99)
	{
		msgNum += 1;
	
	}
	ui->label_4->setText(msg);
	QString num = QString::number(msgNum);
	ui->label->setText(num);
}

void msgboxWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	int i = 0;
	for (i = 0; i < litterIems.size(); i++)
	{
		if (litterIems[i]->getJkNum() == jkNum)
		{
			break;
		}
	}
	if (!litterIems[i]->openOrNot())
	{
		//litterIems[i]->init();
		litterIems[i]->chat->showNormal();
		emit msgboxClicked();
	}
	else
	{
		litterIems[i]->chat->showNormal();
		litterIems[i]->clearNotice();
		this->close();
		emit msgboxClicked();
	}
}
