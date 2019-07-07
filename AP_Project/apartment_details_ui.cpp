#include "apartment_details_ui.h"

Apartment_Details_UI::Apartment_Details_UI(QWidget *parent) : QWidget(parent)
{



    lbl_Address = new QLabel("Address");
    lbl_BasePrice = new QLabel("Base Price");
    lbl_FullArea = new QLabel(tr("Full Area"));
    lbl_Elevator = new QLabel("Elevator");
    lbl_NumberOfFloors = new QLabel("Number Of Floors");
    lbl_Picture = new QLabel();
    lbl_FullPrice = new QLabel(tr("Full Price"));
    lbl_NumberOfUnits = new QLabel(tr("Number Of Units"));

    lbl_Picture->setPixmap(QPixmap(":/Images/resource/imgs/temp.jpeg").scaled(270,185));
    lbl_Picture->setFixedSize(280,165);



    lbl_Address->setFixedWidth(300);


    led_Address = new QLineEdit();
    led_BasePrice = new QLineEdit();
    led_FullArea = new QLineEdit();
    led_Elevator = new QLineEdit();
    led_NumberOfFloors = new QLineEdit();
    led_FullPrice = new QLineEdit();
    led_NumberOfUnits = new QLineEdit();

    led_Address->setEnabled(false);
    led_Elevator->setEnabled(false);
    led_FullArea->setEnabled(false);
    led_BasePrice->setEnabled(false);
    led_NumberOfFloors->setEnabled(false);
    led_FullPrice->setEnabled(false);
    led_NumberOfUnits->setEnabled(false);

    led_Address->setText("Gorgan iran golshahr");
    led_Elevator->setText("Yes");
    led_FullArea->setText("70");
    led_BasePrice->setText("700000");
    led_NumberOfFloors->setText("4");
    led_FullPrice->setText("90000000");
    led_NumberOfUnits->setText("12");


    my_v_layout = new QVBoxLayout;
    my_h_layout = new QHBoxLayout;


    my_v_layout->addWidget(lbl_Address);
    my_v_layout->addWidget(led_Address);
    my_v_layout->addWidget(lbl_BasePrice);
    my_v_layout->addWidget(led_BasePrice);
    my_v_layout->addWidget(lbl_FullPrice);
    my_v_layout->addWidget(led_FullPrice);
    my_v_layout->addWidget(lbl_NumberOfUnits);
    my_v_layout->addWidget(led_NumberOfUnits);
    my_v_layout->addWidget(lbl_FullArea);
    my_v_layout->addWidget(led_FullArea);
    my_v_layout->addWidget(lbl_NumberOfFloors);
    my_v_layout->addWidget(led_NumberOfFloors);
    my_v_layout->addWidget(lbl_Elevator);
    my_v_layout->addWidget(led_Elevator);



    my_v_layout->setSpacing(2);


    led_Address->setStyleSheet("border: 0px");

    my_h_layout->addWidget(lbl_Picture);
    my_h_layout->addLayout(my_v_layout);
    my_h_layout->setSpacing(30);

    lbl_Address->setStyleSheet("font: bold; font-size: 12px");
    lbl_Elevator->setStyleSheet("font: bold;font-size: 12px");
    lbl_FullArea->setStyleSheet("font: bold;font-size: 12px");
    lbl_BasePrice->setStyleSheet("font: bold;font-size: 12px");
    lbl_NumberOfFloors->setStyleSheet("font: bold;font-size: 12px");
    lbl_FullPrice->setStyleSheet("font: bold;font-size: 12px");
    lbl_NumberOfUnits->setStyleSheet("font: bold;font-size: 12px");
    lbl_Picture->setStyleSheet("border-style: ridge;font-size: 12px");

    led_Address->setStyleSheet("border: white 1px;font-size: 14px");
    led_BasePrice->setStyleSheet("border: white 1px;font-size: 14px");
    led_FullArea ->setStyleSheet("border: white 1px;font-size: 14px");
    led_Elevator ->setStyleSheet("border: white 1px;font-size: 14px");
    led_FullPrice->setStyleSheet("border: white 1px;font-size: 14px");
    led_NumberOfUnits->setStyleSheet("border: white 1px;font-size: 14px");
    led_NumberOfFloors->setStyleSheet(" border: white 1px;font-size: 14px");


    QFrame *myFrame = new QFrame;
    myFrame->setLayout(my_h_layout);
    myFrame->setStyleSheet("background-color: #e3e7e8;border: 4px ; border-color:black");

    QHBoxLayout *temp = new QHBoxLayout;
    temp->addWidget(myFrame);

   this->setAttribute(Qt::WA_TranslucentBackground, true);
        this->setLayout(temp);
   this->setWindowFlags(Qt::FramelessWindowHint);
}
