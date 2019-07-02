#include "register_ui.h"

Register_UI::Register_UI(QWidget *parent) : QWidget(parent)
{
    labelUsername = new QLabel(tr("Username"));
    labelPassword = new QLabel(tr("Password"));
    labelFullName = new QLabel(tr("Full Name"));
    labelBirthday = new QLabel(tr("Birthday"));
    //userPicture = new QLabel;


    pushButtonRegister = new QPushButton(tr("Register"));
    pushButtonCancel = new QPushButton(tr("Cancel"));

    lineEditUsername = new QLineEdit;
    lineEditPassword = new QLineEdit;
    lineEditPassword->setEchoMode(QLineEdit::Password);
    lineEditFullName = new QLineEdit;

    checkBoxShowPassword = new QCheckBox(tr("Show"));

    dateEditBirthday = new QDateEdit;
    dateEditBirthday->setCalendarPopup(true);


    //LayOut

    myVLayout = new QVBoxLayout;

    myHLayout = new QHBoxLayout;

    myFrame= new QFrame;

    myHLayout->addWidget(labelPassword,0,Qt::AlignLeft);
    myHLayout->addWidget(checkBoxShowPassword,0,Qt::AlignRight);

    myVLayout->addWidget(labelUsername);
    myVLayout->addWidget(lineEditUsername);
    myVLayout->addLayout(myHLayout);
    myVLayout->addWidget(lineEditPassword);
    myVLayout->addWidget(labelFullName);
    myVLayout->addWidget(lineEditFullName);
    myVLayout->addWidget(labelBirthday);
    myVLayout->addWidget(dateEditBirthday);
    myVLayout->addWidget(pushButtonRegister);
    myVLayout->addWidget(pushButtonCancel);

    //css
    pushButtonRegister->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} ");
    pushButtonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");

    this->setStyleSheet("background-color:#f2f2f2;");

    myFrame->setLayout(myVLayout);
    myFrame->setStyleSheet("background-color:white;border-radius: 5px;");
    lineEditUsername->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditPassword->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditFullName->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");


    dateEditBirthday->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    //set icon
    const QIcon iconUsername(":/icons/resource/icons/User_Login.png");
    lineEditUsername->setClearButtonEnabled(true);
    lineEditUsername->addAction(iconUsername,QLineEdit::LeadingPosition);

    const QIcon iconPassword(":/icons/resource/icons/Password_Login.png");
    lineEditPassword->setClearButtonEnabled(true);
    lineEditPassword->addAction(iconPassword,QLineEdit::LeadingPosition);

    const QIcon iconFullName(":/icons/resource/icons/Register_FullName.png");
    lineEditFullName->setClearButtonEnabled(true);
    lineEditFullName->addAction(iconFullName,QLineEdit::LeadingPosition);



    //set frame
    QVBoxLayout * temp = new QVBoxLayout;
    temp->addWidget(myFrame);
    /////////////////////////////////////
    // round window!!
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////


    this->setLayout(temp);






    //func

    connect(checkBoxShowPassword,SIGNAL(clicked(bool)),this,SLOT(setPasswordEchoMode(bool)));
    connect(pushButtonCancel,SIGNAL(clicked()),this,SLOT(close()));

}


void Register_UI::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Register_UI::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}


void Register_UI::setPasswordEchoMode(bool checked)
{
    if(checked){
        lineEditPassword->setEchoMode(QLineEdit::Normal);
    }else{
        lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}
