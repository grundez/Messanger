/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widgetLogin;
    QPushButton *loginButton;
    QLineEdit *lineUsername;
    QWidget *page_2;
    QWidget *widgetChat;
    QPushButton *sendMsgButton;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(453, 465);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 10, 421, 411));
        page = new QWidget();
        page->setObjectName("page");
        widgetLogin = new QWidget(page);
        widgetLogin->setObjectName("widgetLogin");
        widgetLogin->setGeometry(QRect(0, 0, 411, 401));
        loginButton = new QPushButton(widgetLogin);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(90, 180, 201, 41));
        lineUsername = new QLineEdit(widgetLogin);
        lineUsername->setObjectName("lineUsername");
        lineUsername->setGeometry(QRect(90, 140, 201, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widgetChat = new QWidget(page_2);
        widgetChat->setObjectName("widgetChat");
        widgetChat->setGeometry(QRect(0, 0, 421, 421));
        sendMsgButton = new QPushButton(widgetChat);
        sendMsgButton->setObjectName("sendMsgButton");
        sendMsgButton->setGeometry(QRect(320, 370, 80, 24));
        textBrowser = new QTextBrowser(widgetChat);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 30, 381, 321));
        lineEdit = new QLineEdit(widgetChat);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 370, 291, 24));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 453, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
