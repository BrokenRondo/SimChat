#pragma once

#include <QWidget>
#include <QThread>
#include "moveableframelesswindow.h"

namespace Ui { class connecting; };

class connecting : public MoveableFramelessWindow
{
	Q_OBJECT

public:
	explicit connecting(QWidget *parent = Q_NULLPTR);
	~connecting();

protected:
	QWidget* getDragnWidget() override;
private:
	Ui::connecting *ui;
	volatile bool stopped;
};
