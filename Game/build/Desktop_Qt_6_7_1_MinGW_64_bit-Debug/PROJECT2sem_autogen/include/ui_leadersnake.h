/********************************************************************************
** Form generated from reading UI file 'leadersnake.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERSNAKE_H
#define UI_LEADERSNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LeaderSnake
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QListWidget *listWidget;

    void setupUi(QDialog *LeaderSnake)
    {
        if (LeaderSnake->objectName().isEmpty())
            LeaderSnake->setObjectName("LeaderSnake");
        LeaderSnake->resize(617, 674);
        LeaderSnake->setStyleSheet(QString::fromUtf8("background-image: url(:/res1/bg3.png);"));
        label = new QLabel(LeaderSnake);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 250, 401, 81));
        label->setStyleSheet(QString::fromUtf8("font: 28pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 0, 0);"));
        label_2 = new QLabel(LeaderSnake);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 20, 351, 81));
        label_2->setStyleSheet(QString::fromUtf8("font: 28pt \"Imprint MT Shadow\";\n"
"color: rgb(255, 0, 0);"));
        pushButton = new QPushButton(LeaderSnake);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 620, 83, 29));
        lineEdit = new QLineEdit(LeaderSnake);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 110, 321, 61));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        pushButton_2 = new QPushButton(LeaderSnake);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 200, 83, 29));
        listWidget = new QListWidget(LeaderSnake);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(140, 360, 351, 191));

        retranslateUi(LeaderSnake);

        QMetaObject::connectSlotsByName(LeaderSnake);
    } // setupUi

    void retranslateUi(QDialog *LeaderSnake)
    {
        LeaderSnake->setWindowTitle(QCoreApplication::translate("LeaderSnake", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LeaderSnake", "LEADER BOARD", nullptr));
        label_2->setText(QCoreApplication::translate("LeaderSnake", "ENTER NAME:", nullptr));
        pushButton->setText(QCoreApplication::translate("LeaderSnake", "START", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LeaderSnake", "ENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaderSnake: public Ui_LeaderSnake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERSNAKE_H
