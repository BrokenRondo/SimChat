#include "moveableframelesswindow.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>

MoveableFramelessWindow::MoveableFramelessWindow(QWidget *parent)
	: QWidget(parent),isMove(false)
{
	//���ô���Ϊ�ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	//���õײ㱳��͸��
	setAttribute(Qt::WA_TranslucentBackground);
}

MoveableFramelessWindow::~MoveableFramelessWindow()
{
}
/**
* @brief ��갴�£�׼���϶�����
* @param event
*/
void MoveableFramelessWindow::mousePressEvent(QMouseEvent *event)
{
	//�ж���갴�µ�λ���Ƿ��ڴ����ڲ�
	bool shouldMove = isPointInDragnWidget(getDragnWidget(), event->pos());

	if (shouldMove) {
		pressedPoint = event->pos();
		isMove = true;
	}

	event->ignore();

}

/**
* @brief ����ƶ����������϶�
* @param event
*/
//event->x()�������������ڽ����¼��Ĵ���С������xλ��
void MoveableFramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() == Qt::LeftButton) && isMove == true) {

		QPoint currPoint = this->pos(); //�����Ӵ�������ڸ����ڵ�λ�ã�����Ƕ��㴰�ڣ��򷵻�����������λ��
		currPoint.setX(currPoint.x() + event->x() - pressedPoint.x());
		currPoint.setY(currPoint.y() + event->y() - pressedPoint.y());
		this->move(currPoint); //�����ƶ�����������
	}
}

void MoveableFramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
	isMove = false;

}

/**
* @brief �ж��������λ���Ƿ������϶�����
* @param widget ���϶��ؼ�λ��
* @param point  �����λ��
* @return
*/
bool MoveableFramelessWindow::isPointInDragnWidget(const QWidget *widget, const QPoint &point)
{
	//�ж�λ��
	QRect rect = widget->rect();

	bool isIn = point.x() >= rect.left() && point.x() <= rect.right() && point.y() >= rect.top() && point.y() <= rect.bottom();

	return isIn;
}
