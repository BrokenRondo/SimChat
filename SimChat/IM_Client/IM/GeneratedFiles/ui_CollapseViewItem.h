/********************************************************************************
** Form generated from reading UI file 'CollapseViewItem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEVIEWITEM_H
#define UI_COLLAPSEVIEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollapseViewItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *item_main;
    QVBoxLayout *verticalLayout;
    QWidget *item_top;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *item_con;

    void setupUi(QWidget *CollapseViewItem)
    {
        if (CollapseViewItem->objectName().isEmpty())
            CollapseViewItem->setObjectName(QStringLiteral("CollapseViewItem"));
        CollapseViewItem->resize(148, 127);
        CollapseViewItem->setStyleSheet(QLatin1String("#item_top #label[slected=\"false\"]{\n"
"	 \n"
"}\n"
"\n"
"#item_top #label[slected=\"false\"]:hover{\n"
"	\n"
"	 \n"
"}\n"
"\n"
"#item_top #label[slected=\"true\"]{\n"
"	 \n"
"}\n"
"\n"
"#item_top:hover{\n"
"	\n"
"	background-color: rgba(255, 255, 255,80);\n"
"}\n"
"\n"
"#item_top #label{\n"
"	 \n"
"	\n"
"	background-image: url(:/sys/arrow_r.png);\n"
"	background-repeat:no;\n"
"	background-position:center;\n"
"}\n"
"\n"
"\n"
"#item_top QPushButton{\n"
"	 border:none;\n"
"	 text-align:left;\n"
"	 font-size:10pt;\n"
"	 background-repeat:no;\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(CollapseViewItem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        item_main = new QWidget(CollapseViewItem);
        item_main->setObjectName(QStringLiteral("item_main"));
        verticalLayout = new QVBoxLayout(item_main);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        item_top = new QWidget(item_main);
        item_top->setObjectName(QStringLiteral("item_top"));
        horizontalLayout = new QHBoxLayout(item_top);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 5, 0, 5);
        label = new QLabel(item_top);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(item_top);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(item_top);

        item_con = new QWidget(item_main);
        item_con->setObjectName(QStringLiteral("item_con"));

        verticalLayout->addWidget(item_con);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addWidget(item_main);


        retranslateUi(CollapseViewItem);

        QMetaObject::connectSlotsByName(CollapseViewItem);
    } // setupUi

    void retranslateUi(QWidget *CollapseViewItem)
    {
        CollapseViewItem->setWindowTitle(QApplication::translate("CollapseViewItem", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("CollapseViewItem", "\346\210\221\347\232\204\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollapseViewItem: public Ui_CollapseViewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEVIEWITEM_H
