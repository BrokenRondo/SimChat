/********************************************************************************
** Form generated from reading UI file 'RegisterDia.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIA_H
#define UI_REGISTERDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDia
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LE_pwd;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_sure;
    QPushButton *PB_cancel;

    void setupUi(QDialog *RegisterDia)
    {
        if (RegisterDia->objectName().isEmpty())
            RegisterDia->setObjectName(QStringLiteral("RegisterDia"));
        RegisterDia->resize(334, 175);
        RegisterDia->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"#RegisterDialog{\n"
"	border-radius:2px;\n"
"	background-color: #09A3DC;\n"
"}\n"
"\n"
"#RegisterDialog QPushButton{\n"
"	    border: none;\n"
"        color: rgb(2, 65, 132);\n"
"        background: transparent;\n"
"}\n"
"\n"
"#RegisterDialog QPushButton:hover{\n"
"	    background: rgb(187, 212, 238);\n"
"}\n"
"\n"
"#RegisterDialog QPushButton:pressed{\n"
"	    background: rgb(6, 94, 187);\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(RegisterDia);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(RegisterDia);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        LE_username = new QLineEdit(RegisterDia);
        LE_username->setObjectName(QStringLiteral("LE_username"));

        horizontalLayout->addWidget(LE_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, -1, -1, -1);
        label_2 = new QLabel(RegisterDia);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        LE_pwd = new QLineEdit(RegisterDia);
        LE_pwd->setObjectName(QStringLiteral("LE_pwd"));

        horizontalLayout_2->addWidget(LE_pwd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PB_sure = new QPushButton(RegisterDia);
        PB_sure->setObjectName(QStringLiteral("PB_sure"));

        horizontalLayout_3->addWidget(PB_sure);

        PB_cancel = new QPushButton(RegisterDia);
        PB_cancel->setObjectName(QStringLiteral("PB_cancel"));

        horizontalLayout_3->addWidget(PB_cancel);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        retranslateUi(RegisterDia);

        QMetaObject::connectSlotsByName(RegisterDia);
    } // setupUi

    void retranslateUi(QDialog *RegisterDia)
    {
        RegisterDia->setWindowTitle(QApplication::translate("RegisterDia", "Dialog", nullptr));
        label->setText(QApplication::translate("RegisterDia", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("RegisterDia", "\345\257\206\347\240\201\357\274\232", nullptr));
        PB_sure->setText(QApplication::translate("RegisterDia", "\347\241\256\345\256\232", nullptr));
        PB_cancel->setText(QApplication::translate("RegisterDia", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDia: public Ui_RegisterDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIA_H
