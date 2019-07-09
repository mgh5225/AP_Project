#ifndef SOUTHVILLA_DETAILS_UI_H
#define SOUTHVILLA_DETAILS_UI_H
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
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include <QRadioButton>
#include "headers.h"
class SouthVilla_Details_UI : public QWidget
{
    Q_OBJECT
    QLabel *label_BuildArea;
    QLabel *label_ParkingArea;
    QLabel *label_yardArea;
    QLabel *label_BuildingPicture;
    QLabel *label_FullArea;
    QLabel *label_NumberOfRooms;
    QLabel *label_BasePrice;
    QLabel *label_Address;
    QLabel *lbl_VillaPicture;

    QLineEdit *lineEdit_BuildArea;
    QLineEdit *lineEdit_FrontYardArea;
    QLineEdit *lineEdit_BackYardArea;
    QLineEdit *lineEdit_FullArea;
    QLineEdit *lineEdit_NumberOfRooms;
    QLineEdit *lineEdit_BasePrice;
    QLineEdit *lineEdit_Address;

    QRadioButton *rbtn_sale;
    QRadioButton *rbtn_rent;
    QRadioButton *rbtn_both;

    QVBoxLayout *my_v_layout;



    /////////////

    QPushButton *btn_Buy;
    QPushButton *btn_Rent;
    QPushButton *btn_Edit;
    QPushButton *btn_Save;





    QHBoxLayout *my_h_layout;



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
    sale_file* s;
    rent_file* r;
    south_villa& sv;


    bool IsRentMode = false;
public:
    explicit SouthVilla_Details_UI(sale_file*,rent_file*,south_villa&,QWidget *parent = nullptr);
    void AdminMode();
    void UserMode();

    ///if you need both salemode and rentmode always user rentmode first and then salemode!!!!!
    void SaleMode();
    void RentMode();

signals:

public slots:
    void EditClicked();
};

#endif // SOUTHVILLA_DETAILS_UI_H
