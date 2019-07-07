#include "addsale_ui.h"

AddSale_UI::AddSale_UI(QWidget *parent) : QDialog(parent)
{
    led_Commission = new QLineEdit;
    led_Commission->setPlaceholderText(tr("Default Commission Is : 50000"));
    combobox_Condition = new QComboBox;
    combobox_Condition->addItem("Cash");
    combobox_Condition->addItem("cheque");

    btn_Ok = new QPushButton(tr("Ok"));
    btn_Cancel = new QPushButton(tr("Cancel"));

    my_h_layout = new QHBoxLayout;
    my_h_layout->addWidget(btn_Ok);
    my_h_layout->addWidget(btn_Cancel);
    my_v_layout = new QVBoxLayout;
    my_v_layout->addWidget(led_Commission);
    my_v_layout->addWidget(combobox_Condition);
    my_v_layout->addLayout(my_h_layout);
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setLayout(my_v_layout);

    connect(btn_Cancel,SIGNAL(clicked()),this,SLOT(close()));
}
