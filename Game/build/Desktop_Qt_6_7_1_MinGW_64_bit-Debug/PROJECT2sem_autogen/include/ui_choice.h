/********************************************************************************
** Form generated from reading UI file 'choice.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOICE_H
#define UI_CHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_choice
{
public:
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *choice)
    {
        if (choice->objectName().isEmpty())
            choice->setObjectName("choice");
        choice->resize(1920, 1080);
        choice->setStyleSheet(QString::fromUtf8("\n"
"	background-image: url(:/res1/choose.png);\n"
"    background-position: center;\n"
"    background-repeat: no-repeat;\n"
"    background-size: cover;\n"
""));
        label_2 = new QLabel(choice);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1100, 430, 161, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 26pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 255, 0);"));
        label = new QLabel(choice);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 430, 301, 41));
        label->setStyleSheet(QString::fromUtf8("font: 26pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 255, 0);"));
        pushButton = new QPushButton(choice);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1030, 390, 351, 101));
        pushButton->setStyleSheet(QString::fromUtf8("   background: transparent;\n"
"    border: none; \n"
""));
        pushButton_3 = new QPushButton(choice);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(200, 740, 351, 101));
        pushButton_3->setStyleSheet(QString::fromUtf8("   background: transparent;\n"
"    border: none; "));
        label_4 = new QLabel(choice);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1100, 750, 141, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 26pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 255, 0);"));
        label_5 = new QLabel(choice);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(620, 150, 381, 79));
        label_5->setStyleSheet(QString::fromUtf8("font: 40pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 0, 0);"));
        pushButton_2 = new QPushButton(choice);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1030, 740, 304, 87));
        pushButton_2->setStyleSheet(QString::fromUtf8("   background: transparent;\n"
"    border: none; \n"
""));
        label_3 = new QLabel(choice);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(330, 750, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 26pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 255, 0);"));
        pushButton_4 = new QPushButton(choice);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(200, 390, 351, 101));
        pushButton_4->setStyleSheet(QString::fromUtf8("   background: transparent;\n"
"    border: none; \n"
""));

        retranslateUi(choice);

        QMetaObject::connectSlotsByName(choice);
    } // setupUi

    void retranslateUi(QDialog *choice)
    {
        choice->setWindowTitle(QCoreApplication::translate("choice", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("choice", "SNAKE", nullptr));
        label->setText(QCoreApplication::translate("choice", "TIC TAC TOE", nullptr));
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        label_4->setText(QCoreApplication::translate("choice", "PONG", nullptr));
        label_5->setText(QCoreApplication::translate("choice", "CHOOSE!!!!!", nullptr));
        pushButton_2->setText(QString());
        label_3->setText(QCoreApplication::translate("choice", "SPR", nullptr));
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class choice: public Ui_choice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOICE_H
