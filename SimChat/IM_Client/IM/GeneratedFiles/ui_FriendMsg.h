/********************************************************************************
** Form generated from reading UI file 'FriendMsg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDMSG_H
#define UI_FRIENDMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendMsg
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_4;
    QPushButton *pushButton_agree;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *label_8;
    QLabel *label_5;

    void setupUi(QWidget *FriendMsg)
    {
        if (FriendMsg->objectName().isEmpty())
            FriendMsg->setObjectName(QStringLiteral("FriendMsg"));
        FriendMsg->resize(473, 225);
        FriendMsg->setStyleSheet(QLatin1String("#Friendmsg{\n"
"    background:#D6AA9F;\n"
"}"));
        label = new QLabel(FriendMsg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 71, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        label_2 = new QLabel(FriendMsg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(413, 0, 30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"   color:white;\n"
"}\n"
"QLabel:hover{\n"
"   background-color:rgb(58,149,222);\n"
"   color:white;\n"
"\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(FriendMsg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(443, 0, 30, 30));
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"   color:white;\n"
"}\n"
"QLabel:hover{\n"
"  background-color:rgb(212, 64, 39);\n"
"  color:rgb(255, 255, 255);\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        widget = new QWidget(FriendMsg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, 40, 481, 191));
        widget->setStyleSheet(QStringLiteral("background:#F8F0EE;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 30, 411, 91));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"  border:1px solid #D1CAC8;\n"
"  border-radius:2px;\n"
"}"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(23, 20, 50, 50));
        label_4->setStyleSheet(QLatin1String("#label_4{\n"
"   border-image:url(\":/10.jpeg\");\n"
"   border-radius:2px;\n"
"}"));
        pushButton_agree = new QPushButton(widget_2);
        pushButton_agree->setObjectName(QStringLiteral("pushButton_agree"));
        pushButton_agree->setGeometry(QRect(250, 35, 61, 25));
        pushButton_agree->setFont(font);
        pushButton_agree->setStyleSheet(QLatin1String("border-radius:2px;\n"
"border:1px solid #929291;\n"
"background:#FBFBFA;"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(325, 35, 61, 25));
        pushButton_2->setStyleSheet(QLatin1String("border-radius:2px;\n"
"border:1px solid #929291;\n"
"background:#FBFBFA;"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 25, 141, 16));
        label_6->setFont(font);
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 50, 131, 16));
        label_7->setFont(font);
        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(250, 65, 81, 22));
        comboBox->setMinimumSize(QSize(0, 1));
        comboBox->setMaximumSize(QSize(16777207, 16777215));
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"background-color:rgb(248, 248, 248);\n"
"border:1px solid #929291;\n"
"border-radius:2px;\n"
"height:10px;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
" \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"	image: url(:/sys/arrow_d.png);\n"
"}\n"
""));
        comboBox->setEditable(false);
        comboBox->setInsertPolicy(QComboBox::InsertAlphabetically);
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 70, 54, 12));
        label_8->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(FriendMsg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 16, 16));
        label_5->setStyleSheet(QStringLiteral("border-image:url(\":/friendmsg.png\");"));

        retranslateUi(FriendMsg);

        QMetaObject::connectSlotsByName(FriendMsg);
    } // setupUi

    void retranslateUi(QWidget *FriendMsg)
    {
        FriendMsg->setWindowTitle(QApplication::translate("FriendMsg", "Form", nullptr));
        label->setText(QApplication::translate("FriendMsg", "\351\252\214\350\257\201\346\266\210\346\201\257", nullptr));
        label_2->setText(QApplication::translate("FriendMsg", "\344\270\200", nullptr));
        label_3->setText(QApplication::translate("FriendMsg", "X", nullptr));
        label_4->setText(QString());
        pushButton_agree->setText(QApplication::translate("FriendMsg", "\345\220\214\346\204\217", nullptr));
        pushButton_2->setText(QApplication::translate("FriendMsg", "\346\213\222\347\273\235", nullptr));
        label_6->setText(QApplication::translate("FriendMsg", "\345\247\223\345\220\215\357\274\232\346\235\245\350\207\252\346\230\237\346\230\237\347\232\204\346\210\221", nullptr));
        label_7->setText(QApplication::translate("FriendMsg", "id\357\274\2322014190130", nullptr));
        label_8->setText(QApplication::translate("FriendMsg", "\346\267\273\345\212\240\345\210\260", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendMsg: public Ui_FriendMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDMSG_H
