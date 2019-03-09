#pragma once

#include <QWidget>
#include "ui_IM_Login.h"
#include "moveableframelesswindow.h"
#include "connecting.h"
#include "osapi/Socket.h"


class IM_Login : public MoveableFramelessWindow
{
	Q_OBJECT

public:
	explicit IM_Login(QWidget *parent = Q_NULLPTR);
	~IM_Login();
	bool eventFilter(QObject *object, QEvent *e);

private:
	Ui::IM_Login *ui;

	int UserAuthentication();

protected:
	QWidget* getDragnWidget() override;
private slots:
	/**
	* @brief µÇÂ¼°´Å¥µã»÷
	*/
	void process();
private:
	void startConnecting();
	void connected();
	void Connecting();
	connecting *con;
	
};
