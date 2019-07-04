#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QLineEdit>
#include<QResource>
#include<QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include<QFrame>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include<QRadioButton>
class Login : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLabel *labelType;

    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;


    QRadioButton *radioUser;
    QRadioButton *radioManager;

    QPushButton *pushButtonLogin;
    QPushButton *pushButtonCancel;

    QCheckBox *checkBoxShowPassword;

    QVBoxLayout *myVLayout;
    QHBoxLayout *myHLayout;
    QHBoxLayout *typeHLayout;

    QFrame *myFrame;

    //move the window

public slots:
    void setPasswordEchoMode(bool);
    void custom_close();
    void lineEdit_Username_changed(QString);
    void lineEdit_Password_changed(QString);
    void on_btn_login_clicked();

public:
    explicit Login(QWidget *parent = nullptr);

signals:

};

#endif // LOGIN_H
