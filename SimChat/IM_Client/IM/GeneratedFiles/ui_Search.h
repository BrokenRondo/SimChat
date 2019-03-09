/********************************************************************************
** Form generated from reading UI file 'Search.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_3;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(615, 400);
        widget = new QWidget(Search);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 615, 400));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"  border-radius:4px;\n"
"background:rgb(39,140,222);\n"
"}\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 70, 615, 80));
        widget_2->setStyleSheet(QLatin1String("background:rgb(235,242,249);\n"
"border-radius:0px;"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 261, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("background:white;\n"
"border: 1px solid rgb(60,163,247);\n"
"border-radius:2px;"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 20, 75, 31));
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("background:rgb(60,163,247);\n"
"color:white;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 5, 52, 23));
        label->setStyleSheet(QStringLiteral("border-image:url(':/searchlogo52_23.png');"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(555, 0, 30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"  color:white;\n"
"}\n"
"QLabel:hover{\n"
"  background:rgb(255,255,255,50%);\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(585, 0, 30, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"  \n"
"   color:white;\n"
"}\n"
"QLabel:hover{\n"
"  background-color:rgb(212, 64, 39);\n"
"  color:rgb(255, 255, 255);\n"
"  border-top-right-radius:4px;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 30, 54, 21));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setCursor(QCursor(Qt::PointingHandCursor));
        label_4->setStyleSheet(QLatin1String("color:white;\n"
"font-weight:bold;\n"
"font-size:16px;\n"
"\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(270, 20, 54, 41));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 30, 54, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        label_5->setFont(font3);
        label_5->setCursor(QCursor(Qt::PointingHandCursor));
        label_5->setStyleSheet(QStringLiteral("color:white;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 150, 615, 25));
        label_6->setStyleSheet(QLatin1String("background:rgb(233,237,238);\n"
"color:rgb(104,104,104);"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 175, 615, 234));
        widget_3->setStyleSheet(QStringLiteral("background:white;"));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 50, 50));
        label_7->setStyleSheet(QLatin1String("border-image:url(\":/touxiang01.jpg\");\n"
"border-radius:2px;"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 22, 211, 20));
        label_8->setFont(font);
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(80, 45, 55, 23));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"   color:white;\n"
"   background:rgb(143,192,231);\n"
"   border-radius:2px;\n"
"}\n"
"QPushButton:hover{\n"
"   background:rgb(89,169,236);\n"
"}"));
        comboBox = new QComboBox(widget_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 45, 69, 23));
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

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Form", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("Search", "   \350\257\267\350\276\223\345\205\245\345\205\263\351\224\256\344\277\241\346\201\257", nullptr));
        pushButton->setText(QApplication::translate("Search", "GO", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Search", "\344\270\200", nullptr));
        label_3->setText(QApplication::translate("Search", "X", nullptr));
        label_4->setText(QApplication::translate("Search", "\346\211\276\344\272\272", nullptr));
        label_5->setText(QApplication::translate("Search", "\346\211\276\347\276\244", nullptr));
        label_6->setText(QApplication::translate("Search", "  \346\220\234\347\264\242\347\273\223\346\236\234\344\270\272\357\274\232", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
