#include "CollapseViewItem.h"
#include "ui_CollapseViewItem.h"
#include "osapi/Socket.h"
#include <QTime>
#include <QDebug>
#include "LitterIem.h"

std::vector<LitterIem*> litterIems;//����������ѵ�LitterIem
extern OS_TcpSocket client_socket;
CollapseViewItem::CollapseViewItem(QString titleText,QWidget *parent)//��������ʼ��ʹ��������캯��
	: QWidget(parent)
{
	ui = new Ui::CollapseViewItem();
	ui->setupUi(this);
	//��litteriem����widget��Ӳ���
	item_con_layout = new QVBoxLayout(this);
	item_con_layout->setContentsMargins(0, 0, 0, 0);//�����ı߱߾���0
	item_con_layout->setSpacing(0);
	ui->item_con->setLayout(item_con_layout);
	ui->label->setProperty("selected", ui->item_con->isVisible());
	//����ʱ�������������
	QTime time;
	time = QTime::currentTime();
	qsrand(time.msec() + time.second() * 1000);

	//�������������Ŀ
	int personNumber = qrand() % (MAX_PERSON_PIC_NUM)+1;
	qDebug() << "personNumber:" << personNumber;

	for (int i = 0; i < personNumber; ++i)
	{
		//���ѡ�����ͷ��
		QString picPath = QString(":/media/person/media/person/%1.jpg")
			.arg(QString::number(qrand() % (MAX_PERSON_PIC_NUM)+1));
		addSubItem(new LitterIem(picPath, 1,this));
	}

	//�������δ���ߺ�����Ŀ
	int offlinPerson = qrand() % personNumber;

	titleText = QString("%1 (%2/%3)")
		.arg(titleText).arg(QString::number(offlinPerson)).arg(QString::number(personNumber));

	this->setTitleText(titleText);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onCollapseButClick()));

}
CollapseViewItem::CollapseViewItem(SingleList single_list, QWidget *parent)//�����ȡ��GroupListʹ��������캯��
	: QWidget(parent)
{
	ui = new Ui::CollapseViewItem();
	ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onCollapseButClick()));
	//��litteriem����widget��Ӳ���
	item_con_layout = new QVBoxLayout(this);
	item_con_layout->setContentsMargins(0, 0, 0, 0);//�����ı߱߾���0
	item_con_layout->setSpacing(0);
	ui->item_con->setLayout(item_con_layout);
	ui->label->setProperty("selected", ui->item_con->isVisible());
	//����ͷ��
	for (int i = 0; i < single_list.bodyCount; i++)
	{
		if (single_list.items[i].bodyState==1)
		{
			QString picPath = QString(":/media/person/media/person/%1.jpg")
				.arg(QString::fromStdString(std::to_string(single_list.items[i].bodyPic)));
			LitterIem* litter = new LitterIem(picPath, 1, single_list.items[i], this);
			addSubItem(litter);
			litterIems.push_back(litter);
		}
		else
		{
			QString picPath = QString(":/media/person/media/person/%1.jpg")
				.arg(QString::fromStdString(std::to_string(single_list.items[i].bodyPic)));
			LitterIem* litter = new LitterIem(picPath, 0, single_list.items[i], this);
			addSubItem(litter);
			litterIems.push_back(litter);
		}

		
	}
	QString titleText = QString("%1 (%2/ %3)")
		.arg(QString::fromStdString(single_list.listName))
		.arg(QString::number(single_list.online))
			.arg(QString::number(single_list.bodyCount));
	this->setTitleText(titleText);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onCollapseButClick()));

}

CollapseViewItem::~CollapseViewItem()
{
	delete ui;
}
void CollapseViewItem::setTitleText(QString titleText)
{
	ui->pushButton->setText(titleText);
}

void CollapseViewItem::addSubItems(QList<QWidget *> widgets)
{
	foreach(QWidget *var, widgets) {
		addSubItem(var);
	}
}

void CollapseViewItem::addSubItem(QWidget *widget)
{
	item_con_layout->addWidget(widget);
}

void CollapseViewItem::onCollapseButClick()
{
	//����Ϊ�෴����ʾ״̬,չ�������۵�
	ui->item_con->setVisible(!ui->item_con->isVisible());

	ui->label->setProperty("slected", ui->item_con->isVisible());

	ui->label->update();

}