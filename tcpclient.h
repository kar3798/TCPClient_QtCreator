#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class TCPClient;
}
QT_END_NAMESPACE

class TCPClient : public QMainWindow
{
    Q_OBJECT

public:
    TCPClient(QWidget *parent = nullptr);
    ~TCPClient();

private slots:
    void on_pushButton_clicked();     // Push button to connect to the server
    void onReadyRead();               // Handles incoming data from server
    void sendMessage();             // Send message to the server



private:
    Ui::TCPClient *ui;
    QTcpSocket *tcpSocket;      // TCP socket for communication with server
};
#endif // TCPCLIENT_H
