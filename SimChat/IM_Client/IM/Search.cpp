#include "Search.h"
#include "ui_Search.h"
#include <QDebug>
#include "tools/PackageTool.h"
#include <QMessageBox>
#include "MsgText.h"
#include <Queue>
#include "GroupList.h"
#include <mutex>

#define serverJK 111112222
extern int myJKNum;
extern queue<MsgText*> MsgQueue;
extern GroupList groupList;
Search *searchWidget;
Search::Search(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Search();
	ui->setupUi(this);
	connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_2_ckecked()));
}

Search::~Search()
{
	delete ui;
}
void Search::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		this->setMouseTracking(true);
		mouse_press = true;
		//�������ڴ����λ�ã�����ʹ��event->globalPos() - this->pos()��
		move_point = event->pos();
		qDebug() << "�ƶ�1";
		qDebug() << event->source();
	}

}

void Search::mouseReleaseEvent(QMouseEvent *event)
{
	//�������Ϊδ������
	mouse_press = false;

}

void Search::mouseMoveEvent(QMouseEvent *event)
{
	//��������������
  //  qDebug()<<"mouse_press="<<event->globalPos();
	if (mouse_press)
	{

		//����������Ļ��λ��
		QPoint move_pos = event->globalPos();
		//�ƶ�������λ��
		this->move(move_pos - move_point);
	}
}

bool Search::eventFilter(QObject *object, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress&&object == ui->label_3)
	{
		this->hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_2) {
		showMinimized();
		qDebug() << "��С��";
		qDebug() << mouse_press;

	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_4) {

		ui->label_4->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
		ui->label_5->setStyleSheet("color:white");
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_5) {

		ui->label_5->setStyleSheet("color:white;font-size:16px;font-weight:bold;");
		ui->label_4->setStyleSheet("color:white");
	}

	return false;
}

void Search::showEvent(QShowEvent *event)
{
	qDebug() << "������";
	mouse_press = false;
	qDebug() << mouse_press;
}
void Search::on_pushButton_clicked()
{
	//��Ҫ�����ĺ���������������
	QString number_string = ui->lineEdit->text();
	if (number_string.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������Ҫ���ҵĺ���"));
	}
	int number = number_string.toInt();
	jkNum = number;
	PackageTools *ptools = new PackageTools();
	MsgSearch* m_search = new MsgSearch(number);
	m_search->setType(0x33);
	m_search->setDest(serverJK);
	m_search->setSrc(myJKNum);
	m_search->setTotalLen(17);
	m_search->jkNum = number;
	char buf[18] = { 0 };
	ptools->packMsgSearch(buf, m_search);
	MsgText *mtext = new MsgText(buf, 17);
	MsgQueue.push(mtext);
	ui->pushButton->setText(QString::fromLocal8Bit("������..."));
}
void Search::showResult(int pic, std::string name,char result)
{
	if (result==0x00)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("�޽��"));
		ui->pushButton->setText("Go");
		return;
	}
	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg(QString::number(pic));
	QPixmap p(picPath);
	ui->label_7->setPixmap(p);
	ui->label_8->setText(QString::fromStdString(name));
	for (int i = 0; i < groupList.groupList.size(); i++)
	{
		ui->comboBox->addItem(QString::fromStdString(groupList.groupList[i].listName.data()));
	}
	ui->pushButton->setText("Go");
	ui->pushButton_2->setText(QString::fromLocal8Bit("�Ӻ���"));
}
void Search::on_pushButton_2_ckecked()
{
	MsgAddFriend* madd = new MsgAddFriend();
	madd->setTotalLen(31);
	madd->setType(0x24);
	madd->setDest(jkNum);
	madd->setSrc(myJKNum);
	madd->setAdd_id(myJKNum);
	madd->setPic(7);
	int listloc = ui->comboBox->currentIndex();
	madd->setlist_name(groupList.groupList[listloc].listName);
	PackageTools* ptools = new PackageTools();
	char *buf = new char [18];
	ptools->packMsgAddFriend(buf, madd);
	MsgText *msgtext = new MsgText(buf, 31);
	mtx.Lock();

	MsgQueue.push(msgtext);
	mtx.Unlock();

	//delete msgtext;
	delete madd;
	delete ptools;
	QApplication::setQuitOnLastWindowClosed(false);
	QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
		QString::fromLocal8Bit("�ѷ�������"));
	this->hide();
}
