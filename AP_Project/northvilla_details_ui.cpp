#include "northvilla_details_ui.h"

NorthVilla_Details_UI::NorthVilla_Details_UI(person* _p,sale_file* _s,rent_file* _r,north_villa& nv,QWidget *parent) :nv(nv), QWidget(parent)
{
    s=_s;
    r=_r;
    p=_p;
    u=dynamic_cast<user*>(p);
    m=dynamic_cast<manager*>(p);
    label_BuildArea  = new QLabel(tr("Build Area"));
    label_FrontYardArea  = new QLabel(tr("Front yard Area"));
    label_BackyardArea  = new QLabel(tr("Back yard Area"));
    label_BuildingPicture  = new QLabel(tr("Building Picture"));
    label_FullArea = new QLabel(tr("Full Area"));
    label_NumberOfRooms = new QLabel(tr("Number Of Rooms"));
    label_BasePrice = new QLabel(tr("Base Price"));
    label_Address = new QLabel(tr("Address"));

    lineEdit_BuildArea = new QLineEdit;
    lineEdit_FrontYardArea = new QLineEdit;
    lineEdit_BackYardArea = new QLineEdit;
    lineEdit_FullArea = new QLineEdit;
    lineEdit_NumberOfRooms = new QLineEdit;
    lineEdit_BasePrice = new QLineEdit;
    lineEdit_Address = new QLineEdit;

    my_v_layout = new QVBoxLayout;

    lineEdit_BuildArea->setEnabled(false);
    lineEdit_FrontYardArea ->setEnabled(false);
    lineEdit_BackYardArea->setEnabled(false);
    lineEdit_FullArea->setEnabled(false);
    lineEdit_NumberOfRooms->setEnabled(false);
    lineEdit_BasePrice->setEnabled(false);
    lineEdit_Address->setEnabled(false);

    QHBoxLayout *tmp_H2 = new QHBoxLayout;
    QLabel *labelFor = new QLabel("For");
    rbtn_both= new QRadioButton(tr("Both"));
    rbtn_rent= new QRadioButton(tr("Rent"));
    rbtn_sale= new QRadioButton(tr("Sale"));
    tmp_H2->addWidget(rbtn_sale);
    tmp_H2->addWidget(rbtn_rent);
    tmp_H2->addWidget(rbtn_both);

    my_v_layout->addWidget(label_BuildArea);
    my_v_layout->addWidget(lineEdit_BuildArea);
    my_v_layout->addWidget(label_BackyardArea);
    my_v_layout->addWidget(lineEdit_BackYardArea);
    my_v_layout->addWidget(label_FrontYardArea);
    my_v_layout->addWidget(lineEdit_FrontYardArea);
    my_v_layout->addWidget(label_FullArea);
    my_v_layout->addWidget(lineEdit_FullArea);
    my_v_layout->addWidget(labelFor);
    my_v_layout->addLayout(tmp_H2);
    my_v_layout->addWidget(label_Address);
    my_v_layout->addWidget(lineEdit_Address);
    my_v_layout->addWidget(label_BasePrice);
    my_v_layout->addWidget(lineEdit_BasePrice);
    my_v_layout->addWidget(label_NumberOfRooms);
    my_v_layout->addWidget(lineEdit_NumberOfRooms);

    btn_Buy = new QPushButton("Buy");
    btn_Rent = new QPushButton("Rent");
    btn_Edit = new QPushButton("Edit");
    btn_Save = new QPushButton("Save");
    btn_Buy->hide();
    btn_Rent->hide();
    btn_Edit->hide();
    btn_Save->hide();

    //////////////////////////
    QVBoxLayout *SellAndRent_layout = new QVBoxLayout;
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
    led_RentFinalPrice->setEnabled(false);


    SellAndRent_layout->addWidget(lbl_RentalTerms,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(lbl_Commission,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(led_Commission,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(lbl_MortgageDuration,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(led_MortgageDuration,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(lbl_RentAmount,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(led_RentAmount,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(lbl_RentDuration,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(led_RentDuration,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(lbl_RentFinalPrice,0,Qt::AlignTop);
    SellAndRent_layout->addWidget(led_RentFinalPrice,0,Qt::AlignTop);

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


    QVBoxLayout *Sell_layout = new QVBoxLayout();

    Sell_layout->addWidget(lbl_SalesTerms,0,Qt::AlignTop);
    Sell_layout->addWidget(lbl_SaleCommission,0,Qt::AlignTop);
    Sell_layout->addWidget(led_SaleCommission,0,Qt::AlignTop);
    Sell_layout->addWidget(lbl_Condition,0,Qt::AlignTop);
    Sell_layout->addWidget(led_Condition,0,Qt::AlignTop);
    Sell_layout->addWidget(lbl_SaleFinalPrice,0,Qt::AlignTop);
    Sell_layout->addWidget(led_SaleFinalPrice,0,Qt::AlignTop);


    SellAndRent_layout->addLayout(Sell_layout,Qt::AlignTop);

    led_SaleCommission->hide();
    led_Condition->hide();
    led_SaleCommission->hide();
    lbl_SaleCommission ->hide();
    lbl_SalesTerms ->hide();
    lbl_Condition ->hide();
    lbl_SaleFinalPrice->hide();
    led_SaleFinalPrice->hide();
    //led_MortgageDuration->setText(QString::number(r->mortgage_price()));
    lbl_VillaPicture = new QLabel;
    //////////
    lbl_VillaPicture->setFixedSize(280,165);
    label_Address->setFixedWidth(200);

    lbl_SaleCommission->setFixedWidth(200);
    /// ///////

    QVBoxLayout *tmp = new QVBoxLayout;

    tmp->addWidget(lbl_VillaPicture);
    QHBoxLayout *tmp_h = new QHBoxLayout;
    tmp_h->addWidget(btn_Buy);
    tmp_h->addWidget(btn_Rent);

    tmp->addWidget(btn_Edit);
    tmp->addWidget(btn_Save);
    tmp->addLayout(tmp_h);

    my_h_layout = new QHBoxLayout;

    my_h_layout->addLayout(tmp,Qt::AlignBottom);
    my_h_layout->addLayout(my_v_layout);
    my_h_layout->addLayout(SellAndRent_layout);
    this->setLayout(my_h_layout);

    this->setStyleSheet("QLineEdit{border: white 1px;font-size: 14px}");
    this->setStyleSheet("QLabel{font: bold;font-size: 12px; }");

    lbl_RentalTerms->setStyleSheet("font: bold;font-size: 12px;color:#16a085");
    lbl_SalesTerms->setStyleSheet("font: bold;font-size: 12px; color:green");;

    btn_Edit->setStyleSheet("QPushButton:pressed {background-color: #0D47A1;color:#3498db;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#3498db;color:#0D47A1;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif;margin-top:20px} ");
    btn_Save->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} ");
    btn_Buy->setStyleSheet("QPushButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QPushButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;} ");
    btn_Rent->setStyleSheet("QPushButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QPushButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;} ");

    /////////////
    connect(btn_Edit,SIGNAL(clicked()),this ,SLOT(EditClicked()) );
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


void NorthVilla_Details_UI::AdminMode()
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

void NorthVilla_Details_UI::UserMode()
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

void NorthVilla_Details_UI::SaleMode()
{
    if(!IsRentMode)
        led_SaleFinalPrice->setStyleSheet("margin-bottom: 170px;");
    led_SaleCommission->show();
    led_Condition->show();
    lbl_SaleCommission->show();
    lbl_SalesTerms->show();
    lbl_Condition ->show();
    lbl_SaleFinalPrice->show();
    led_SaleFinalPrice->show();
}

void NorthVilla_Details_UI::RentMode()
{
    IsRentMode = true;
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

void NorthVilla_Details_UI::EditClicked()
{
    btn_Buy->hide();
    btn_Rent->hide();
    btn_Edit->hide();
    btn_Save->show();
}
