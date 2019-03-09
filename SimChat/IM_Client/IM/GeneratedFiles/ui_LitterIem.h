/********************************************************************************
** Form generated from reading UI file 'LitterIem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITTERIEM_H
#define UI_LITTERIEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LitterIem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *litter_main;
    QHBoxLayout *horizontalLayout;
    QLabel *label_pic;
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_signal;
    QLabel *label;

    void setupUi(QWidget *LitterIem)
    {
        if (LitterIem->objectName().isEmpty())
            LitterIem->setObjectName(QStringLiteral("LitterIem"));
        LitterIem->resize(290, 54);
        LitterIem->setMinimumSize(QSize(0, 54));
        LitterIem->setMaximumSize(QSize(16777215, 54));
        LitterIem->setStyleSheet(QLatin1String("#litter_main:hover{\n"
"	background-color: rgb(252, 235, 172);\n"
"}\n"
"\n"
"#label_pic{\n"
"	border-radius:4px;\n"
"	background-color: rgb(0,0,0);\n"
"	 \n"
"}\n"
"\n"
"#label_name{\n"
"	font-size:10pt;	\n"
"}\n"
"\n"
"#label_signal{\n"
"	color:rgb(170, 170, 170)\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(LitterIem);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        litter_main = new QWidget(LitterIem);
        litter_main->setObjectName(QStringLiteral("litter_main"));
        horizontalLayout = new QHBoxLayout(litter_main);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, 6, 11, 6);
        label_pic = new QLabel(litter_main);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setMinimumSize(QSize(42, 42));
        label_pic->setMaximumSize(QSize(42, 42));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/sys/img/sf.jpg")));
        label_pic->setScaledContents(true);

        horizontalLayout->addWidget(label_pic);

        widget = new QWidget(litter_main);
        widget->setObjectName(QStringLiteral("widget"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(6, 6, 201, 35));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout->addWidget(label_name);

        label_signal = new QLabel(layoutWidget);
        label_signal->setObjectName(QStringLiteral("label_signal"));

        verticalLayout->addWidget(label_signal);


        horizontalLayout_3->addLayout(verticalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(10, 10));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addWidget(litter_main);


        retranslateUi(LitterIem);

        QMetaObject::connectSlotsByName(LitterIem);
    } // setupUi

    void retranslateUi(QWidget *LitterIem)
    {
        LitterIem->setWindowTitle(QApplication::translate("LitterIem", "Form", nullptr));
        label_pic->setText(QString());
        label_name->setText(QApplication::translate("LitterIem", "\351\243\236\347\277\224\347\232\204\344\274\201\351\271\205", nullptr));
        label_signal->setText(QApplication::translate("LitterIem", "Happer new year!", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LitterIem: public Ui_LitterIem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITTERIEM_H
