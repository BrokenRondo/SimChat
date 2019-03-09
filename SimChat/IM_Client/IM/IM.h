#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IM.h"

class IM : public QMainWindow
{
	Q_OBJECT

public:
	IM(QWidget *parent = Q_NULLPTR);

private:
	Ui::IMClass ui;
};
