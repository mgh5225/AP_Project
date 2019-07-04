#include "login.h"




Login::Login(QWidget *parent) : QWidget(nullptr)
{
    this->parent=parent;
    labelUsername = new QLabel(tr("Username"));
    labelPassword = new QLabel(tr("Password"));
    labelType = new QLabel(tr("Login As a:"));
    //userPicture = new QLabel;

    pushButtonLogin = new QPushButton(tr("Log in"));
    pushButtonCancel = new QPushButton(tr("Cancel"));

    lineEditUsername = new QLineEdit;

    lineEditPassword = new QLineEdit;
    lineEditPassword->setEchoMode(QLineEdit::Password);

    radioUser=new QRadioButton("User");
    radioUser->setChecked(true);
    radioManager=new QRadioButton("Manager");

    checkBoxShowPassword = new QCheckBox(tr("Show"));

    //LayOut

    myVLayout = new QVBoxLayout;

    myHLayout = new QHBoxLayout;

    typeHLayout=new QHBoxLayout;

    myFrame= new QFrame;

    myHLayout->addWidget(labelPassword,0,Qt::AlignLeft);
    myHLayout->addWidget(checkBoxShowPassword,0,Qt::AlignRight);

    //myVLayout->addWidget(userPicture);
    myVLayout->addWidget(labelUsername);
    myVLayout->addWidget(lineEditUsername);
    myVLayout->addLayout(myHLayout);
    myVLayout->addWidget(lineEditPassword);
    myVLayout->addLayout(typeHLayout);
    myVLayout->addWidget(pushButtonLogin);
    myVLayout->addWidget(pushButtonCancel);

    typeHLayout->addWidget(labelType);
    typeHLayout->addWidget(radioUser);
    typeHLayout->addWidget(radioManager);

    //fixed size??
    //myVLayout->setSizeConstraint(QLayout::SetFixedSize);

    //css
    pushButtonLogin->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} ");
    pushButtonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");

    labelType->setStyleSheet("margin-top:15px");
    radioUser->setStyleSheet("margin-top:15px");
    radioManager->setStyleSheet("margin-top:15px");

    //this->setStyleSheet("background-color:#f2f2f2;");

    myFrame->setLayout(myVLayout);
    myFrame->setStyleSheet("background-color:white;border-radius: 5px;");
    lineEditUsername->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditPassword->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");

    //set icon
    const QIcon iconUsername(":/icons/resource/icons/User_Login.png");
    lineEditUsername->setClearButtonEnabled(true);
    lineEditUsername->addAction(iconUsername,QLineEdit::LeadingPosition);

    const QIcon iconPassword(":/icons/resource/icons/Password_Login.png");
    lineEditPassword->setClearButtonEnabled(true);
    lineEditPassword->addAction(iconPassword,QLineEdit::LeadingPosition);


    //set frame
    QVBoxLayout * temp = new QVBoxLayout;
    temp->addWidget(myFrame);
    /////////////////////////////////////
    // round window!!
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////
     this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setLayout(temp);






    //func

    connect(checkBoxShowPassword,SIGNAL(clicked(bool)),this,SLOT(setPasswordEchoMode(bool)));
    connect(pushButtonCancel,SIGNAL(clicked()),this,SLOT(custom_close()));

}


//func

void Login::custom_close(){
    hide();
    parent->show();
}




void Login::setPasswordEchoMode(bool checked)
{
    if(checked){
        lineEditPassword->setEchoMode(QLineEdit::Normal);
    }else{
        lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}
