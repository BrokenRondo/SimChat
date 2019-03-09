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
	* @brief 设置标题文字
	* @param titleText
	*/
	void setTitleText(QString titleText);

	/**
	 * @brief 添加展开抽屉后的内容项目
	 * @param widgets 项目列表
	 */
	void addSubItems(QList<QWidget *> widgets);

	/**
	 * @brief 添加展开抽屉后的内容项目
	 * @param widgets 项目
	 */
	void addSubItem(QWidget*widget);

private slots:
	//折叠项目
	void onCollapseButClick();
private:
	Ui::CollapseViewItem *ui;
	QVBoxLayout *item_con_layout;
	

};
