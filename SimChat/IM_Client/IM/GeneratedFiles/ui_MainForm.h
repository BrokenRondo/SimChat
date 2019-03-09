/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *main_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QWidget *main_top;
    QVBoxLayout *verticalLayout_7;
    QWidget *top_title;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_logo;
    QLabel *label_logo_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_shutdown;
    QWidget *top_names;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_nick;
    QLabel *label_status;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit;
    QWidget *wether_widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QWidget *top_tools;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_zone;
    QPushButton *pushButton_mail;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_skin;
    QPushButton *pushButton_talk;
    QLineEdit *search;
    QWidget *main_center;
    QVBoxLayout *verticalLayout_3;
    QWidget *center_nav;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_p;
    QPushButton *pushButton_q;
    QPushButton *pushButton_t;
    QStackedWidget *center_stack;
    QWidget *page_4;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_9;
    QWidget *page_6;
    QPushButton *pushButton_10;
    QWidget *main_bottom;
    QPushButton *pushButton;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QStringLiteral("MainForm"));
        MainForm->resize(294, 665);
        MainForm->setStyleSheet(QString::fromUtf8("/*\345\256\232\344\271\211\345\205\250\345\261\200\346\273\232\345\212\250\346\235\241\346\240\267\345\274\217*/\n"
"	\n"
" QScrollBar:vertical {\n"
"     width: 10px;\n"
"	 border: 0px;\n"
" }\n"
" \n"
"  QScrollBar:vertical:hover {\n"
"	 background: rgb(221,225,228);\n"
" }\n"
"\n"
"\n"
" QScrollBar::handle:vertical {\n"
"    background: rgb(198,201,203);\n"
"    border-radius:5px;\n"
" }\n"
"\n"
"\n"
" QScrollBar::add-line:vertical {\n"
"     border: 0px;\n"
"     height: 0px;\n"
" }\n"
"\n"
" QScrollBar::sub-line:vertical {\n"
"     border:0px;\n"
"     height: 0px;\n"
" }\n"
"\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 0px;\n"
"	 \n"
" }\n"
"\n"
" QScrollBar::add-page:vertical{\n"
"	border-top-left-radius:5px;\n"
"	border-top-right-radius:5px;\n"
" }\n"
"\n"
"QScrollBar::sub-page:vertical {\n"
"	border-bottom-left-radius:5px;\n"
"	border-bottom-right-radius:5px;\n"
" }\n"
"\n"
" QScrollBar::add-page:vertical:hover, QScrollBar::sub-page:vertical:hover {\n"
"	back"
                        "ground: rgb(221,225,228);\n"
" }\n"
"\n"
"/********************************/\n"
" \n"
" QScrollBar:horizontal {\n"
"     border: 0px;\n"
"     height: 10px;\n"
" }\n"
"\n"
"\n"
" QScrollBar::handle:horizontal {\n"
"     background: rgba(69,124,216,150);\n"
"      \n"
" }\n"
"\n"
" \n"
" QScrollBar::add-line:horizontal {\n"
"     border: 0px;\n"
"     width: 0px;\n"
" }\n"
"\n"
" QScrollBar::sub-line:horizontal {\n"
"     border:0px;\n"
"     width: 0px;\n"
" }\n"
" QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal {\n"
"     border: 0px;\n"
" }\n"
"\n"
" QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"     background: rgba(0,0,0,0);\n"
" }\n"
"\n"
"\n"
" \n"
"/*\346\273\232\345\212\250\346\235\241\346\240\267\345\274\217\345\256\232\344\271\211\347\273\223\346\235\237*/\n"
"\n"
"\n"
""));
        main_widget = new QWidget(MainForm);
        main_widget->setObjectName(QStringLiteral("main_widget"));
        main_widget->setGeometry(QRect(6, 6, 286, 653));
        main_widget->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"#main_widget{\n"
"	border-radius:2px;\n"
"	border-image: url(:/sys/back.png) 5;\n"
"}\n"
"\n"
"#centralwidget{\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"/*\344\270\212\351\203\250\347\224\250\346\210\267\344\277\241\346\201\257\345\214\272\345\237\237*/\n"
"#main_top{\n"
"	\n"
"}\n"
"\n"
"#label_logo_name{\n"
"	color:#fff;\n"
"	font-size:9pt;\n"
"}\n"
"\n"
"/*\346\230\265\347\247\260\357\274\214\347\255\211\347\272\247\357\274\214\347\255\276\345\220\215\347\255\211\344\275\215\347\275\256\345\256\232\344\271\211*/\n"
"#top_names *{\n"
"	color:#fff;\n"
"}\n"
"\n"
"#top_names #label_nick{\n"
"	font-size:12pt;\n"
"}\n"
"\n"
"#top_names #label_status{\n"
"	 \n"
"}\n"
"\n"
"#top_names QLineEdit{\n"
"	color:#fff;\n"
"	font-size:10pt;\n"
"	background-color: rgba(255, 255, 255,0);\n"
"	border:none;\n"
"	border-radius:2px;\n"
"	 \n"
"}\n"
"\n"
"#top_names QLineEdit:focus{\n"
"	background-color: rgb(255, 255, 255); \n"
"	color:#000;\n"
""
                        "	border:1px solid rgb(213, 213, 213);\n"
"}\n"
"\n"
"#top_names QLineEdit:hover{\n"
"	 border:1px solid rgba(0,0,0,100);\n"
"}\n"
"\n"
"/*\347\274\251\345\260\217\345\217\212\345\205\263\351\227\255\346\214\211\351\222\256*/\n"
"#top_title QPushButton{\n"
"	border:none;\n"
"	width:20px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#top_title QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}\n"
"\n"
"#top_title QPushButton#pushButton_minimize{\n"
"	background-image: url(:/sys/mainform_minimize.png);\n"
"}\n"
"\n"
"#top_title QPushButton#pushButton_shutdown{\n"
"	background-image: url(:/sys/mainform_shutdown.png);\n"
"}\n"
"\n"
"\n"
"/*\345\267\245\345\205\267\346\240\217\345\233\276\346\240\207\345\256\232\344\271\211*/\n"
"#top_tools QPushButton{\n"
"	border:none;\n"
"	width:24px;\n"
"	height:20px;\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"#top_tools QPushButton:hover{\n"
"   border:1px solid rgb(13, 97, 137);\n"
"   \n"
"}\n"
"\n"
"/*\346\220\234\347\264\242\346\241\206*/\n"
""
                        "QLineEdit#search{\n"
"	padding:6px;\n"
"	border:none;\n"
"	background-color: rgba(0,0,0,60);\n"
"	color: rgb(229, 229, 229);\n"
"	background-image: url(:/sys/search.png);\n"
"	background-repeat:no;\n"
"	background-position:right center;\n"
"	background-origin: content;\n"
"	\n"
"}\n"
"\n"
"#search:focus{\n"
"	background-color: #fff;\n"
"	color: #000;\n"
"	border-bottom:1px solid #ccc;\n"
"}\n"
"\n"
"#center_stack QWidget{\n"
"	/*background-color: #E8F5FC;*/\n"
"	background-color: rgba(255, 255, 255,230);\n"
"}\n"
"\n"
"#center_stack QWidget>QWidget{\n"
"	/*background-color: #E8F5FC;*/\n"
"	background-color: rgba(255, 255, 255,0);\n"
"}\n"
"\n"
"\n"
"#center_nav{\n"
"	min-height:38px;\n"
"	border-bottom:1px solid rgb(211, 225, 226);\n"
"	background-color: rgba(255, 255, 255,230);\n"
"}\n"
"\n"
"#center_nav QPushButton{\n"
"	border:none;\n"
"	background-repeat:none;\n"
"	background-position:center;\n"
"	height:38px;\n"
"\n"
"}\n"
"\n"
"/*\350\201\224\347\263\273\344\272\272\345\210\227\350\241\250\345\233\276\346"
                        "\240\207\345\256\232\344\271\211---------\345\274\200\345\247\213*/\n"
"#center_nav QPushButton#pushButton_p{\n"
"	background-image: url(:/sys/qqicon_p_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_p:hover{\n"
"	background-image: url(:/sys/qqicon_p_blue.png);\n"
"}\n"
"\n"
"\n"
"#center_nav QPushButton#pushButton_q{\n"
"	background-image: url(:/sys/qqicon_q_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_q:hover{\n"
"	background-image: url(:/sys/qqicon_q_blue.png);\n"
"}\n"
"\n"
"\n"
"\n"
"#center_nav QPushButton#pushButton_t{\n"
"	background-image: url(:/sys/qqicon_t_gray.png);\n"
"}\n"
"\n"
"#center_nav QPushButton#pushButton_t:hover{\n"
"	background-image: url(:/sys/qqicon_t_blue.png);\n"
"}\n"
"\n"
"/*\350\201\224\347\263\273\344\272\272\345\210\227\350\241\250\345\233\276\346\240\207\345\256\232\344\271\211-----------\347\273\223\346\235\237*/\n"
"\n"
"\n"
"\n"
"#main_bottom{\n"
"	border-bottom-left-radius:2px;\n"
"	border-bottom-right-radius:2px;\n"
"	border-top:1px solid rgba"
                        "(0,0,0,40);\n"
"	background-color: rgba(255,255,255,190);\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(main_widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        centralwidget = new QWidget(main_widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(280, 0));
        centralwidget->setStyleSheet(QLatin1String("#centralwidget{\n"
"	background-color: rgb(22, 154, 218);\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        main_top = new QWidget(centralwidget);
        main_top->setObjectName(QStringLiteral("main_top"));
        verticalLayout_7 = new QVBoxLayout(main_top);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        top_title = new QWidget(main_top);
        top_title->setObjectName(QStringLiteral("top_title"));
        horizontalLayout_3 = new QHBoxLayout(top_title);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_logo = new QLabel(top_title);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMinimumSize(QSize(0, 0));
        label_logo->setMaximumSize(QSize(16, 16));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/sys/qlogo.png")));
        label_logo->setScaledContents(true);

        horizontalLayout_3->addWidget(label_logo);

        label_logo_name = new QLabel(top_title);
        label_logo_name->setObjectName(QStringLiteral("label_logo_name"));

        horizontalLayout_3->addWidget(label_logo_name);

        horizontalSpacer = new QSpacerItem(201, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_minimize = new QPushButton(top_title);
        pushButton_minimize->setObjectName(QStringLiteral("pushButton_minimize"));
        pushButton_minimize->setStyleSheet(QLatin1String("QPushButton{\n"
"border-color: rgba(22, 154, 255, 218);\n"
"}"));
        pushButton_minimize->setFlat(false);

        horizontalLayout_3->addWidget(pushButton_minimize);

        pushButton_shutdown = new QPushButton(top_title);
        pushButton_shutdown->setObjectName(QStringLiteral("pushButton_shutdown"));
        pushButton_shutdown->setStyleSheet(QLatin1String("QPushButton{\n"
"border-color: rgba(22, 154, 255, 218);\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(252, 74, 45);\n"
"}"));
        pushButton_shutdown->setFlat(false);

        horizontalLayout_3->addWidget(pushButton_shutdown);


        verticalLayout_7->addWidget(top_title);

        top_names = new QWidget(main_top);
        top_names->setObjectName(QStringLiteral("top_names"));
        horizontalLayout_4 = new QHBoxLayout(top_names);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 0, 0, 0);
        widget_2 = new QWidget(top_names);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 54, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/media/person/media/person/8.jpg")));
        label_2->setScaledContents(true);
        layoutWidget = new QWidget(widget_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(57, 0, 171, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_nick = new QLabel(layoutWidget);
        label_nick->setObjectName(QStringLiteral("label_nick"));

        horizontalLayout->addWidget(label_nick);

        label_status = new QLabel(layoutWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setPixmap(QPixmap(QString::fromUtf8(":/sys/level.png")));

        horizontalLayout->addWidget(label_status);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(lineEdit);


        horizontalLayout_4->addWidget(widget_2);

        wether_widget = new QWidget(top_names);
        wether_widget->setObjectName(QStringLiteral("wether_widget"));
        wether_widget->setMinimumSize(QSize(55, 55));
        verticalLayout_4 = new QVBoxLayout(wether_widget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(wether_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setPixmap(QPixmap(QString::fromUtf8(":/media/wether/media/wether/3.png")));
        label->setScaledContents(true);

        verticalLayout_4->addWidget(label);


        horizontalLayout_4->addWidget(wether_widget);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout_7->addWidget(top_names);

        top_tools = new QWidget(main_top);
        top_tools->setObjectName(QStringLiteral("top_tools"));
        horizontalLayout_5 = new QHBoxLayout(top_tools);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 4, -1, 4);
        pushButton_zone = new QPushButton(top_tools);
        pushButton_zone->setObjectName(QStringLiteral("pushButton_zone"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/sys/qq_tool_zone.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_zone->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_zone);

        pushButton_mail = new QPushButton(top_tools);
        pushButton_mail->setObjectName(QStringLiteral("pushButton_mail"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sys/qq_tool_mail.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_mail->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_mail);

        horizontalSpacer_2 = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_skin = new QPushButton(top_tools);
        pushButton_skin->setObjectName(QStringLiteral("pushButton_skin"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sys/qq_tool_skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_skin->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_skin);

        pushButton_talk = new QPushButton(top_tools);
        pushButton_talk->setObjectName(QStringLiteral("pushButton_talk"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/sys/qq_tool_talk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_talk->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_talk);


        verticalLayout_7->addWidget(top_tools);

        search = new QLineEdit(main_top);
        search->setObjectName(QStringLiteral("search"));
        QPalette palette;
        QBrush brush(QColor(229, 229, 229, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 60));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        search->setPalette(palette);
        search->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_7->addWidget(search);


        verticalLayout_8->addWidget(main_top);

        main_center = new QWidget(centralwidget);
        main_center->setObjectName(QStringLiteral("main_center"));
        verticalLayout_3 = new QVBoxLayout(main_center);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        center_nav = new QWidget(main_center);
        center_nav->setObjectName(QStringLiteral("center_nav"));
        horizontalLayout_2 = new QHBoxLayout(center_nav);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_p = new QPushButton(center_nav);
        pushButton_p->setObjectName(QStringLiteral("pushButton_p"));

        horizontalLayout_2->addWidget(pushButton_p);

        pushButton_q = new QPushButton(center_nav);
        pushButton_q->setObjectName(QStringLiteral("pushButton_q"));

        horizontalLayout_2->addWidget(pushButton_q);

        pushButton_t = new QPushButton(center_nav);
        pushButton_t->setObjectName(QStringLiteral("pushButton_t"));

        horizontalLayout_2->addWidget(pushButton_t);


        verticalLayout_3->addWidget(center_nav);

        center_stack = new QStackedWidget(main_center);
        center_stack->setObjectName(QStringLiteral("center_stack"));
        center_stack->setEnabled(true);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        center_stack->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        verticalLayout_9 = new QVBoxLayout(page_5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        pushButton_9 = new QPushButton(page_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout_9->addWidget(pushButton_9);

        center_stack->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        pushButton_10 = new QPushButton(page_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(11, 175, 258, 28));
        center_stack->addWidget(page_6);

        verticalLayout_3->addWidget(center_stack);


        verticalLayout_8->addWidget(main_center);

        main_bottom = new QWidget(centralwidget);
        main_bottom->setObjectName(QStringLiteral("main_bottom"));
        main_bottom->setMinimumSize(QSize(0, 40));
        main_bottom->setMaximumSize(QSize(16777215, 40));
        main_bottom->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255)"));
        pushButton = new QPushButton(main_bottom);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 5, 31, 31));
        pushButton->setMouseTracking(false);
        pushButton->setFocusPolicy(Qt::ClickFocus);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(245, 245, 245);\n"
"border-style:none;\n"
"color:rgb(255, 247, 247);\n"
"}\n"
"QPushButton:checked{\n"
"background-color: rgb(20, 62, 134);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/sys/addFriend.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(26, 24));
        pushButton->setCheckable(false);
        pushButton->setFlat(false);

        verticalLayout_8->addWidget(main_bottom);


        verticalLayout_2->addWidget(centralwidget);


        retranslateUi(MainForm);

        center_stack->setCurrentIndex(0);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Form", nullptr));
        label_logo->setText(QString());
        label_logo_name->setText(QApplication::translate("MainForm", "QQ", nullptr));
        pushButton_minimize->setText(QString());
        pushButton_shutdown->setText(QString());
        label_2->setText(QString());
        label_nick->setText(QApplication::translate("MainForm", "\351\243\236\347\277\224\347\232\204\344\274\201\351\271\205", nullptr));
        label_status->setText(QString());
        lineEdit->setText(QApplication::translate("MainForm", "\344\270\215\345\277\230\345\210\235\345\277\203\357\274\214\346\226\271\345\276\227\345\247\213\347\273\210", nullptr));
        label->setText(QString());
        pushButton_zone->setText(QString());
        pushButton_mail->setText(QString());
        pushButton_skin->setText(QString());
        pushButton_talk->setText(QString());
        search->setText(QApplication::translate("MainForm", "\346\220\234\347\264\242", nullptr));
        pushButton_p->setText(QString());
        pushButton_q->setText(QString());
        pushButton_t->setText(QString());
        pushButton_9->setText(QApplication::translate("MainForm", "PushButton", nullptr));
        pushButton_10->setText(QApplication::translate("MainForm", "PushButton", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
