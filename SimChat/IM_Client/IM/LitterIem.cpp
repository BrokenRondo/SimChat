#include "LitterIem.h"
#include "ui_LitterIem.h"
#include <QImage>
#include <QDesktopWidget>
#include <vector>



LitterIem::LitterIem(QString picPath,int state,QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LitterIem();
	ui->setupUi(this);
	isOpen = false;
	chat = nullptr;
	if (state == 1)//如果在线
	{
		QPixmap p(picPath);
		ui->label_pic->setPixmap(p);
	}
	if (state==0)
	{
		QImage img;
		img.load(picPath);

		QImage image2 = img.convertToFormat(QImage::Format_Indexed8);
		image2.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image2.setColor(i, qRgb(i, i, i));
		}
		ui->label_pic->setPixmap((QPixmap::fromImage(image2)));

	}
}
LitterIem::LitterIem(QString picPath, int state, SingleItem singleItem, QWidget* parent)
{
	ui = new Ui::LitterIem();
	ui->setupUi(this);
	isOpen = false;
	if (state == 1)//如果在线
	{
		QPixmap p(picPath);
		ui->label_pic->setPixmap(p);
	}
	if (state == 0)
	{
		QImage img;
		img.load(picPath);

		QImage image2 = img.convertToFormat(QImage::Format_Indexed8);
		image2.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image2.setColor(i, qRgb(i, i, i));
		}
		ui->label_pic->setPixmap((QPixmap::fromImage(image2)));

	}
	setJkNum(singleItem.jkNum);
	setNickName(singleItem.nickName);
	setState(singleItem.bodyState);
	setPic(singleItem.bodyPic);
	setpicPath(picPath);
	ui->label_name->setText(QString::fromStdString(singleItem.nickName));
	isOpen = false;
	m_mbox = false;
	notice = false;
	isInited = false;
	
}
LitterIem::LitterIem(int pic, int state, std::string listname,int jkNum, std::string itemName,QWidget *parent)
{
	ui = new Ui::LitterIem();
	ui->setupUi(this);
	isOpen = false;
	QString picPath = QString(":/media/person/media/person/%1.jpg")
		.arg(QString::number(pic));
	if (state == 1)//如果在线
	{
		QPixmap p(picPath);
		ui->label_pic->setPixmap(p);
	}
	if (state == 0)
	{
		QImage img;
		img.load(picPath);

		QImage image2 = img.convertToFormat(QImage::Format_Indexed8);
		image2.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image2.setColor(i, qRgb(i, i, i));
		}
		ui->label_pic->setPixmap((QPixmap::fromImage(image2)));

	}
	setJkNum(jkNum);
	setNickName(listname);
	setState(state);
	setPic(pic);
	setpicPath(picPath);
	ui->label_name->setText(QString::fromStdString(itemName));
	isOpen = false;
	m_mbox = false;
	notice = false;
	isInited = false;
}

LitterIem::~LitterIem()
{
	delete ui;
}
int LitterIem::getJkNum()
{
	return jkNum;
}
void LitterIem::setJkNum(int jknum)
{
	this->jkNum = jknum;
}
char LitterIem::getState()
{
	return state;
}
void LitterIem::setState(char state)
{
	this->state = state;
}
std::string LitterIem::getNickName()
{
	return nickName;
}
void LitterIem::setNickName(std::string nickName)
{
	this->nickName = nickName;
}
int LitterIem::getPic()
{
	return pic;
}
void LitterIem::setPic(int pic)
{
	this->pic = pic;
}
void LitterIem::setpicPath(QString picPath)
{
	this->picPath = picPath;
}

void LitterIem::acceptClose()
{
	isOpen = false;
	isInited = false;
}
bool LitterIem::openOrNot()
{
	return isOpen;
}
void LitterIem::init()
{
	chat = new Chat(jkNum, state, pic, nickName);
	connect(chat, SIGNAL(sendClose()), this, SLOT(acceptClose()));
	isInited = true;
}
void LitterIem::showMsgBox(QString msg)
{
	m_msgBox = new MyMessageBox(pic,state,jkNum,nickName,msg);
	m_msgBox->show();
	m_mbox = true;
	connect(m_msgBox, SIGNAL(m_mboxclose()), this, SLOT(msgboxclicked()));
}

void LitterIem::setNotice()
{
	QPixmap p (":/sys/reddot.png");
	ui->label->setPixmap(p);
	notice = true;//设置有通知(窗口没打开才设置)
}
void LitterIem::clearNotice()
{
	ui->label->clear();
	notice = false;
}

void LitterIem::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (!isOpen&&!isInited)
	{
		chat = new Chat(jkNum, state, pic, nickName);
		connect(chat, SIGNAL(sendClose()), this, SLOT(acceptClose()));
		chat->showNormal();
		isOpen = true;
		isInited = true;
		if (m_mbox)
		{
			m_msgBox->close();
			m_mbox = false;
		}
		if (notice)
		{
			clearNotice();
		}
		
	}
	else if (isInited&&isOpen)
	{
		isOpen = true;
		clearNotice();
		chat->showNormal();
		m_mbox = false;
	}
	else if(isInited&&!isOpen)
	{
		chat->showNormal();
		if (notice) {
			clearNotice();
			notice = false;
		}
		m_msgBox->close();
		m_mbox = false;
		isOpen = true;
	}

	
}
bool LitterIem::hasMsgBox()
{
	return m_mbox;
}
void LitterIem::msgboxclicked()
{
	m_mbox = false;
	isOpen = true;
	clearNotice();
}
void LitterIem::clearm_mbox()
{
	m_mbox = false;
}
void LitterIem::refreshPic(bool online)
{
	if (online)//如果是好友上线
	{
		PlaySound(TEXT("E:/Global.wav"), NULL, SND_FILENAME | SND_ASYNC);
		QPixmap p(picPath);
		ui->label_pic->setPixmap(p);
	}
	else//如果下线
	{
		QImage img;
		img.load(picPath);
		QImage image2 = img.convertToFormat(QImage::Format_Indexed8);
		image2.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image2.setColor(i, qRgb(i, i, i));
		}
		ui->label_pic->setPixmap((QPixmap::fromImage(image2)));
	}
}
