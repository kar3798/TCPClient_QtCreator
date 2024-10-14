/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClient
{
public:
    QWidget *centralwidget;
    QPushButton *connectServer;
    QLabel *label;
    QPushButton *sendButton;
    QLineEdit *lineEdit;
    QTextEdit *chatHistory;
    QMenuBar *menubar;

    void setupUi(QMainWindow *TCPClient)
    {
        if (TCPClient->objectName().isEmpty())
            TCPClient->setObjectName("TCPClient");
        TCPClient->resize(400, 400);
        centralwidget = new QWidget(TCPClient);
        centralwidget->setObjectName("centralwidget");
        connectServer = new QPushButton(centralwidget);
        connectServer->setObjectName("connectServer");
        connectServer->setGeometry(QRect(10, 320, 140, 50));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 380, 20));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(230, 320, 140, 50));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 280, 380, 30));
        chatHistory = new QTextEdit(centralwidget);
        chatHistory->setObjectName("chatHistory");
        chatHistory->setGeometry(QRect(10, 40, 380, 230));
        TCPClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TCPClient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        TCPClient->setMenuBar(menubar);

        retranslateUi(TCPClient);

        QMetaObject::connectSlotsByName(TCPClient);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClient)
    {
        TCPClient->setWindowTitle(QCoreApplication::translate("TCPClient", "TCPClient", nullptr));
        connectServer->setText(QCoreApplication::translate("TCPClient", "Connect to Server", nullptr));
        label->setText(QString());
        sendButton->setText(QCoreApplication::translate("TCPClient", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPClient: public Ui_TCPClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
