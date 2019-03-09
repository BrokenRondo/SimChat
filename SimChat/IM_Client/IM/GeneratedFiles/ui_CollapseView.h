/********************************************************************************
** Form generated from reading UI file 'CollapseView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEVIEW_H
#define UI_COLLAPSEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollapseView
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *CollapseView)
    {
        if (CollapseView->objectName().isEmpty())
            CollapseView->setObjectName(QStringLiteral("CollapseView"));
        CollapseView->resize(192, 285);
        CollapseView->setStyleSheet(QLatin1String("#scrollArea{\n"
"	border:none;\n"
"}\n"
"\n"
"#scrollAreaWidgetContents{\n"
"	\n"
"}"));
        verticalLayout = new QVBoxLayout(CollapseView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CollapseView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 192, 285));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(CollapseView);

        QMetaObject::connectSlotsByName(CollapseView);
    } // setupUi

    void retranslateUi(QWidget *CollapseView)
    {
        CollapseView->setWindowTitle(QApplication::translate("CollapseView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollapseView: public Ui_CollapseView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEVIEW_H
