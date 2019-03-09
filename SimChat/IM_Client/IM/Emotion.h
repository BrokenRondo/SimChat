#pragma once

#include <QWidget>
namespace Ui { class Emotion; };

class Emotion : public QWidget
{
	Q_OBJECT

public:
	explicit Emotion(QWidget *parent = Q_NULLPTR);
	~Emotion();
	bool eventFilter(QObject *object, QEvent *e);
signals:
	void imgurl(QString imgurl);
private slots:
	void on_pushButton_clicked();
private:
	Ui::Emotion *ui;
};
