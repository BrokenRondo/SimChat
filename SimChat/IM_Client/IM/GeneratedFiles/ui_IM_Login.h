/********************************************************************************
** Form generated from reading UI file 'IM_Login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IM_LOGIN_H
#define UI_IM_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IM_Login
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *login_main_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *login_top_widget;
    QLabel *label;
    QLabel *label_minimize;
    QLabel *label_shutdown;
    QWidget *login_con_widget;
    QLabel *label_touxiang;
    QLineEdit *lineEdit_un;
    QLineEdit *lineEdit_pass;
    QLabel *label_1;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_login;

    void setupUi(QWidget *IM_Login)
    {
        if (IM_Login->objectName().isEmpty())
            IM_Login->setObjectName(QStringLiteral("IM_Login"));
        IM_Login->resize(445, 344);
        QIcon icon;
        icon.addFile(QStringLiteral(":/sys/qlogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        IM_Login->setWindowIcon(icon);
        IM_Login->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"#LoginForm{\n"
"	\n"
"	\n"
"}\n"
"\n"
"#login_main_widget{\n"
"	\n"
"	background-color: rgb(255, 170, 127,0);\n"
"	border-image: url(:/sys/back.png) 5;\n"
"}\n"
"\n"
"#login_top_widget{\n"
"	background-color: #09A3DC;\n"
"	border-top-left-radius:4px;\n"
"	border-top-right-radius:4px;\n"
"}\n"
"\n"
"\n"
"#login_top_widget QLabel{\n"
"	border-top-left-radius:4px;\n"
"	border-top-right-radius:4px;\n"
"}\n"
"\n"
"\n"
"/*\347\231\273\345\275\225\344\277\241\346\201\257\345\241\253\345\206\231\351\203\250\345\210\206\346\200\273\345\256\271\345\231\250*/\n"
"#login_con_widget{\n"
"	 \n"
"	background-color: #EBF2F9;	\n"
"	border-bottom-left-radius:4px;\n"
"	border-bottom-right-radius:4px;\n"
"}\n"
"\n"
"/*\350\276\223\345\205\245\346\241\206\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"#login_con_widget QLineEdit{\n"
"	\n"
"	border:1px solid rgb(209,209,209);\n"
"	height:28px;   /*\345\255\220\346\216\247\344\273\266\351"
                        "\253\230\345\272\246*/\n"
"	font-size:10pt;\n"
"	padding-left:6px;\n"
"	padding-right:6px;\n"
"	\n"
"}\n"
"\n"
"/*\350\276\223\345\205\245\346\241\206\346\202\254\345\201\234\346\240\267\345\274\217*/\n"
"#login_con_widget QLineEdit:hover{\n"
"	\n"
"	border:1px solid rgb(21,131,221) /*\351\274\240\346\240\207\346\202\254\345\201\234\345\234\250\350\276\223\345\205\245\346\241\206\344\270\212\346\227\266\350\276\271\346\241\206\345\217\230\350\223\235*/\n"
"	\n"
"}\n"
"\n"
"/*\347\224\250\346\210\267\345\220\215\350\276\223\345\205\245\346\241\206\346\240\267\345\274\217*/\n"
"#login_con_widget QLineEdit#lineEdit_un{\n"
"	border-top-left-radius:4px;\n"
"	border-top-right-radius:4px;\n"
"	\n"
"}\n"
"\n"
"/*\345\257\206\347\240\201\350\276\223\345\205\245\346\241\206\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"#login_con_widget QLineEdit#lineEdit_pass{\n"
"	border-top-width:0px;\n"
"	border-bottom-left-radius:4px;\n"
"	border-bottom-right-radius:4px;\n"
"	background-image: url(:/sys/img/keyborad.png);\n"
""
                        "	background-repeat:no;\n"
"	background-position:right center;\n"
"	background-origin: content;\n"
"   \n"
"}\n"
"\n"
"/*\345\257\206\347\240\201\350\276\223\345\205\245\346\241\206\345\234\250\346\202\254\345\201\234\346\227\266\346\230\276\347\244\272*/\n"
"#login_con_widget QLineEdit#lineEdit_pass:hover{\n"
"	border-top-width:1px;\n"
"}\n"
"\n"
"\n"
"/*\346\240\207\347\255\276\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"#login_con_widget QLabel{\n"
"\n"
"	color: #09A3DC;\n"
"}\n"
"\n"
"/*\346\240\207\347\255\276\346\202\254\345\201\234*/\n"
"#login_con_widget QLabel:hover{\n"
"	color: rgba(9, 163, 220 ,120); /* \351\274\240\346\240\207\346\202\254\345\201\234\345\234\250\346\240\207\347\255\276\344\270\212\346\227\266\346\240\207\347\255\276\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262\345\217\230\344\270\272\345\215\212\351\200\217\346\230\216\347\232\204\350\223\235\350\211\262*/\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\207\345\255\227\345\237\272\346\234\254\346"
                        "\240\267\345\274\217*/\n"
"#login_con_widget QCheckBox{\n"
"	color:rgb(145, 145, 145);\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\345\237\272\346\234\254\346\240\267\345\274\217*/\n"
"#login_con_widget QCheckBox::indicator {\n"
"	border:1px solid #B2B2B2;\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\351\200\211\344\270\255\346\240\267\345\274\217*/\n"
"#login_con_widget QCheckBox::indicator:checked {\n"
"	border:1px solid #278CDE;\n"
"	background-image: url(:/sys/img/check.png);  /*\351\200\211\344\270\255\346\227\266\345\244\215\351\200\211\346\241\206\345\241\253\345\205\205\350\223\235\350\211\262\345\257\271\345\213\276*/\n"
"}\n"
"\n"
"/*\345\244\215\351\200\211\346\241\206\346\226\271\346\241\206\351\203\250\345\210\206\346\202\254\345\201\234*/\n"
"#login_con_widget QCheckBox::indicator:hover {\n"
"	 border:1px solid #278CDE;      /*\346\202\254\345\201\234\346\227\266\345\244\215\351\200\211"
                        "\346\241\206\347\232\204\350\276\271\346\241\206\345\217\230\350\223\235*/\n"
"}\n"
"\n"
"\n"
"/*\345\256\232\344\271\211\345\244\264\345\203\217\346\240\267\345\274\217*/\n"
"#label_touxiang{\n"
"	border-radius:4px;	\n"
"	border-image: url(:/media/person/media/person/8.jpg) 1; /*\345\244\264\345\203\217\345\233\276\347\211\207*/\n"
"	\n"
"}\n"
"\n"
"/*\347\231\273\345\275\225\346\214\211\351\222\256\346\240\267\345\274\217*/\n"
"#pushButton_login{\n"
"	border-radius:4px;\n"
"	border:none;\n"
"	background-color: #09A3DC;\n"
"	color:#fff;\n"
"}\n"
"\n"
"/*\347\231\273\345\275\225\346\214\211\351\222\256\351\274\240\346\240\207\346\202\254\345\201\234\346\240\267\345\274\217*/\n"
"#pushButton_login:hover{\n"
"	background-color:rgb(60,195,245); /*\346\202\254\345\201\234\346\227\266\345\217\230\344\270\272\345\215\212\351\200\217\346\230\216*/\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(IM_Login);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        login_main_widget = new QWidget(IM_Login);
        login_main_widget->setObjectName(QStringLiteral("login_main_widget"));
        login_main_widget->setMinimumSize(QSize(433, 332));
        login_main_widget->setMaximumSize(QSize(433, 332));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 170, 127, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        login_main_widget->setPalette(palette);
        verticalLayout_2 = new QVBoxLayout(login_main_widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        login_top_widget = new QWidget(login_main_widget);
        login_top_widget->setObjectName(QStringLiteral("login_top_widget"));
        login_top_widget->setStyleSheet(QString::fromUtf8("/*\347\274\251\345\260\217\345\217\212\345\205\263\351\227\255\346\214\211\351\222\256*/\n"
"#login_top_widget QLabel{\n"
"	border:none;\n"
"	width:20px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#login_top_widget QLabel:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}\n"
"\n"
"#login_top_widget QLabel#label_minimize{\n"
"	background-image: url(:/sys/mainform_minimize.png);\n"
"}\n"
"\n"
"#login_top_widget QLabel#label_shutdown{\n"
"	background-image: url(:/sys/mainform_shutdown.png);\n"
"}"));
        label = new QLabel(login_top_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 427, 176));
        label->setPixmap(QPixmap(QString::fromUtf8(":/sys/img/blue70-2.gif")));
        label->setScaledContents(true);
        label_minimize = new QLabel(login_top_widget);
        label_minimize->setObjectName(QStringLiteral("label_minimize"));
        label_minimize->setGeometry(QRect(370, 10, 20, 20));
        label_shutdown = new QLabel(login_top_widget);
        label_shutdown->setObjectName(QStringLiteral("label_shutdown"));
        label_shutdown->setGeometry(QRect(400, 10, 20, 20));

        verticalLayout_2->addWidget(login_top_widget);

        login_con_widget = new QWidget(login_main_widget);
        login_con_widget->setObjectName(QStringLiteral("login_con_widget"));
        login_con_widget->setMinimumSize(QSize(0, 150));
        login_con_widget->setMaximumSize(QSize(16777215, 150));
        QPalette palette1;
        QBrush brush3(QColor(235, 242, 249, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        login_con_widget->setPalette(palette1);
        label_touxiang = new QLabel(login_con_widget);
        label_touxiang->setObjectName(QStringLiteral("label_touxiang"));
        label_touxiang->setGeometry(QRect(40, 12, 80, 80));
        label_touxiang->setMinimumSize(QSize(80, 80));
        label_touxiang->setMaximumSize(QSize(80, 80));
        label_touxiang->setScaledContents(true);
        lineEdit_un = new QLineEdit(login_con_widget);
        lineEdit_un->setObjectName(QStringLiteral("lineEdit_un"));
        lineEdit_un->setGeometry(QRect(132, 12, 195, 30));
        lineEdit_pass = new QLineEdit(login_con_widget);
        lineEdit_pass->setObjectName(QStringLiteral("lineEdit_pass"));
        lineEdit_pass->setGeometry(QRect(132, 42, 195, 29));
        lineEdit_pass->setEchoMode(QLineEdit::Password);
        label_1 = new QLabel(login_con_widget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(340, 18, 61, 20));
        label_2 = new QLabel(login_con_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 50, 61, 17));
        checkBox = new QCheckBox(login_con_widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(132, 74, 91, 21));
        checkBox->setChecked(false);
        checkBox_2 = new QCheckBox(login_con_widget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(260, 74, 91, 21));
        pushButton_login = new QPushButton(login_con_widget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(132, 106, 195, 32));
        pushButton_login->setMinimumSize(QSize(195, 32));
        label_1->raise();
        label_touxiang->raise();
        lineEdit_un->raise();
        lineEdit_pass->raise();
        label_2->raise();
        checkBox->raise();
        checkBox_2->raise();
        pushButton_login->raise();

        verticalLayout_2->addWidget(login_con_widget);


        verticalLayout->addWidget(login_main_widget);


        retranslateUi(IM_Login);

        QMetaObject::connectSlotsByName(IM_Login);
    } // setupUi

    void retranslateUi(QWidget *IM_Login)
    {
        IM_Login->setWindowTitle(QApplication::translate("IM_Login", "\347\231\273\345\275\225QQ", nullptr));
        label->setText(QString());
        label_minimize->setText(QString());
        label_shutdown->setText(QString());
        label_touxiang->setText(QString());
        lineEdit_un->setText(QApplication::translate("IM_Login", "987654321", nullptr));
        lineEdit_pass->setText(QApplication::translate("IM_Login", "987654321", nullptr));
        label_1->setText(QApplication::translate("IM_Login", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("IM_Login", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        checkBox->setText(QApplication::translate("IM_Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QApplication::translate("IM_Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        pushButton_login->setText(QApplication::translate("IM_Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IM_Login: public Ui_IM_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IM_LOGIN_H
