#pragma once

#include <QDialog>
namespace Ui { class RegisterDia; };

class RegisterDia : public QDialog
{
	Q_OBJECT

public:
	RegisterDia(QWidget *parent = Q_NULLPTR);
	~RegisterDia();

private:
	
	Ui::RegisterDia *ui;

private slots:
	void PB_sure_clicked();
	void PB_cancle_clicked();
	
};
