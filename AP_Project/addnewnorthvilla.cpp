#include "addnewnorthvilla.h"

AddNewNorthVilla::AddNewNorthVilla(QWidget *parent) : QWidget(parent)
{
    label_BuildArea  = new QLabel(tr("Build Area"));
    label_FrontYardArea  = new QLabel(tr("Front yard Area"));
    label_BackyardArea  = new QLabel(tr("Back yard Area"));
    label_BuildingPicture  = new QLabel(tr("Building Picture"));
    label_FullArea = new QLabel(tr("Full Area"));
    label_NumberOfRooms = new QLabel(tr("Number Of Rooms"));
    label_BasePrice = new QLabel(tr("Base Price"));
    label_Address = new QLabel(tr("Address"));
    labelDragAndDrop = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));

    lineEdit_BuildArea = new QLineEdit;
    lineEdit_FrontYardArea = new QLineEdit;
    lineEdit_BackYardArea = new QLineEdit;
    lineEdit_FullArea = new QLineEdit;
    lineEdit_NumberOfRooms = new QLineEdit;
    lineEdit_BasePrice = new QLineEdit;
    lineEdit_Address = new QLineEdit;

    btn_Add = new QPushButton(tr("Add"));
    btn_Cancel = new QPushButton(tr("Cancel"));

    QHBoxLayout *tmp_H2 = new QHBoxLayout;
    QLabel *labelFor = new QLabel("For");
    rbtn_both= new QRadioButton(tr("Both"));
    rbtn_rent= new QRadioButton(tr("Rent"));
    rbtn_sale= new QRadioButton(tr("Sale"));
    tmp_H2->addWidget(rbtn_sale);
    tmp_H2->addWidget(rbtn_rent);
    tmp_H2->addWidget(rbtn_both);


    my_grid_layout = new QGridLayout();

    my_grid_layout->addWidget(label_BuildArea,1,1);
    my_grid_layout->addWidget(lineEdit_BuildArea,2,1);
    my_grid_layout->addWidget(label_BackyardArea,3,1);
    my_grid_layout->addWidget(lineEdit_BackYardArea,4,1);
    my_grid_layout->addWidget(label_FrontYardArea,5,1);
    my_grid_layout->addWidget(lineEdit_FrontYardArea,6,1);
    my_grid_layout->addWidget(label_FullArea,7,1);
    my_grid_layout->addWidget(lineEdit_FullArea,8,1,Qt::AlignTop);
    my_grid_layout->addWidget(labelFor,9,1);
    my_grid_layout->addLayout(tmp_H2,10,1,Qt::AlignTop);
    my_grid_layout->addWidget(btn_Cancel,11,1,Qt::AlignTop);



    my_grid_layout->addWidget(label_Address,1,0);
    my_grid_layout->addWidget(lineEdit_Address,2,0);
    my_grid_layout->addWidget(label_BasePrice,3,0);
    my_grid_layout->addWidget(lineEdit_BasePrice,4,0);
    my_grid_layout->addWidget(label_NumberOfRooms,5,0);
    my_grid_layout->addWidget(lineEdit_NumberOfRooms,6,0);
    my_grid_layout->addWidget(label_BuildingPicture,7,0);
    my_grid_layout->addWidget(labelDragAndDrop,8,0,3,1);
    my_grid_layout->addWidget(btn_Add,11,0);


    lineEdit_Address->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_FullArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_FrontYardArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_BasePrice->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_BuildArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_BackYardArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_NumberOfRooms->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    btn_Add->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} ");
    btn_Cancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");



    labelDragAndDrop->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    labelDragAndDrop->setFixedSize(350,150);
    label_Address->setFixedWidth(200);
    label_BuildArea->setFixedWidth(350);

    QFrame *myFrame = new QFrame();
    myFrame->setLayout(my_grid_layout);
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


    connect(btn_Cancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(rbtn_rent,SIGNAL(clicked( bool )),this,SLOT(RentClicked()));
    connect(rbtn_sale,SIGNAL(clicked( bool )),this,SLOT(SaleClicked()));
    connect(rbtn_both,SIGNAL(clicked( bool )),this,SLOT(BothClicked()));

}


void AddNewNorthVilla::RentClicked()
{
    qDebug() << "hi";
        AddRent_UI *t = new AddRent_UI();

        //myFinalLayOut->addWidget(t);
        t->exec();
        t->setModal(true);
}

void AddNewNorthVilla::SaleClicked()
{
    AddSale_UI *s = new AddSale_UI();
    s->exec();
    s->setModal(true);
}

void AddNewNorthVilla::BothClicked()
{
    AddRent_UI *t = new AddRent_UI();

    t->exec();

    AddSale_UI *s = new AddSale_UI();
    s->exec();
    s->setModal(true);
    t->setModal(true);
}

