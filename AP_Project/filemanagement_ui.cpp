#include "filemanagement_ui.h"

FileManagement_UI::FileManagement_UI(manager& mgr,QWidget *parent) : mgr(mgr),QWidget(parent)
{
    PushButtonRequests = new QPushButton(tr("Requests"));
    PushButtonRentsFile = new QPushButton(tr("Rent Files"));
    PushButtonSalesFile = new QPushButton(tr("Sale Files"));

    GridLayoutButtons = new QGridLayout;
    GridLayoutButtons ->addWidget(PushButtonSalesFile,0,0);
    GridLayoutButtons->addWidget(PushButtonRentsFile,0,1);
    GridLayoutButtons->addWidget(PushButtonRequests,1,0,1,2);

    PushButtonRequests->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    PushButtonRentsFile->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    PushButtonSalesFile->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );

    Requests = nullptr;
    sales=nullptr;
    rents=nullptr;
    this->setStyleSheet("QPushButton:hover{ background-color: #91a0a1; color: wihte;border-radius: 5px;}QPushButton{border:0px;border-radius: 5px;background-color: #34495e;color:white;padding:40px ;text-align:center}");
    this->setLayout(GridLayoutButtons);
    connect(PushButtonRequests,SIGNAL(clicked()),this,SLOT(PushButtonRequestsClicked()));

}

void FileManagement_UI::PushButtonRequestsClicked()
{
    Requests = new Requests_Ui(mgr,this);
    PushButtonRequests->hide();
    PushButtonRentsFile->hide();
    PushButtonSalesFile->hide();
    GridLayoutButtons->addWidget(Requests,0,0);
}
