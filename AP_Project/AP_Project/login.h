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

class Login : public QWidget
{
    Q_OBJECT
    QLabel *labelUsername;
    QLabel *labelPassword;

    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;

    QPushButton *pushButtonLogin;
    QPushButton *pushButtonCancel;

    QCheckBox *checkBoxShowPassword;

    QVBoxLayout *myVLayout;
    QHBoxLayout *myHLayout;

    QFrame *myFrame;

    //move the window
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

private slots:
    void setPasswordEchoMode(bool);
public:
    explicit Login(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // LOGIN_H
