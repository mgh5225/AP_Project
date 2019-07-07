#ifndef ADDRENT_UI_H
#define ADDRENT_UI_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QDialog>
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
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include <QRadioButton>

class AddRent_UI : public QDialog
{
    Q_OBJECT

    QLineEdit *led_Commission;
    QLineEdit *led_MortgageDuration;
    QLineEdit *led_RentAmount;
    QLineEdit *led_RentDuration;
    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QHBoxLayout *my_h_layout;
    QVBoxLayout *my_v_layout;
public:
    explicit AddRent_UI(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ADDRENT_UI_H
