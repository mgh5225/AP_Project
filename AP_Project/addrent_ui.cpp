#include "addrent_ui.h"

AddRent_UI::AddRent_UI(QWidget *parent) : QDialog(parent)
{    

    led_Commission = new QLineEdit;
    led_Commission->setPlaceholderText(tr("Default Commission Is : 50000"));
    led_RentAmount = new QLineEdit;
    led_RentAmount->setPlaceholderText(tr("Rent Amount"));
    led_RentDuration = new QLineEdit;
    led_RentDuration->setPlaceholderText(tr("Rent Duration"));
    led_MortgageDuration = new QLineEdit;
    led_MortgageDuration->setPlaceholderText(tr("Mortgage Duration"));

    btn_Ok = new QPushButton(tr("Ok"));
    btn_Cancel = new QPushButton(tr("Cancel"));

    my_h_layout = new QHBoxLayout;
    my_h_layout->addWidget(btn_Ok);
    my_h_layout->addWidget(btn_Cancel);
    my_v_layout = new QVBoxLayout;
    my_v_layout->addWidget(led_Commission);
    my_v_layout->addWidget(led_RentAmount);
    my_v_layout->addWidget(led_RentDuration);
    my_v_layout->addWidget(led_MortgageDuration);
    my_v_layout->addLayout(my_h_layout);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(my_v_layout);
    connect(btn_Cancel,SIGNAL(clicked()),this,SLOT(close()));
}
