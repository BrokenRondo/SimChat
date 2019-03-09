/********************************************************************************
** Form generated from reading UI file 'IM.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IM_H
#define UI_IM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IMClass)
    {
        if (IMClass->objectName().isEmpty())
            IMClass->setObjectName(QStringLiteral("IMClass"));
        IMClass->resize(600, 400);
        menuBar = new QMenuBar(IMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        IMClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IMClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IMClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(IMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IMClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IMClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IMClass->setStatusBar(statusBar);

        retranslateUi(IMClass);

        QMetaObject::connectSlotsByName(IMClass);
    } // setupUi

    void retranslateUi(QMainWindow *IMClass)
    {
        IMClass->setWindowTitle(QApplication::translate("IMClass", "IM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IMClass: public Ui_IMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IM_H
