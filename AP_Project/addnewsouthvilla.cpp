#include "addnewsouthvilla.h"
#include "headers.h"
AddNewSouthVilla::AddNewSouthVilla(manager& mgr,QWidget *parent) : mgr(mgr),QWidget(parent)
{
    label_BuildArea  = new QLabel(tr("Build Area"));
    label_YardArea  = new QLabel(tr("Yard Area"));
    label_ParkingArea  = new QLabel(tr("Parking Area"));
    label_BuildingPicture  = new QLabel(tr("Building Picture"));
    label_FullArea = new QLabel(tr("Full Area"));
    label_NumberOfRooms = new QLabel(tr("Number Of Rooms"));
    label_BasePrice = new QLabel(tr("Base Price"));
    label_Address = new QLabel(tr("Address"));
    labelDragAndDrop = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));

    lineEdit_BuildArea = new QLineEdit;
    lineEdit_YardArea = new QLineEdit;
    lineEdit_ParkingArea = new QLineEdit;
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
    my_grid_layout->addWidget(label_ParkingArea,3,1);
    my_grid_layout->addWidget(lineEdit_ParkingArea,4,1);
    my_grid_layout->addWidget(label_YardArea,5,1);
    my_grid_layout->addWidget(lineEdit_YardArea,6,1);
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
    lineEdit_YardArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_BasePrice->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_BuildArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEdit_ParkingArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
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
    setAcceptDrops(true);

    this->setLayout(temp);

    connect(rbtn_rent,SIGNAL(clicked( bool )),this,SLOT(RentClicked()));
    connect(rbtn_sale,SIGNAL(clicked( bool )),this,SLOT(SaleClicked()));
    connect(rbtn_both,SIGNAL(clicked( bool )),this,SLOT(BothClicked()));
    connect(btn_Add,SIGNAL(clicked()),this,SLOT(AddClicked()));
    connect(btn_Cancel,SIGNAL(clicked()),this,SLOT(close()));

}

void AddNewSouthVilla::RentClicked()
{
        rent_input= new AddRent_UI();

        //myFinalLayOut->addWidget(t);
        rent_input->exec();
        rent_input->setModal(true);
}

void AddNewSouthVilla::SaleClicked()
{
   sale_input = new AddSale_UI();
    sale_input->exec();
    sale_input->setModal(true);
}

void AddNewSouthVilla::BothClicked()
{
    rent_input = new AddRent_UI();

    rent_input->exec();

    sale_input= new AddSale_UI();
    sale_input->exec();
    sale_input->setModal(true);
    rent_input->setModal(true);
}

void AddNewSouthVilla::AddClicked()
{
    south_villa n(lineEdit_BasePrice->text().toDouble(),lineEdit_FullArea->text().toLongLong(),lineEdit_Address->text(),fileName,lineEdit_NumberOfRooms->text().toInt(),lineEdit_BuildArea->text().toLongLong(),lineEdit_YardArea->text().toLongLong(),lineEdit_ParkingArea->text().toLongLong());
    svillas[n.get_id()]=n;
    QJsonObject j;
    n.write(j);
    svillasjson[n.get_id()]=j;
    if(rbtn_sale->isChecked()){
        sale_file s(sale_input->get_com().toDouble(),mgr.get_id(),&n,sale_input->get_con());
        sales[n.get_id()]=s;
        QJsonObject j2;
        s.write(j2);
        salesjson[n.get_id()]=j2;
    }
    else if(rbtn_rent->isChecked()){
        rent_file r(rent_input->get_com(),mgr.get_id(),&n,rent_input->get_dur());
        rents[n.get_id()]=r;
        QJsonObject j3;
        r.write(j3);
        rentsjson[n.get_id()]=j3;
    }
    else if(rbtn_both->isChecked()){
        sale_file s(sale_input->get_com().toDouble(),mgr.get_id(),&n,sale_input->get_con());
        sales[n.get_id()]=s;
        QJsonObject j2;
        s.write(j2);
        salesjson[n.get_id()]=j2;
        rent_file r(rent_input->get_com(),mgr.get_id(),&n,rent_input->get_dur());
        rents[n.get_id()]=r;
        QJsonObject j3;
        r.write(j3);
        rentsjson[n.get_id()]=j3;
    }
    else {
     QMessageBox msg;
     msg.setText("Please choose a condition!");
     msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     msg.exec();
     return;
    }
    close();
}
void AddNewSouthVilla::dragEnterEvent(QDragEnterEvent *e)
{

    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void AddNewSouthVilla::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
    }
    labelDragAndDrop->setPixmap(QPixmap(fileName).scaled(350,150));


}
