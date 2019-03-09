#include "Chat.h"
#include "ui_Chat.h"
#include <QDesktopWidget>
#include <queue>
#include "Msg/MsgChat.h"
#include <QMessageBox>
#include "tools/PackageTool.h"
#include "MsgText.h"
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

extern std::queue<MsgText*> MsgQueue;
extern int myJKNum;
Chat::Chat(int jkNum, char state, int pic, std::string nickName, QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Chat();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_DeleteOnClose);

	this->jkNum = jkNum;
	this->state = state;
	this->pic = pic;
	this->nickName = nickName;

	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg((QString::number(pic)));
	QPixmap p;
	p.load(picPath);
	ui->label->setPixmap(p);
	ui->label_4->installEventFilter(this);
	ui->label_5->installEventFilter(this);
	ui->label_2->setText(QString::fromStdString(nickName));
	QFile file(":/myqss/scrollbar.qss");
	file.open(QFile::ReadOnly);
	ui->textBrowser->verticalScrollBar()->setStyleSheet(file.readAll());
	ui->label_8->installEventFilter(this);
	move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height() - 20) / 2);
	emotion = new Emotion();
	connect(emotion, SIGNAL(imgurl(QString)), this, SLOT(sendemotion(QString)));
	connect(ui->textBrowser, SIGNAL(textChanged()), this,SLOT(refreshText()));
}

Chat::~Chat()
{
	delete ui;
}
void Chat::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		this->setMouseTracking(true);
		mouse_press = true;
		//鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
		move_point = event->pos();
		qDebug() << "MOVE1";
		qDebug() << event->source();
	}

}

void Chat::mouseReleaseEvent(QMouseEvent *event)
{
	//设置鼠标为未被按下
	mouse_press = false;

}

void Chat::mouseMoveEvent(QMouseEvent *event)
{
	//若鼠标左键被按下
  //  qDebug()<<"mouse_press="<<event->globalPos();
	if (mouse_press)
	{

		//鼠标相对于屏幕的位置
		QPoint move_pos = event->globalPos();
		//移动主窗体位置
		this->move(move_pos - move_point);
	}
}

bool Chat::eventFilter(QObject *object, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress&&object == ui->label_5)
	{
		emit sendClose();
		close();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_4) {
		showMinimized();
		qDebug() << "MIN";
		qDebug() << mouse_press;

	}
	//表情发送
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_8) {

		qDebug() << ui->label_8->x();
		qDebug() << x();
		emotion->move(x() - 10, ui->label_8->y() - 100);
		emotion->show();

	}
	return false;
}
void Chat::showEvent(QShowEvent *event)
{
	qDebug() << "SHOW";
	this->move((QApplication::desktop()->width() - this->width()) / 2, (QApplication::desktop()->height() - this->height()) / 2);
	
	mouse_press = false;
	qDebug() << mouse_press;
}



void Chat::on_pushButton_2_clicked()
{
	if (ui->textEdit->toPlainText().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("消息不能为空"));
		return;
	}
	QString content = ui->textEdit->toPlainText();
	if (content.length()>2048)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("内容过长！"));
		return;
	}
	qDebug() << content.length();
	if (content.length() >= 23) {
		qDebug() << "send clicked";
		/*QString s1 = "<img width='30' height='30' src='qrc:/10.jpeg' style='float:right;margin-left:15px;margin-right:15px;'><div style='background:rgb(18,183,245);padding-top:8px;float:right;margin-top:10px;margin-right:45px;padding:10px;margin-left:60px;'><span style='height:5px;  width:5px;border - width:8px;border - style:solid;border color:rgb(18,183,245);right:-16px;top:3px;color:white; font-size:16px;line-hight:16px;font-family:'Microsoft Yahei';margin-top:2px;'>" + content + "</span></div><br><br><br>";*/
		QString s1 = QString(
			R"(<img width='30' height='30' src=':/media/person/media/person/%1.jpg' style='float:right;margin-left:15px;margin-right:15px;'><div style='background:rgb(18,183,245);padding-top:8px;float:right;margin-top:4px;margin-right:45px;padding:10px;margin-left:60px;'><span style="color:white;font-size:16px;font-family:'Microsoft YaHei';margin-top:2px;">%2</span></div><br><br><br>)").arg(QString::number(pic)).arg(content);
		qDebug() << s1;
		ui->textBrowser->insertHtml(s1);
	}
	else {
		int flag = 60 + (24 - content.length()) * 15;
		QString myflag = QString::number(flag, 10);;
		qDebug() << myflag;
		QString s1 = "<img width='30' height='30' src=':/media/person/media/person/5.jpg' style='float:right;margin-left:15px;margin-right:15px;'><div style='background:rgb(18,183,245);padding-top:8px;float:right;margin-top:4px;margin-right:45px;padding:10px;margin-left:" + myflag + "px;'>";
		s1 += "<span style=\"color:white;font-size:16px;font-family:'Microsoft YaHei';margin-top:2px;\">" + content + "</span></div><br><br><br>";
		qDebug() << s1;
		ui->textBrowser->insertHtml(s1);
	}
	MsgChat *mchat = new MsgChat(myJKNum, jkNum, content.toStdString());
	//将mchat打包好变成string
	char* buf = new char[2048];
	PackageTools *ptools = new PackageTools();
	ptools->packMsgChat(buf, mchat);
	MsgText* mText = new MsgText();
	memcpy(mText->buf, buf, mchat->getTotalLen());
	mText->length = mchat->getTotalLen();
	mutex.Lock();
	MsgQueue.push(mText);
	Sleep(26);
	delete mchat;
	delete[] buf;
	delete mText;
	mutex.Unlock();
	
	ui->textEdit->clear();
}
void Chat::sendemotion(QString s)
{
	qDebug() << "选择了发送表情";
	QString tt = tr(": / media / person / media / person / 4.jpg");
	QString s1 = "<img width='30' height='30' src=': /media/ person/ media/person/5.jpg' style='float:right;margin-left:15px;margin-right:15px;'><div style='background:rgb(205,215,226);padding-top:8px;float:right;margin-top:10px;margin-right:45px;padding:10px;margin-left:387px;'><img src='" + s + "'></div><br><br><br>";
	ui->textBrowser->insertHtml(s1);
}
void Chat::refreshText()
{
	ui->textBrowser->moveCursor(QTextCursor::End);
}
void Chat::recvShowMsg(QString msg)
{
	PlaySound(TEXT("E:/msg.wav"), NULL, SND_FILENAME | SND_ASYNC);
	QScrollBar *bar = ui->textBrowser->verticalScrollBar();
	if (bar)
	{
		bar->setSliderPosition(bar->maximum());
	}
	if (msg.length()>=23)
	{
		QString s1 = QString(
			R"(<img width='30' height='30' src=':/media/person/media/person/4.jpg' style='float:left;margin-left:15px;margin-right:15px;'><div style='background:rgb(225,225,225);padding-top:8px;float:left;margin-top:4px;margin-right:45px;padding:10px;margin-left:60px;'><span style="color:black;font-size:16px;font-family:'Microsoft YaHei';margin-top:2px;">%2</span></div><br><br><br>)").arg(QString::number(pic)).arg(msg);
		qDebug() << s1;
		ui->textBrowser->insertHtml(s1);
	}
	else
	{
		int flag = 60 + (24 - msg.length()) * 15;
		QString myflag = QString::number(flag-5, 10);;
		qDebug() << myflag;
		QString tt =tr( ": / media / person / media / person / 4.jpg");
		QString s1 = "<img width='30' height='30' src=':/media/ person/ media/person/4.jpg' style='float:left;margin-left:15px;margin-right:15px;'><div style='background:rgb(225,225,225);padding-top:8px;float:left;margin-top:4px;margin-left:45px;padding:10px;margin-right:" + myflag + "px;'>";
		s1 += "<span style=\"color:black;font-size:16px;font-family:'Microsoft YaHei';margin-top:2px;\">" + msg + "</span></div><br><br><br>";
		ui->textBrowser->insertHtml(s1);
	}
	
}
void Chat::alert()
{
	QApplication::alert(this);
}
