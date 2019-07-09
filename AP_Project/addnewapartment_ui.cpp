#include "addnewapartment_ui.h"
#include <QDebug>
#include "headers.h"
#include <QGroupBox>
AddNewApartment_UI::AddNewApartment_UI(manager& mgr,QWidget *parent) : mgr(mgr),QWidget(parent)
{

    //new things

    lineEditAddress = new QLineEdit;
    lineEditBasePrice = new QLineEdit;
    lineEditNumberOfUnits = new QLineEdit;
    lineEditApartmentArea = new QLineEdit;
    lineEditNumberOfFloors = new QLineEdit;
    lineEditUnitArea = new QLineEdit;
    lineEditUnitFloorNumber = new QComboBox;
    lineEditUnitNumberOfRooms = new QLineEdit;

    comboBoxWhichUnit = new QComboBox;

    labelAddress = new QLabel(tr("Address"));
    labeNumberOfUnits = new QLabel(tr("Unit Number"));
    labelBasePrice = new QLabel(tr("Base Price"));
    labelApartmentArea = new QLabel(tr("Apartment Area"));
    labelNumberOfFloors = new QLabel(tr("Number Of Floors"));
    labelApartmentPicture = new QLabel(tr("Apartment Picture"));
    labelDragAndDrop = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));
    labelWhichUnit = new QLabel(tr("Which Unit?"));
    labelUnitArea = new QLabel(tr("Unit Area"));
    labelUnitPicture = new QLabel(tr("Unit Picture"));
    labelUnitFloorNumber = new QLabel(tr("Floor Number"));
    labelUnitNumberOfRooms = new QLabel(tr("Number Of Rooms"));
    labeDragAndDropUnits = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));

    pushBottonAdd = new QPushButton(tr("Add"));
    pushBottonCancel = new QPushButton(tr("Cancel"));

    myFirstVBoxLayOut = new QVBoxLayout();
    mySecondVBoxLayOut = new QVBoxLayout();


    QHBoxLayout *tmp_H = new QHBoxLayout;
    rbtn_Normal = new QRadioButton(tr("Normal"));
    rbtn_Official= new QRadioButton(tr("Official"));
    rbtn_Commercial= new QRadioButton(tr("Commercial"));
    labelApplication = new QLabel(tr("Application"));
    tmp_H->addWidget(rbtn_Normal);
    tmp_H->addWidget(rbtn_Official);
    tmp_H->addWidget(rbtn_Commercial);





    //////


    //////

    myHBoxLayOutBotton = new QHBoxLayout();
    myFinalLayOut = new QGridLayout();

    myFrame = new QFrame;

    labelElevator = new QLabel("Elevator");
    comboBoxElevator = new QComboBox();
    comboBoxElevator->addItem(tr("Yes"));
    comboBoxElevator->addItem(tr("No"));


    //drag and drops





    //set layouts

    //set first layout
    //myFirstVBoxLayOut->addWidget(setSizeOfFirstHboxLayout);
    myFirstVBoxLayOut->addWidget(labelApartmentArea,0,Qt::AlignTop);
    myFirstVBoxLayOut->addWidget(lineEditApartmentArea);
    myFirstVBoxLayOut->addWidget(labelBasePrice);
    myFirstVBoxLayOut->addWidget(lineEditBasePrice);
    myFirstVBoxLayOut->addWidget(labelNumberOfFloors);
    myFirstVBoxLayOut->addWidget(lineEditNumberOfFloors);
    myFirstVBoxLayOut->addWidget(labelAddress);
    myFirstVBoxLayOut->addWidget(lineEditAddress);
    myFirstVBoxLayOut->addWidget(labeNumberOfUnits);
    myFirstVBoxLayOut->addWidget(lineEditNumberOfUnits);
    myFirstVBoxLayOut->addWidget(labelApplication);
    myFirstVBoxLayOut->addLayout(tmp_H);
    myFirstVBoxLayOut->addWidget(labelApartmentPicture);
    myFirstVBoxLayOut->addWidget(labelDragAndDrop);

    //setSizeOfFirstHboxLayout->setFixedSize(140,0);


    //set secont layout

    mySecondVBoxLayOut->addWidget(labelWhichUnit);
    mySecondVBoxLayOut->addWidget(comboBoxWhichUnit);
    mySecondVBoxLayOut->addWidget(labelElevator);
    mySecondVBoxLayOut->addWidget(comboBoxElevator);
    mySecondVBoxLayOut->addWidget(labelUnitArea              );
    mySecondVBoxLayOut->addWidget(lineEditUnitArea           );
    mySecondVBoxLayOut->addWidget(labelUnitFloorNumber       );
    mySecondVBoxLayOut->addWidget(lineEditUnitFloorNumber     );
    mySecondVBoxLayOut->addWidget(labelUnitNumberOfRooms      );
    mySecondVBoxLayOut->addWidget(lineEditUnitNumberOfRooms   );
    mySecondVBoxLayOut->addWidget(labelUnitPicture          );
    mySecondVBoxLayOut->addWidget(labeDragAndDropUnits           );
    labelWhichUnit -> hide();
    comboBoxWhichUnit-> hide();
    labelElevator-> hide();
    comboBoxElevator-> hide();
    labelUnitArea            -> hide();
    lineEditUnitArea         -> hide();
    labelUnitFloorNumber     -> hide();
    lineEditUnitFloorNumber  -> hide();
    labelUnitNumberOfRooms   -> hide();
    lineEditUnitNumberOfRooms-> hide();
    labelUnitPicture         -> hide();
    labeDragAndDropUnits     -> hide();

    //set h boton
    myHBoxLayOutBotton->addWidget(pushBottonAdd);
    myHBoxLayOutBotton->addWidget(pushBottonCancel);




    //set h hox layout

    myFinalLayOut->addLayout(mySecondVBoxLayOut,0,0);
    myFinalLayOut->addLayout(myFirstVBoxLayOut,0,1);
    myFinalLayOut->addLayout(myHBoxLayOutBotton,1,0,1,2);


    //set frame
    myFrame->setLayout(myFinalLayOut);
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

    //css
    lineEditAddress->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditBasePrice->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditApartmentArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditNumberOfUnits->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditNumberOfFloors->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    lineEditUnitArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditUnitFloorNumber->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditUnitNumberOfRooms->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    comboBoxWhichUnit->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    comboBoxElevator->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    labelDragAndDrop->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    labeDragAndDropUnits->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");


    pushBottonAdd->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} ");
    pushBottonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");



    //func
    //labelApartmentPicture->setFixedSize(200,10);
    labelAddress->setFixedWidth(200);
    labelDragAndDrop->setFixedSize(350,150);
    labeDragAndDropUnits->setFixedSize(350,150);

    checkp=true;
setAcceptDrops(true);
    connect(lineEditNumberOfUnits,SIGNAL(textChanged(QString)),this,SLOT(ChangeFrame(QString)));
    connect(pushBottonCancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(pushBottonAdd,SIGNAL(clicked()),this,SLOT(AddClicked()));
}

AddNewApartment_UI::AddNewApartment_UI(manager& mgr,apartment &aptr, QWidget *parent):mgr(mgr)
{
    aptr_p=new apartment;
    aptr_p=&aptr;
    lineEditAddress = new QLineEdit;
    lineEditBasePrice = new QLineEdit;
    lineEditNumberOfUnits = new QLineEdit;
    lineEditApartmentArea = new QLineEdit;
    lineEditNumberOfFloors = new QLineEdit;
    lineEditUnitArea = new QLineEdit;
    lineEditUnitFloorNumber = new QComboBox;
    lineEditUnitNumberOfRooms = new QLineEdit;



    comboBoxWhichUnit = new QComboBox;

    labelAddress = new QLabel(tr("Address"));
    labeNumberOfUnits = new QLabel(tr("Unit Number"));
    labelBasePrice = new QLabel(tr("Base Price"));
    labelApartmentArea = new QLabel(tr("Apartment Area"));
    labelNumberOfFloors = new QLabel(tr("Number Of Floors"));
    labelApartmentPicture = new QLabel(tr("Apartment Picture"));
    labelDragAndDrop = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));
    labelWhichUnit = new QLabel(tr("Which Unit?"));
    labelUnitArea = new QLabel(tr("Unit Area"));
    labelUnitPicture = new QLabel(tr("Unit Picture"));
    labelUnitFloorNumber = new QLabel(tr("Floor Number"));
    labelUnitNumberOfRooms = new QLabel(tr("Number Of Rooms"));
    labeDragAndDropUnits = new QLabel(tr("Please Drag And Drop your Image\nOr\nClick here for explore!"));

    pushButtonAddFlat = new QPushButton(tr("Add"));
    pushBottonCancel = new QPushButton(tr("Cancel"));

    myFirstVBoxLayOut = new QVBoxLayout();
    mySecondVBoxLayOut = new QVBoxLayout();


    QHBoxLayout *tmp_H = new QHBoxLayout;
    rbtn_Normal = new QRadioButton(tr("Normal"));
    rbtn_Official= new QRadioButton(tr("Official"));
    rbtn_Commercial= new QRadioButton(tr("Commercial"));
    labelApplication = new QLabel(tr("Application"));
    tmp_H->addWidget(rbtn_Normal);
    tmp_H->addWidget(rbtn_Official);
    tmp_H->addWidget(rbtn_Commercial);
    QGroupBox* gb=new QGroupBox;
    gb->setLayout(tmp_H);

    QHBoxLayout *tmp_H2 = new QHBoxLayout;
    QLabel *labelFor = new QLabel("For");
    rbtn_both= new QRadioButton(tr("Both"));
    rbtn_rent= new QRadioButton(tr("Rent"));
    rbtn_sale= new QRadioButton(tr("Sale"));
    tmp_H2->addWidget(rbtn_sale);
    tmp_H2->addWidget(rbtn_rent);
    tmp_H2->addWidget(rbtn_both);



    //////


    //////

    myHBoxLayOutBotton = new QHBoxLayout();
    myFinalLayOut = new QGridLayout();

    myFrame = new QFrame;

    labelElevator = new QLabel("Elevator");
    comboBoxElevator = new QComboBox();
    comboBoxElevator->addItem(tr("Yes"));
    comboBoxElevator->addItem(tr("No"));
    //QString(aptr.get_base_price())


    lineEditApartmentArea->setText( QString::number(aptr.get_total_area()));
    lineEditBasePrice->setText(QString::number(aptr.get_base_price()));
    lineEditNumberOfFloors->setText(QString::number(aptr.get_floors()));
    lineEditAddress->setText(aptr.get_address());
    lineEditNumberOfUnits->setText(QString::number(aptr.get_units()));

    labelDragAndDrop->setPixmap(QPixmap(aptr.get_picture()).scaled(350,150));
    lineEditApartmentArea->setEnabled(false);
    lineEditBasePrice->setEnabled(false);;
    lineEditNumberOfFloors->setEnabled(false);
    lineEditNumberOfUnits->setEnabled(false);
    lineEditAddress->setEnabled(false);
    bool flag;
    for(int i=0;i<lineEditNumberOfUnits->text().toInt();i++){
        flag=true;
        for(int j=0;j<flats[aptr.get_id()].size();j++){
            if(flats[aptr.get_id()][j].get_unit()==i+1){
                flag=false;
                break;
            }
        }
        if(flag)comboBoxWhichUnit->addItem(QString::number(i+1));
    }
    for(int i=0;i<lineEditNumberOfFloors->text().toInt();i++){
        lineEditUnitFloorNumber->addItem(QString::number(i+1));
    }
    if(aptr.get_apply()=="Normal")rbtn_Normal->setChecked(true);
    else if(aptr.get_apply()=="Official")rbtn_Official->setChecked(true);
    else if(aptr.get_apply()=="Commercial")rbtn_Commercial->setChecked(true);
    rbtn_Normal->setEnabled(false);
    rbtn_Official->setEnabled(false);
    rbtn_Commercial->setEnabled(false);
    //drag and drops





    //set layouts

    //set first layout
    //myFirstVBoxLayOut->addWidget(setSizeOfFirstHboxLayout);
    myFirstVBoxLayOut->addWidget(labelApartmentArea,0,Qt::AlignTop);

    myFirstVBoxLayOut->addWidget(lineEditApartmentArea);
    myFirstVBoxLayOut->addWidget(labelBasePrice);
    myFirstVBoxLayOut->addWidget(lineEditBasePrice);
    myFirstVBoxLayOut->addWidget(labelNumberOfFloors);
    myFirstVBoxLayOut->addWidget(lineEditNumberOfFloors);
    myFirstVBoxLayOut->addWidget(labelAddress);
    myFirstVBoxLayOut->addWidget(lineEditAddress);
    myFirstVBoxLayOut->addWidget(labeNumberOfUnits);
    myFirstVBoxLayOut->addWidget(lineEditNumberOfUnits);
    myFirstVBoxLayOut->addWidget(labelApplication);
    myFirstVBoxLayOut->addWidget(gb);
    myFirstVBoxLayOut->addWidget(labelApartmentPicture);
    myFirstVBoxLayOut->addWidget(labelDragAndDrop);

    //setSizeOfFirstHboxLayout->setFixedSize(140,0);


    //set secont layout

    mySecondVBoxLayOut->addWidget(labelWhichUnit);
    mySecondVBoxLayOut->addWidget(comboBoxWhichUnit);
    mySecondVBoxLayOut->addWidget(labelElevator);
    mySecondVBoxLayOut->addWidget(comboBoxElevator);
    mySecondVBoxLayOut->addWidget(labelUnitArea              );
    mySecondVBoxLayOut->addWidget(lineEditUnitArea           );
    mySecondVBoxLayOut->addWidget(labelUnitFloorNumber       );
    mySecondVBoxLayOut->addWidget(lineEditUnitFloorNumber     );
    mySecondVBoxLayOut->addWidget(labelUnitNumberOfRooms      );
    mySecondVBoxLayOut->addWidget(lineEditUnitNumberOfRooms   );
    mySecondVBoxLayOut->addWidget(labelFor);
    mySecondVBoxLayOut->addLayout(tmp_H2);
    mySecondVBoxLayOut->addWidget(labelUnitPicture          );
    mySecondVBoxLayOut->addWidget(labeDragAndDropUnits           );


    //set h boton
    myHBoxLayOutBotton->addWidget(pushButtonAddFlat);
    myHBoxLayOutBotton->addWidget(pushBottonCancel);




    //set h hox layout

    myFinalLayOut->addLayout(mySecondVBoxLayOut,0,0);
    myFinalLayOut->addLayout(myFirstVBoxLayOut,0,1);
    myFinalLayOut->addLayout(myHBoxLayOutBotton,1,0,1,2);


    //set frame
    myFrame->setLayout(myFinalLayOut);
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

    //css
    lineEditAddress->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditBasePrice->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditApartmentArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditNumberOfUnits->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditNumberOfFloors->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    lineEditUnitArea->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditUnitFloorNumber->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditUnitNumberOfRooms->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    comboBoxWhichUnit->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    comboBoxElevator->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    labelDragAndDrop->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    labeDragAndDropUnits->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");


    pushButtonAddFlat->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} ");
    pushBottonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");



    //func
    //labelApartmentPicture->setFixedSize(200,10);
    labelAddress->setFixedWidth(200);
    labelDragAndDrop->setFixedSize(350,150);
    labeDragAndDropUnits->setFixedSize(350,150);

    setAcceptDrops(true);

    checkp=false;

    connect(lineEditNumberOfUnits,SIGNAL(textChanged(QString)),this,SLOT(ChangeFrame(QString)));
    connect(pushBottonCancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(rbtn_rent,SIGNAL(clicked( bool )),this,SLOT(RentClicked()));
    connect(rbtn_sale,SIGNAL(clicked( bool )),this,SLOT(SaleClicked()));
    connect(rbtn_both,SIGNAL(clicked( bool )),this,SLOT(BothClicked()));
    connect(pushButtonAddFlat,SIGNAL(clicked()),this,SLOT(AddFlatClicked()));

}


void AddNewApartment_UI::ChangeFrame(const QString &text)
{


    qDebug()<< " jjj" ;
    comboBoxWhichUnit->clear();
    for(int i=0;i<lineEditNumberOfUnits->text().toInt();i++){
        comboBoxWhichUnit->addItem(QString::number(i+1));
    }

}

void AddNewApartment_UI::RentClicked()
{
        rent_input = new AddRent_UI();

        //myFinalLayOut->addWidget(t);
        rent_input->exec();
        rent_input->setModal(true);
}

void AddNewApartment_UI::SaleClicked()
{
    sale_input= new AddSale_UI();
    sale_input->exec();
    sale_input->setModal(true);
}

void AddNewApartment_UI::BothClicked()
{
    rent_input = new AddRent_UI();

    rent_input->exec();

    sale_input = new AddSale_UI();
    sale_input->exec();
    sale_input->setModal(true);
    rent_input->setModal(true);
}

void AddNewApartment_UI::AddClicked()
{
    QString temp;
    if(rbtn_Normal->isChecked())temp="Normal";
    else if(rbtn_Official->isChecked())temp="Official";
    else if(rbtn_Commercial->isChecked())temp="Commercial";
    apartment a(lineEditBasePrice->text().toDouble(),lineEditApartmentArea->text().toLongLong(),lineEditAddress->text(),fileName,lineEditNumberOfFloors->text().toInt(),lineEditNumberOfUnits->text().toInt(),temp);
    apartments[a.get_id()]=a;
    QJsonObject j;
    a.write(j);
    apartmentsjson[a.get_id()]=j;
    close();
}

void AddNewApartment_UI::AddFlatClicked()
{
    flat *f=new flat(aptr_p,lineEditUnitFloorNumber->currentText().toInt(),!comboBoxElevator->currentIndex(),lineEditUnitNumberOfRooms->text().toInt(),lineEditUnitArea->text().toLongLong(),fileName2,comboBoxWhichUnit->currentText().toInt());
    flats[aptr_p->get_id()].push_back(*f);
    QJsonObject j;
    f->write(j);
    flatsjson[f->get_id()]=j;
    if(rbtn_sale->isChecked()){
        sale_file s(sale_input->get_com().toDouble(),mgr.get_id(),f,sale_input->get_con());
        sales[f->get_id()]=s;
        QJsonObject j2;
        s.write(j2);
        salesjson[f->get_id()]=j2;
    }
    else if(rbtn_rent->isChecked()){
        rent_file r(rent_input->get_com(),mgr.get_id(),f,rent_input->get_dur());
        rents[f->get_id()]=r;
        QJsonObject j3;
        r.write(j3);
        rentsjson[f->get_id()]=j3;
    }
    else if(rbtn_both->isChecked()){
        sale_file s(sale_input->get_com().toDouble(),mgr.get_id(),f,sale_input->get_con());
        sales[f->get_id()]=s;
        QJsonObject j2;
        s.write(j2);
        salesjson[f->get_id()]=j2;
        rent_file r(rent_input->get_com(),mgr.get_id(),f,rent_input->get_dur());
        rents[f->get_id()]=r;
        QJsonObject j3;
        r.write(j3);
        rentsjson[f->get_id()]=j3;
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


///////////setAcceptDrops(true); ////////
void AddNewApartment_UI::dragEnterEvent(QDragEnterEvent *e)
{

    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void AddNewApartment_UI::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        fileName = url.toLocalFile();
        fileName2 =  url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
    }
    if(checkp) labelDragAndDrop->setPixmap(QPixmap(fileName).scaled(350,150));
    else labeDragAndDropUnits->setPixmap(QPixmap(fileName2).scaled(350,150));


}





