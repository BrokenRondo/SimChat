#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include "SingleList.h"
#define MAX_PERSON_PIC_NUM 8
namespace Ui { class CollapseViewItem; };

class CollapseViewItem : public QWidget
{
	Q_OBJECT

public:
	CollapseViewItem(QString titleText,QWidget *parent = Q_NULLPTR);
	CollapseViewItem( SingleList single_list,QWidget *parent = Q_NULLPTR);
	~CollapseViewItem();
	/**
	* @brief ���ñ�������
	* @param titleText
	*/
	void setTitleText(QString titleText);

	/**
	 * @brief ���չ��������������Ŀ
	 * @param widgets ��Ŀ�б�
	 */
	void addSubItems(QList<QWidget *> widgets);

	/**
	 * @brief ���չ��������������Ŀ
	 * @param widgets ��Ŀ
	 */
	void addSubItem(QWidget*widget);

private slots:
	//�۵���Ŀ
	void onCollapseButClick();
private:
	Ui::CollapseViewItem *ui;
	QVBoxLayout *item_con_layout;
	

};
