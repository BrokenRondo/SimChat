#include "MyMessageBox.h"
#include "ui_MyMessageBox.h"
#include  <QDesktopWidget>
#include <QListWidget>
#include <QRect>
#include <qrect.h>
#include "LitterIem.h"
#include "msgboxWidget.h"

extern std::vector<LitterIem*> litterIems;
MyMessageBox::MyMessageBox(int pic,int state,int jkNum,std::string nickName,QString msg, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::MyMessageBox();
	ui->setupUi(this);
	this->pic = pic;
	this->state = state;
	this->jkNum = jkNum;
	this->nickName = nickName;
	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg(QString::fromStdString(std::to_string(pic)));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);
	ui->label_2->installEventFilter(this);
	QRect rect = QApplication::desktop()->availableGeometry();
	move(rect.width() - width() - 10, rect.height() - height() - 3);
	QListWidgetItem* item1 = new QListWidgetItem();
	item1->setSizeHint(QSize(0, 70));
	 m = new msgboxWidget(jkNum,QString::fromStdString(nickName),msg,picPath,this);
	ui->listWidget->addItem(item1);
	ui->listWidget->setItemWidget(item1, m);
	connect(m, SIGNAL(msgboxClicked()), this, SLOT(mboxClicked()));
}

MyMessageBox::~MyMessageBox()
{
	delete ui;
}
bool MyMessageBox::eventFilter(QObject* object, QEvent* e)
{
	if (e->type() == QEvent::MouseButtonPress&&object == ui->label_2)
	{
		hide();
	}
	if (e->type() == QEvent::MouseButtonPress&&object == ui->listWidget)//如果点击了消息
	{
		int i = 0;
		for (i = 0; i < litterIems.size(); i++)
		{
			if (litterIems[i]->getJkNum() == jkNum)
			{
				break;
			}
		}
		litterIems[i]->chat->showNormal();
		this->hide();
		litterIems[i]->clearNotice();
	}
	return true;
}
void MyMessageBox::mboxClicked()
{
	this->close();
	emit m_mboxclose();
}


