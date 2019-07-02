#ifndef REGISTER_UI_H
#define REGISTER_UI_H

#include <QWidget>
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
#include <QDateEdit>

class Register_UI : public QWidget
{
    Q_OBJECT

    QLabel *labelUsername;
    QLabel *labelPassword;
    QLabel *labelFullName;
    QLabel *labelBirthday;

    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditFullName;

    QCheckBox *checkBoxShowPassword;

    QDateEdit *dateEditBirthday;

    QPushButton *pushButtonRegister;
    QPushButton *pushButtonCancel;


    QVBoxLayout *myVLayout;
    QHBoxLayout *myHLayout;

    QFrame *myFrame;

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

private slots:
    void setPasswordEchoMode(bool);



public:
    explicit Register_UI(QWidget *parent = nullptr);


signals:

public slots:
};

#endif // REGISTER_UI_H
