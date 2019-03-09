/********************************************************************************
** Form generated from reading UI file 'msgboxWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBOXWIDGET_H
#define UI_MSGBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_msgboxWidget
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QWidget *msgboxWidget)
    {
        if (msgboxWidget->objectName().isEmpty())
            msgboxWidget->setObjectName(QStringLiteral("msgboxWidget"));
        msgboxWidget->resize(449, 62);
        msgboxWidget->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(msgboxWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 42, 42));
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"  border-image:url(\":/10.jpeg\");\n"
"  border-radius:2px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(msgboxWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(65, 8, 141, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_3->setFont(font);
        label_4 = new QLabel(msgboxWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(65, 33, 211, 17));
        label_4->setFont(font);
        label = new QLabel(msgboxWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 20, 18, 18));
        label->setStyleSheet(QLatin1String("background-color:rgb(255, 0, 0);\n"
"color:white;\n"
"border-radius:9px"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(msgboxWidget);

        QMetaObject::connectSlotsByName(msgboxWidget);
    } // setupUi

    void retranslateUi(QWidget *msgboxWidget)
    {
        msgboxWidget->setWindowTitle(QApplication::translate("msgboxWidget", "Form", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("msgboxWidget", "\346\274\251\346\266\241\351\270\243\344\272\272", nullptr));
        label_4->setText(QApplication::translate("msgboxWidget", "\345\244\247\345\256\266\345\245\275\357\274\214\346\210\221\346\230\257\346\274\251\346\266\241\351\270\243\344\272\272", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class msgboxWidget: public Ui_msgboxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOXWIDGET_H
