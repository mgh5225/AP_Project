#include "flat_details_ui.h"

Flat_Details_UI::Flat_Details_UI(person* _p,sale_file* _s,rent_file* _r,flat &flt,QWidget *parent) : flt(flt),QWidget(parent)
{

    s=_s;
    r=_r;
    p=_p;
    u=dynamic_cast<user*>(p);
    m=dynamic_cast<manager*>(p);
    lbl_FloorNumber = new QLabel(tr("Floor Number"));
    lbl_UnitPicture = new QLabel;
    lbl_NumberOfRooms = new QLabel(tr("Number Of Rooms"));
    lbl_BuildArea = new QLabel(tr("Build Area"));
    lbl_Elevator = new QLabel(tr("Elevator"));
    QLabel *lbl_detail = new QLabel("Detail");


    led_FloorNumber = new QLineEdit;
    led_UnitPicture = new QLineEdit;
    led_NumberOfRooms = new QLineEdit;
    led_BuildArea = new QLineEdit;


    comboBox_Elevator = new QComboBox;
    comboBox_Elevator->addItem("Yes");
    comboBox_Elevator->addItem("No");
    comboBox_Elevator->setEnabled(false);
    //comboBox_Elevator->setCurrentText() tooodoooooooooo

    led_FloorNumber ->setEnabled(false);
    led_UnitPicture ->setEnabled(false);
    led_NumberOfRooms->setEnabled(false);
    led_BuildArea ->setEnabled(false);

    btn_Buy = new QPushButton("Buy");
    btn_Rent = new QPushButton("Rent");
    btn_Edit = new QPushButton("Edit");
    btn_Save = new QPushButton("Save");
    btn_Buy->hide();
    btn_Rent->hide();
    btn_Edit->hide();
    btn_Save->hide();

    led_FloorNumber->setText(QString::number(flt.get_floor_num()));
    led_NumberOfRooms->setText(QString::number(flt.get_rooms()));
    led_BuildArea->setText(QString::number(flt.get_building_area()));
    if(flt.get_lift())comboBox_Elevator->setCurrentIndex(0);
    else comboBox_Elevator->setCurrentIndex(1);
    lbl_UnitPicture-> setPixmap(QPixmap(flt.get_picture()).scaled(256,150));




    my_v_layout = new QVBoxLayout;
    my_v_layout->addWidget(lbl_detail,0,Qt::AlignTop);
    my_v_layout->addWidget(lbl_BuildArea);
    my_v_layout->addWidget(led_BuildArea);
    my_v_layout->addWidget(lbl_Elevator);
    my_v_layout->addWidget(comboBox_Elevator);
    my_v_layout->addWidget(lbl_FloorNumber);
    my_v_layout->addWidget(led_FloorNumber);
    my_v_layout->addWidget(lbl_NumberOfRooms);
    my_v_layout->addWidget(led_NumberOfRooms);


    //////////rent///////////////

    lbl_RentalTerms = new QLabel(tr("Rental Terms"));
    lbl_Commission= new QLabel("Rent Commission");
    lbl_MortgageDuration= new QLabel(tr("Mortagege Amount"));
    lbl_RentAmount= new QLabel(tr("Rent Amount"));
    lbl_RentDuration= new QLabel(tr("Rent Duration"));
    lbl_RentFinalPrice = new QLabel(tr("Full Price"));

    led_Commission = new QLineEdit();
    led_MortgageDuration= new QLineEdit();
    led_RentAmount= new QLineEdit();
    led_RentDuration= new QLineEdit();
    led_RentFinalPrice = new QLineEdit();


    led_Commission->setEnabled(false);
    led_MortgageDuration->setEnabled(false);
    led_RentAmount->setEnabled(false);
    led_RentDuration->setEnabled(false);

    my_rent_layout = new QVBoxLayout();

    my_rent_layout->addWidget(lbl_RentalTerms,0,Qt::AlignTop);
    my_rent_layout->addWidget(lbl_Commission);
    my_rent_layout->addWidget(led_Commission);
    my_rent_layout->addWidget(lbl_MortgageDuration);
    my_rent_layout->addWidget(led_MortgageDuration);
    my_rent_layout->addWidget(lbl_RentAmount);
    my_rent_layout->addWidget(led_RentAmount);
    my_rent_layout->addWidget(lbl_RentDuration);
    my_rent_layout->addWidget(led_RentDuration);
    my_rent_layout->addWidget(lbl_RentFinalPrice);
    my_rent_layout->addWidget(led_RentFinalPrice);

    lbl_RentalTerms ->    hide();
    lbl_Commission->      hide();
    lbl_MortgageDuration->hide();
    lbl_RentAmount     -> hide();
    lbl_RentDuration  ->  hide();
    lbl_RentFinalPrice->hide();

    led_Commission ->setEnabled(false);
    led_MortgageDuration->setEnabled(false);
    led_RentAmount->setEnabled(false);
    led_RentDuration->setEnabled(false);
    led_RentFinalPrice->setEnabled(false);

    led_Commission ->hide();
    led_MortgageDuration->hide();
    led_RentAmount->hide();
    led_RentDuration->hide();
    led_RentFinalPrice->hide();
    if(r){
        led_Commission->setText(QString::number(r->get_commission()));
        led_MortgageDuration->setText(QString::number(r->mortgage_price()));
        led_RentAmount->setText(QString::number(r->rent_price()));
        led_RentDuration->setText(QString::number(r->get_duration()));
        led_RentFinalPrice->setText(QString::number(r->final_price()));
    }

    /////////sale///////////
    led_SaleCommission = new QLineEdit;
    led_Condition = new QLineEdit;
    led_SaleFinalPrice = new QLineEdit();
    led_SaleCommission->setEnabled(false);
    led_Condition ->setEnabled(false);
    led_SaleFinalPrice->setEnabled(false);

    lbl_SaleCommission = new QLabel("Sale Commision");
    lbl_SalesTerms = new QLabel("Sale Terms");
    lbl_Condition = new QLabel("Condition");

    lbl_SaleFinalPrice= new QLabel("Full Price");


    my_sale_layout = new QVBoxLayout;

    my_sale_layout->addWidget(lbl_SalesTerms,0,Qt::AlignTop);
    my_sale_layout->addWidget(lbl_SaleCommission,1,Qt::AlignTop);
    my_sale_layout->addWidget(led_SaleCommission,2,Qt::AlignTop);
    my_sale_layout->addWidget(lbl_Condition,3,Qt::AlignTop);
    my_sale_layout->addWidget(led_Condition,4,Qt::AlignTop);
    my_sale_layout->addWidget(lbl_SaleFinalPrice,5,Qt::AlignTop);
    my_sale_layout->addWidget(led_SaleFinalPrice,6,Qt::AlignTop);

    led_SaleCommission->hide();
    led_Condition->hide();
    led_SaleCommission->hide();
    lbl_SaleCommission ->hide();
    lbl_SalesTerms ->hide();
    lbl_Condition ->hide();
    lbl_SaleFinalPrice->hide();
    led_SaleFinalPrice->hide();

    if(s){
        led_SaleCommission->setText(QString::number(s->get_commission()));
        led_Condition->setText(s->get_condition());
        led_SaleFinalPrice->setText(QString::number(s->final_price()));
    }

    //////////
    lbl_UnitPicture->setFixedSize(280,165);
    lbl_Commission->setFixedWidth(200);
    lbl_BuildArea->setFixedWidth(200);
    lbl_SaleCommission->setFixedWidth(200);
    /// ///////

    QVBoxLayout *tmp = new QVBoxLayout;

    tmp->addWidget(lbl_UnitPicture);
    QHBoxLayout *tmp_h = new QHBoxLayout;
    tmp_h->addWidget(btn_Buy);
    tmp_h->addWidget(btn_Rent);

    tmp->addWidget(btn_Edit);
    tmp->addWidget(btn_Save);
    tmp->addLayout(tmp_h);

    my_h_layout = new QHBoxLayout;

    my_h_layout->addLayout(tmp,Qt::AlignBottom);
    my_h_layout->addLayout(my_v_layout);
    my_h_layout->addLayout(my_rent_layout);
    my_h_layout->addLayout(my_sale_layout,Qt::AlignBottom);
    this->setLayout(my_h_layout);
    /////////css//////////

    lbl_detail->setStyleSheet("font: bold;font-size: 12px");
    lbl_Elevator->setStyleSheet("font: bold;font-size: 12px");
    lbl_BuildArea->setStyleSheet("font: bold;font-size: 12px");
    lbl_Condition->setStyleSheet("font: bold;font-size: 12px");
    lbl_Commission->setStyleSheet("font: bold;font-size: 12px");
    lbl_RentAmount->setStyleSheet("font: bold;font-size: 12px");
    lbl_SalesTerms->setStyleSheet("font: bold;font-size: 12px; color:green");;
    lbl_FloorNumber->setStyleSheet("font: bold;font-size: 12px");
    lbl_MortgageDuration->setStyleSheet("font: bold;font-size: 12px");
    lbl_SaleFinalPrice->setStyleSheet("font: bold;font-size: 12px");
    lbl_SaleCommission->setStyleSheet("font: bold;font-size: 12px");
    lbl_RentFinalPrice->setStyleSheet("font: bold;font-size: 12px");
    lbl_NumberOfRooms->setStyleSheet("font: bold;font-size: 12px");
    lbl_RentDuration->setStyleSheet("font: bold;font-size: 12px");
    lbl_UnitPicture->setStyleSheet("font: bold;font-size: 12px");
    lbl_RentalTerms->setStyleSheet("font: bold;font-size: 12px; color:#16a085");

    this->setStyleSheet("QLineEdit{border: white 1px;font-size: 14px}");

    btn_Edit->setStyleSheet("QPushButton:pressed {background-color: #0D47A1;color:#3498db;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#3498db;color:#0D47A1;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif;margin-top:20px} ");
    btn_Save->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} ");
    btn_Buy->setStyleSheet("QPushButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QPushButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;} ");
    btn_Rent->setStyleSheet("QPushButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QPushButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;} ");

    /////////////
    connect(btn_Edit,SIGNAL(clicked()),this ,SLOT(EditClicked()));
    connect(btn_Save,SIGNAL(clicked()),this,SLOT(SaveClicked()));
    connect(btn_Buy,SIGNAL(clicked()),this,SLOT(BuyClicked()));
    connect(btn_Rent,SIGNAL(clicked()),this,SLOT(RentClicked()));
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    if(r){
        RentMode();
    }
    if(s){
        SaleMode();
    }
    if(u){
        UserMode();
    }
    if(m){
        AdminMode();
    }
}

void Flat_Details_UI::AdminMode()
{
    if(s){
        btn_Buy->show();
        if(s->get_user_ID()=="")btn_Buy->setEnabled(true);
        else btn_Buy->setEnabled(false);
    }
    if(r){
        btn_Rent->show();
        if(r->get_user_ID()=="")btn_Rent->setEnabled(true);
        else btn_Rent->setEnabled(false);
    }
    btn_Edit->show();
    btn_Save->hide();

}

void Flat_Details_UI::UserMode()
{
    if(s){
        btn_Buy->show();
        if(s->get_user_ID()=="")btn_Buy->setEnabled(true);
        else btn_Buy->setEnabled(false);
    }
    if(r){
        btn_Rent->show();
        if(r->get_user_ID()=="")btn_Rent->setEnabled(true);
        else btn_Rent->setEnabled(false);
    }
    btn_Edit->hide();
    btn_Save->hide();
}

void Flat_Details_UI::SaleMode()
{
    led_SaleCommission->show();
    led_Condition->show();
    lbl_SaleCommission->show();
    lbl_SalesTerms->show();
    lbl_Condition ->show();
    lbl_SaleFinalPrice->show();
    led_SaleFinalPrice->show();
}

void Flat_Details_UI::RentMode()
{
    lbl_RentalTerms ->show();
    lbl_Commission->show();
    lbl_MortgageDuration->show();
    lbl_RentAmount     ->show();
    lbl_RentDuration  ->show();
    lbl_RentFinalPrice->show();

    led_Commission ->show();
    led_MortgageDuration->show();
    led_RentAmount->show();
    led_RentDuration->show();
    led_RentFinalPrice->show();
}

void Flat_Details_UI::EditClicked()
{
    btn_Buy->hide();
    btn_Rent->hide();
    btn_Edit->hide();
    btn_Save->show();
    comboBox_Elevator->setEnabled(true);
    led_FloorNumber ->setEnabled(true);
    led_NumberOfRooms->setEnabled(true);
    led_BuildArea ->setEnabled(true);
    if(r){
    led_Commission ->setEnabled(true);
    led_RentDuration->setEnabled(true);
    }
    if(s){
    led_SaleCommission->setEnabled(true);
    led_Condition ->setEnabled(true);
    }
}

void Flat_Details_UI::SaveClicked()
{
    btn_Edit->hide();
    flt.set_lift(!comboBox_Elevator->currentIndex());
    flt.set_floor_num(led_FloorNumber->text().toInt());
    flt.set_rooms(led_NumberOfRooms->text().toInt());
    flt.set_building_area(led_BuildArea->text().toLongLong());
    for(int j=0;j<flats[flt.get_current_apartment_ID()].size();j++){
        if(flats[flt.get_current_apartment_ID()][j].get_id()==flt.get_id()){
            flats[flt.get_current_apartment_ID()][j]=flt;
            QJsonObject temp;
            flt.write(temp);
            flatsjson[flt.get_id()]=temp;
        }
    }
    if(r){
        r->set_commission(led_Commission->text().toDouble());
        r->set_duration(led_RentDuration->text().toInt());
       rents[r->get_building_ID()]=*r;
       QJsonObject temp;
       r->write(temp);
       rentsjson[r->get_building_ID()]=temp;
    }
    if(s){
        s->set_commission(led_SaleCommission->text().toDouble());
        s->set_condition(led_Condition->text());
        sales[s->get_building_ID()]=*s;
        QJsonObject temp;
        s->write(temp);
        rentsjson[s->get_building_ID()]=temp;
    }
    close();
}

void Flat_Details_UI::BuyClicked()
{
    QMessageBox msg;
    if(p->get_balance()>s->final_price()){
        s->set_user_ID(p->get_user());
        QJsonObject temp;
        s->write(temp);
        salesjson[flt.get_id()]=temp;
        msg.setText("Your request for buying this flat has submitted!");
        msg.exec();
        close();
    }
    else{
        msg.setText("Your account balance is not enough!");
         msg.exec();
         close();
    }

}
void Flat_Details_UI::RentClicked(){
    QMessageBox msg;
    if(p->get_balance()>r->final_price()){
        r->set_user_ID(p->get_user());
        QJsonObject temp;
        r->write(temp);
        salesjson[flt.get_id()]=temp;
        msg.setText("Your request for renting this flat has submitted!");
        msg.exec();
        close();
    }
    else{
        msg.setText("Your account balance is not enough!");
        msg.exec();
        close();
}
}
