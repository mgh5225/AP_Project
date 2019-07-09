#ifndef RENT_DETAILS_UI_H
#define RENT_DETAILS_UI_H

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
#include "headers.h"//prob?
#include "file.h"

class Flat_Details_UI : public QWidget
{
    Q_OBJECT


    QLabel *lbl_FloorNumber;
    QLabel *lbl_UnitPicture;
    QLabel *lbl_NumberOfRooms;
    QLabel *lbl_BuildArea;
    QLabel *lbl_Elevator;

    QLineEdit *led_FloorNumber;
    QLineEdit *led_UnitPicture;
    QLineEdit *led_NumberOfRooms;
    QLineEdit *led_BuildArea;

    QComboBox *comboBox_Elevator;


    QPushButton *btn_Buy;
    QPushButton *btn_Rent;
    QPushButton *btn_Edit;
    QPushButton *btn_Save;





    QHBoxLayout *my_h_layout;


    QVBoxLayout *my_v_layout;

    //////////////////////////////

    ////for rent
    QLabel *lbl_RentalTerms;
    QLabel *lbl_Commission;
    QLabel *lbl_MortgageDuration;
    QLabel *lbl_RentAmount;
    QLabel *lbl_RentDuration;
    QLabel *lbl_RentFinalPrice;


    QLineEdit *led_Commission;
    QLineEdit *led_MortgageDuration;
    QLineEdit *led_RentAmount;
    QLineEdit *led_RentDuration;
    QLineEdit *led_RentFinalPrice;

    QVBoxLayout *my_rent_layout;

    ///////////////////////////////
    ////for sale
    QLabel *lbl_SalesTerms;
    QLabel *lbl_SaleCommission;
    QLabel *lbl_Condition;
    QLineEdit *led_SaleCommission;
    QLineEdit *led_Condition;
    QLabel *lbl_SaleFinalPrice;
    QLineEdit *led_SaleFinalPrice;
    QVBoxLayout *my_sale_layout;
    flat& flt;
    sale_file* s;
    rent_file* r;
    person* p;
    user* u;
    manager* m;


public:
    explicit Flat_Details_UI(person*,sale_file*,rent_file*,flat &flt,QWidget *parent = nullptr);
    void AdminMode();
    void UserMode();
    void SaleMode();
    void RentMode();

signals:

public slots:
    void EditClicked();
    void SaveClicked();
    void BuyClicked();
    void RentClicked();
};

#endif // RENT_DETAILS_UI_H
