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
#include<QComboBox>
#include<QRadioButton>
class Register_UI : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLabel *labelFullName;
    QLabel *labelBirthday;
    QLabel *labelType;

    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditFullName;

    QCheckBox *checkBoxShowPassword;

    QDateEdit *dateEditBirthday;

    QPushButton *pushButtonRegister;
    QPushButton *pushButtonCancel;

    QRadioButton *radioUser;
    QRadioButton *radioManager;

    QVBoxLayout *myVLayout;
    QHBoxLayout *myHLayout;
    QHBoxLayout *typeHLayout;

    QFrame *myFrame;

public slots:
    void setPasswordEchoMode(bool);
    void custom_close();
    void lineEdit_Username_changed(QString);
    void lineEdit_Password_changed(QString);
    void on_btn_register_clicked();

public:
    explicit Register_UI(QWidget *parent = nullptr);


signals:

};


#endif // REGISTER_UI_H
