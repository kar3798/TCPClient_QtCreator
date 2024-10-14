#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QDateTime>

TCPClient::TCPClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TCPClient)
    , tcpSocket(new QTcpSocket(this))   // Initialize the TCP socket
{
    ui->setupUi(this);

    // Setup the UI
    ui->chatHistory->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->chatHistory->setWordWrapMode(QTextOption::WordWrap);
    ui->chatHistory->setReadOnly(true);

    // Connect signals to slots
    connect(ui->connectServer, &QPushButton::clicked, this, &TCPClient::on_pushButton_clicked);
    connect(ui->sendButton, &QPushButton::clicked, this, &TCPClient::sendMessage);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &TCPClient::sendMessage); // Send on Enter key
    connect(tcpSocket, &QTcpSocket::readyRead, this, &TCPClient::onReadyRead);

}

TCPClient::~TCPClient()
{
    delete ui;
}

// This function will be triggered when the button is clicked, connects client to the server
void TCPClient::on_pushButton_clicked()
{
    // Connect to the server on localhost and port 1234
    tcpSocket->connectToHost("127.0.0.1", 1234);

    if (tcpSocket->waitForConnected(5000)){
        ui->label->setText("Connected to server!");
        // tcpSocket->write("Hello, server!");
    } else {
        ui->label->setText("Failed to connect to server!");
    }
}

// This function handles incoming data from the server
void TCPClient::onReadyRead()
{
    QByteArray dataFromServer = tcpSocket->readAll();
    QString responseMessage = QString::fromUtf8(dataFromServer);

    // Get current time for the timestamp
    QString timeStamp = QDateTime::currentDateTime().toString("hh:mm:ss");

    // Format and append server message with timestamp and color
    ui->chatHistory->append(QString("<font color='green'>[%1] <b>Server:</b> %2</font>")
                                .arg(timeStamp, responseMessage));
}

// This function handles the portion for the data to the client
void TCPClient::sendMessage()
{
    QString message = ui->lineEdit->text();
    if (tcpSocket->state() == QAbstractSocket::ConnectedState) {
        tcpSocket->write(message.toUtf8());
        // Get current time for the timestamp
        QString timeStamp = QDateTime::currentDateTime().toString("hh:mm:ss");

        // Format and append client message with timestamp and color
        ui->chatHistory->append(QString("<font color='blue'>[%1] <b>Client:</b> %2</font>")
                                    .arg(timeStamp, message));

        ui->lineEdit->clear();
    }
}
