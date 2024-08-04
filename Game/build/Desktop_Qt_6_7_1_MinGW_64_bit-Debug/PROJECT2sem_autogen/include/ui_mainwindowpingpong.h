/********************************************************************************
** Form generated from reading UI file 'mainwindowpingpong.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWPINGPONG_H
#define UI_MAINWINDOWPINGPONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowPingPong
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowPingPong)
    {
        if (MainWindowPingPong->objectName().isEmpty())
            MainWindowPingPong->setObjectName("MainWindowPingPong");
        MainWindowPingPong->resize(800, 600);
        centralwidget = new QWidget(MainWindowPingPong);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 190, 31, 111));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(736, 190, 31, 111));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 280, 41, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color: purple;\n"
"border-radius: 20px;\n"
"\n"
"}"));
        MainWindowPingPong->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowPingPong);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindowPingPong->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowPingPong);
        statusbar->setObjectName("statusbar");
        MainWindowPingPong->setStatusBar(statusbar);

        retranslateUi(MainWindowPingPong);

        QMetaObject::connectSlotsByName(MainWindowPingPong);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowPingPong)
    {
        MainWindowPingPong->setWindowTitle(QCoreApplication::translate("MainWindowPingPong", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindowPingPong", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowPingPong", "TextLabel", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowPingPong: public Ui_MainWindowPingPong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWPINGPONG_H
