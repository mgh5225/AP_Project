#include "addbuilding.h"

AddBuilding::AddBuilding(QWidget *parent) : QWidget(parent)
{
    btn_AddFlat = new QToolButton();
    btn_AddApartment = new QToolButton();
    btn_AddNorthVilla = new QToolButton();
    btn_AddSouthVilla = new QToolButton();
    btn_AddApartment->setText(tr("Add Apartment"));
    btn_AddNorthVilla->setText(tr("Add North Villa"));
    btn_AddFlat->setText(tr("Add Flat"));
    btn_AddSouthVilla->setText(tr("Add South Villa"));

    btn_AddFlat->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_AddApartment->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_AddNorthVilla->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_AddSouthVilla->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );


   btn_AddApartment ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_AddNorthVilla ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_AddSouthVilla ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_AddFlat->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");

   apartment = new AddNewApartment_UI(this);
    soutVilla = new AddNewSouthVilla(this);
    northVilla = new AddNewNorthVilla(this);
    my_grid_Layout = new QGridLayout();

    my_grid_Layout->addWidget(btn_AddApartment,0,0);
    my_grid_Layout->addWidget(btn_AddNorthVilla,1,0);
    my_grid_Layout->addWidget(btn_AddFlat,0,1);
    my_grid_Layout->addWidget(btn_AddSouthVilla,1,1);

    QFrame *myFrame = new QFrame();
    myFrame->setLayout(my_grid_Layout);
    myFrame->setStyleSheet("background-color:#e3e7e8;border-radius: 5px;");


    ////////////////////////////////////////
    //set frame

    QHBoxLayout *temp = new QHBoxLayout;
    temp->addWidget(myFrame);
    /////////////////////////////////////
    // round window!!
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////


    this->setLayout(temp);
    connect(btn_AddApartment,SIGNAL(clicked()),this,SLOT(AddApartment()));
    connect(btn_AddSouthVilla,SIGNAL(clicked()),this,SLOT(AddSoutVilla()));
    connect(btn_AddNorthVilla,SIGNAL(clicked()),this,SLOT(AddNorthVilla()));
}


void AddBuilding::AddApartment()
{
    btn_AddApartment->hide();
    btn_AddFlat->hide();
    btn_AddNorthVilla->hide();
    btn_AddSouthVilla->hide();
    soutVilla->hide();
    Enable = false;
    my_grid_Layout->addWidget(apartment,1,0);
}

void AddBuilding::AddSoutVilla()
{
    btn_AddApartment->hide();
    btn_AddFlat->hide();
    btn_AddNorthVilla->hide();
    btn_AddSouthVilla->hide();
    apartment->hide();
    my_grid_Layout->addWidget(soutVilla,1,0);
}

void AddBuilding::AddNorthVilla()
{
    btn_AddApartment->hide();
    btn_AddFlat->hide();
    btn_AddNorthVilla->hide();
    btn_AddSouthVilla->hide();

    my_grid_Layout->addWidget(northVilla,1,0);

}
