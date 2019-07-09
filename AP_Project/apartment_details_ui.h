#ifndef APARTMENT_DETAILS_UI_H
#define APARTMENT_DETAILS_UI_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QResource>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFrame>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateEdit>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include <QFont>
#include "headers.h" //prob?
class Apartment_Details_UI : public QWidget
{
    Q_OBJECT

    QLabel *lbl_Address;
    QLabel *lbl_BasePrice;
    QLabel *lbl_FullArea;
    QLabel *lbl_Elevator;
    QLabel *lbl_NumberOfFloors;
    QLabel *lbl_Picture;
    QLabel *lbl_FullPrice;
    QLabel *lbl_NumberOfUnits;

    QLineEdit *led_Address;
    QLineEdit *led_BasePrice;
    QLineEdit *led_FullArea;
    QLineEdit *led_Elevator;
    QLineEdit *led_NumberOfFloors;
    QLineEdit *led_FullPrice;
    QLineEdit *led_NumberOfUnits;


    QPushButton *btn_Edit;

    apartment& aptr;

    QHBoxLayout *my_h_layout;

    QVBoxLayout *my_v_layout;




public:
    explicit Apartment_Details_UI(apartment &aptr ,QWidget *parent = nullptr);
    void AdminMode();
    void UserMode();

signals:

public slots:
};

#endif // APARTMENT_DETAILS_UI_H
