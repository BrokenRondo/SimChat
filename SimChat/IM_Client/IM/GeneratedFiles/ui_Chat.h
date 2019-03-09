/********************************************************************************
** Form generated from reading UI file 'Chat.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QFrame *line_2;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(629, 587);
        Chat->setStyleSheet(QLatin1String("#widget{\n"
"  border-radius:3px;\n"
"  background:#E8F5FB;\n"
"}"));
        widget = new QWidget(Chat);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 629, 589));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"  border-radius:3px;\n"
"  background:#E7EAF7;\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(8, 9, 50, 50));
        label->setStyleSheet(QLatin1String("border-image:url(\":/11.jpg\");\n"
"border-radius:2px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 101, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_2->setFont(font);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 30, 381, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_3->setFont(font1);
        label_3->setWordWrap(true);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(569, 0, 30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setStyleSheet(QLatin1String("QLabel{\n"
"   color:rgb(134, 134, 134);\n"
"}\n"
"QLabel:hover{\n"
"   background-color:rgb(58,149,222);\n"
"   color:white;\n"
"\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(599, 0, 30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(true);
        font3.setWeight(75);
        label_5->setFont(font3);
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"   color:rgb(134, 134, 134);;\n"
"}\n"
"QLabel:hover{\n"
"  background-color:rgb(212, 64, 39);\n"
"  color:rgb(255, 255, 255);\n"
"  border-top-right-radius:3px;\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 65, 629, 3));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(6);
        line->setFont(font4);
        line->setStyleSheet(QLatin1String("height:2px;\n"
""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 66, 141, 521));
        label_6->setStyleSheet(QLatin1String("border-image:url(\":/personman.png\");\n"
""));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/sys/personman.png")));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 440, 26, 26));
        label_7->setStyleSheet(QLatin1String("QLabel{\n"
"background-image:url(\":/A26.png\");\n"
"}\n"
"QLabel:hover{\n"
"  border:1px solid rgb(203, 203, 203);\n"
"}"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/sys/A26.png")));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(36, 439, 26, 26));
        label_8->setStyleSheet(QLatin1String("QLabel{\n"
"background-image:url(\":/emotion26.png\");\n"
"}\n"
"QLabel:hover{\n"
" border:1px solid rgb(203, 203, 203);\n"
"}"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/sys/emotion26.png")));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 466, 481, 91));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(10);
        textEdit->setFont(font5);
        textEdit->setStyleSheet(QLatin1String("border:none;\n"
"background:#E7EAF7;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 560, 61, 24));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("QPushButton{ \n"
"     background-color: rgb(6,157,213); \n"
"     border: none;\n"
"     border-radius:2px;\n"
"     color:white;\n"
"}\n"
"QPushButton:hover{ \n"
"     background-color: rgb(75,202,255);\n"
"}"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 560, 61, 24));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{ \n"
"     background-color: rgb(6,157,213); \n"
"     border: none;\n"
"     border-radius:2px;\n"
"     color:white;\n"
"}\n"
"QPushButton:hover{ \n"
"     background-color: rgb(75,202,255);\n"
"}"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 66, 481, 371));
        textBrowser->setStyleSheet(QLatin1String("border:none;\n"
" background:#E7EAF7;"));
        line_2 = new QFrame(widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 420, 491, 41));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Chat", "\351\271\277\344\270\270", nullptr));
        label_3->setText(QApplication::translate("Chat", "\346\210\221\346\230\257\350\246\201\346\210\220\344\270\272\346\265\267\350\264\274\347\216\213\347\232\204\344\272\272", nullptr));
        label_4->setText(QApplication::translate("Chat", "\344\270\200", nullptr));
        label_5->setText(QApplication::translate("Chat", "X", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        pushButton->setText(QApplication::translate("Chat", "\345\205\263\351\227\255", nullptr));
        pushButton_2->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
