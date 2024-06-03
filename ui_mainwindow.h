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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QLabel *loginLabel;
    QLabel *usernameBanLabel;
    QWidget *page_2;
    QWidget *widgetChat;
    QPushButton *sendMsgButton;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QListWidget *userListWidget;
    QLabel *recipientUsernameLabel;
    QLabel *membersLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(735, 484);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 10, 701, 411));
        page = new QWidget();
        page->setObjectName("page");
        widgetLogin = new QWidget(page);
        widgetLogin->setObjectName("widgetLogin");
        widgetLogin->setGeometry(QRect(0, 0, 631, 401));
        loginButton = new QPushButton(widgetLogin);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(210, 190, 201, 41));
        loginButton->setCursor(QCursor(Qt::PointingHandCursor));
        loginButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(120, 183, 140);\n"
"border-radius: 20px;        \n"
"border: 2px solid #094065"));
        lineUsername = new QLineEdit(widgetLogin);
        lineUsername->setObjectName("lineUsername");
        lineUsername->setGeometry(QRect(210, 140, 201, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        lineUsername->setFont(font);
        lineUsername->setStyleSheet(QString::fromUtf8("border-radius: 20px;                 \n"
"border: 2px solid #094065;"));
        loginLabel = new QLabel(widgetLogin);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(157, 148, 91, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        loginLabel->setFont(font1);
        loginLabel->setStyleSheet(QString::fromUtf8("color: rgb(120, 183, 140);"));
        usernameBanLabel = new QLabel(widgetLogin);
        usernameBanLabel->setObjectName("usernameBanLabel");
        usernameBanLabel->setEnabled(false);
        usernameBanLabel->setGeometry(QRect(216, 152, 81, 16));
        usernameBanLabel->setFont(font);
        usernameBanLabel->setCursor(QCursor(Qt::IBeamCursor));
        usernameBanLabel->setMouseTracking(true);
        usernameBanLabel->setTabletTracking(false);
        usernameBanLabel->setStyleSheet(QString::fromUtf8("color: rgb(200, 10, 10);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widgetChat = new QWidget(page_2);
        widgetChat->setObjectName("widgetChat");
        widgetChat->setGeometry(QRect(0, 0, 671, 421));
        sendMsgButton = new QPushButton(widgetChat);
        sendMsgButton->setObjectName("sendMsgButton");
        sendMsgButton->setGeometry(QRect(320, 380, 80, 24));
        QFont font2;
        font2.setBold(true);
        sendMsgButton->setFont(font2);
        sendMsgButton->setCursor(QCursor(Qt::PointingHandCursor));
        sendMsgButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(120, 183, 140);\n"
"border-radius: 10px;               \n"
"border: 2px solid #094065"));
        textBrowser = new QTextBrowser(widgetChat);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 40, 381, 321));
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("border-radius: 5px;               \n"
"border: 2px solid #094065"));
        lineEdit = new QLineEdit(widgetChat);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 380, 291, 24));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 10px;               \n"
"border: 2px solid #094065"));
        userListWidget = new QListWidget(widgetChat);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setGeometry(QRect(440, 40, 191, 321));
        userListWidget->setFont(font);
        userListWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;               \n"
"border: 2px solid #094065"));
        recipientUsernameLabel = new QLabel(widgetChat);
        recipientUsernameLabel->setObjectName("recipientUsernameLabel");
        recipientUsernameLabel->setGeometry(QRect(20, 20, 181, 16));
        recipientUsernameLabel->setFont(font1);
        recipientUsernameLabel->setStyleSheet(QString::fromUtf8("color: rgb(120, 183, 140);"));
        membersLabel = new QLabel(widgetChat);
        membersLabel->setObjectName("membersLabel");
        membersLabel->setGeometry(QRect(440, 20, 181, 16));
        membersLabel->setFont(font1);
        membersLabel->setStyleSheet(QString::fromUtf8("color: rgb(120, 183, 140);"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 735, 21));
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
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        usernameBanLabel->setText(QCoreApplication::translate("MainWindow", "Wrong name", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("MainWindow", "=>", nullptr));
        recipientUsernameLabel->setText(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\202", nullptr));
        membersLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
