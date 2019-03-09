#include "connecting.h"
#include "ui_connecting.h"
#include <QMovie>
extern bool Connecting;
connecting::connecting(QWidget *parent)
	: MoveableFramelessWindow(parent)
{
	ui = new Ui::connecting();
	ui->setupUi(this);
	QMovie *movie = new QMovie(":/sys/img/blue70-2.gif");
	ui->label->setMovie(movie);
	movie->start();
}

connecting::~connecting()
{
	delete ui;
}

QWidget * connecting::getDragnWidget()
{
	return NULL;
}
