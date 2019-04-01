﻿#ifndef LOGINANDREGWINDOW_H
#define LOGINANDREGWINDOW_H

#include <QWidget>
#include <QMovie>
#include "TCP_part/TCPClient.h"
#include "DecodeAnimation.h"
#include "DataModel/UserInfoModel.h"
#include <QFile>
namespace Ui {
class LoginAndRegWindow;
}

class LoginAndRegWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAndRegWindow(QWidget *parent = 0);
    ~LoginAndRegWindow();
    void SetTcpClient(TCPClient *tcp);
    void SetUserInfoModel(UserInfoModel *userInfoModel);
    void SetToolButtonToDefult();
    void InitUI();

private slots:

    void on_CreateExamRoom_clicked();
    void LicenceProofreading(QString Licence);
    // 许可证判断返回时触发的槽函数
    void GetLicenceResult(int Result);
    // 登录判断返回时触发的槽函数
    void GetLoginResult(int Result);
    // 注册判断返回时触发的槽函数
    void GetRegistResult(int Result);
    void on_SignIn_clicked();
    void on_SignUp_clicked();
    // 侧边栏按钮点击槽
    void ToolButtonCliced();


private:
    Ui::LoginAndRegWindow *ui;
    TCPClient *m_tcpClient;
    UserInfoModel *m_userInfoModel;
    QMovie *IndexMovie;
    QString qss_Checked;
    QString qss_Unchecked;
signals:
    void CreateExamRoomSuccess();
    void LoginSuccessfuly();
    void RegistSuccessfuly();

};

#endif // LOGINANDREGWINDOW_H
