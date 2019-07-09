#include "editpanel_ui.h"
/////you need to remove this!
#include "headers.h"
///
EditPanel_UI::EditPanel_UI(QWidget *parent) : QWidget(parent)
{
    LineEditUsername = new QLineEdit();
    LineEditBalance = new QLineEdit();
    LineEditPassword = new QLineEdit();
    LineEditFullName = new QLineEdit();

    LabelBalance = new QLabel("Balance");
    LabelFullName= new QLabel("Full Name");
    LabelPassword= new QLabel("Password");
    LabelUsername= new QLabel("Username");



    //////////////////You need Too Fill this shit!//////////////////////
    //person* s;
//
//    LineEditUsername->setText(s->get_user());
//    LineEditFullName->setText("poresh kon bayad get benevise!");
//    LineEditBalance->setText(QString::number(s->get_balance()));
//    LineEditPassword->setText("********");
//
    ////////////////////////////////////////////////////////////////
    PushButtonSave = new QPushButton("Save");
    PushButtonCancel = new QPushButton("Cancel");

    QLabel *LabelDate = new QLabel("Brith Day Date");
    DateEditBirthDay = new QDateEdit;
    DateEditBirthDay->setCalendarPopup(true);

    LayoutVAll = new QVBoxLayout;

    LayoutVAll->addWidget(LabelUsername);
    LayoutVAll->addWidget(LineEditUsername);
    LayoutVAll->addWidget(LabelPassword);
    LayoutVAll->addWidget(LineEditPassword);
    LayoutVAll->addWidget(LabelFullName);
    LayoutVAll->addWidget(LineEditFullName);
    LayoutVAll->addWidget(LabelBalance);
    LayoutVAll->addWidget(LineEditBalance);
    LayoutVAll->addWidget(LabelDate);
    LayoutVAll->addWidget(DateEditBirthDay);

    QHBoxLayout *LayoutButton = new QHBoxLayout;
    LayoutButton->addWidget(PushButtonSave);
    LayoutButton->addWidget(PushButtonCancel);


    LayoutVAll->addLayout(LayoutButton);


    LineEditBalance->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    LineEditFullName->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    LineEditPassword->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    LineEditUsername->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    PushButtonSave->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif}");
    PushButtonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");

    DateEditBirthDay->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    this->setLayout(LayoutVAll);

}
