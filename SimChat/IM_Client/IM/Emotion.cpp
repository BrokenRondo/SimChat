#include "Emotion.h"
#include "ui_Emotion.h"

Emotion::Emotion(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Emotion();
	ui->setupUi(this);
	setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint);
	ui->label->installEventFilter(this);
	ui->label_2->installEventFilter(this);
	ui->label_3->installEventFilter(this);
	//ui->label_15->installEventFilter(this);
	ui->label_4->installEventFilter(this);
	ui->label_5->installEventFilter(this);
	ui->label_6->installEventFilter(this);
	ui->label_7->installEventFilter(this);
}

Emotion::~Emotion()
{
	delete ui;
}
bool Emotion::eventFilter(QObject *object, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonPress&&object == ui->label)
	{
		emit imgurl(QString(":/emotion/emotion/emotion01.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_2) {
		emit imgurl(QString(":/emotion/emotion/emotion02.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_3) {
		emit imgurl(QString(":/emotion/emotion/emotion03.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_4) {
		emit imgurl(QString(":/emotion/emotion/emotion04.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_5) {
		emit imgurl(QString(":/emotion/emotion/emotion05.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_6) {
		emit imgurl(QString(":/emotion/emotion/emotion06.png"));
		hide();
	}
	else if (e->type() == QEvent::MouseButtonPress&&object == ui->label_7) {
		emit imgurl(QString(":/emotion/emotion/emotion07.png"));
		hide();
	}
	return false;
}

void Emotion::on_pushButton_clicked()
{
	qDebug("µã»÷ÁË") ;
}