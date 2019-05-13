﻿#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
namespace Ui {
class TCPClient;
}


class TCPClient : public QWidget
{
    Q_OBJECT
public:
    explicit TCPClient(QWidget *parent = 0);
    ~TCPClient();
    void InitTcp(QTcpSocket *getTcpClient);
    QTcpSocket *tcpClient;

    void InitFuncMap();
    void ConnectToServer(QString Ip, quint16 Port);
    void DisConnectToServer();
    void SendInfo(const char*  Licence);
private:
    Ui::TCPClient *ui;
    void LicenceResultSingal();
private slots:
    //客户端槽函数
    void ReadData();
    void ReadError(QAbstractSocket::SocketError);

    void on_btnConnect_clicked();
    void on_btnSend_clicked();
    void on_pushButton_clicked();
    void on_btnConnect_2_clicked();

    void on_GetHelp_clicked();

signals:
    void LicenceResult(int type);
    void DoLogin(int type);
    void DoRegiste(int type);
    void ExaminationBegins(QString ExamRoomInfo);
    void DoHandInPaper();
    void SetExamHistory(QString ExamHistory);
    void SetInfomation(QString Infomation);
};

#endif // TCPCLIENT_H
