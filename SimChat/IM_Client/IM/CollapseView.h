#pragma once

#include <QWidget>
#include "Msg_H.h"
#include <QVBoxLayout>
#include "GroupList.h"
#include "CollapseViewItem.h"

namespace Ui { class CollapseView; };

class CollapseView : public QWidget
{
	Q_OBJECT

public:
	CollapseView(QWidget *parent = Q_NULLPTR);
	~CollapseView();
	CollapseViewItem* collapseviewItem;
	vector<CollapseViewItem*> collapse_view_List;
	int collapseViewItemCount;
private:
	Ui::CollapseView *ui;
	QVBoxLayout *w_layout;
	GroupList getGroupList();
};
