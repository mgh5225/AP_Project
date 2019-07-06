#include "register_ui.h"
#include "headers.h"

Register_UI::Register_UI(QWidget *parent) : QWidget(nullptr)
{
    this->parent=parent;
    labelUsername = new QLabel(tr("Username"));
    labelPassword = new QLabel(tr("Password"));
    labelFullName = new QLabel(tr("Full Name"));
    labelBirthday = new QLabel(tr("Birthday"));
    labelType = new QLabel(tr("Register As a:"));
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

    radioUser=new QRadioButton("User");
    radioUser->setChecked(true);
    radioManager=new QRadioButton("Manager");

    //LayOut

    myVLayout = new QVBoxLayout;

    myHLayout = new QHBoxLayout;

    typeHLayout=new QHBoxLayout;

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
    myVLayout->addLayout(typeHLayout);
    myVLayout->addWidget(pushButtonRegister);
    myVLayout->addWidget(pushButtonCancel);

    typeHLayout->addWidget(labelType);
    typeHLayout->addWidget(radioUser);
    typeHLayout->addWidget(radioManager);

    //css
    pushButtonRegister->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;margin-top:20px} ");
    pushButtonCancel->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");

    this->setStyleSheet("background-color:#f2f2f2;");

    myFrame->setLayout(myVLayout);
    myFrame->setStyleSheet("background-color:white;border-radius: 5px;");
    lineEditUsername->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditPassword->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");
    lineEditFullName->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif ");


    dateEditBirthday->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif;");
    labelType->setStyleSheet("margin-top:15px");
    radioUser->setStyleSheet("margin-top:15px");
    radioManager->setStyleSheet("margin-top:15px");

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

     this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setLayout(temp);


    pushButtonRegister->setEnabled(false);
    lineEditPassword->setEnabled(false);



    //func

    connect(checkBoxShowPassword,SIGNAL(clicked(bool)),this,SLOT(setPasswordEchoMode(bool)));
    connect(lineEditUsername,SIGNAL(textChanged(QString)),this,SLOT(lineEdit_Username_changed(QString)));
    connect(lineEditPassword,SIGNAL(textChanged(QString)),this,SLOT(lineEdit_Password_changed(QString)));
    connect(pushButtonCancel,SIGNAL(clicked()),this,SLOT(custom_close()));
    connect(pushButtonRegister,SIGNAL(clicked()),this,SLOT(on_btn_register_clicked()));

}
void Register_UI::custom_close(){
    hide();
    parent->show();
}

void Register_UI::lineEdit_Username_changed(QString s)
{
    if(s.size()!=0){
        lineEditPassword->setEnabled(true);
    }else{
        lineEditPassword->setEnabled(false);
        pushButtonRegister->setEnabled(false);
    }
}

void Register_UI::lineEdit_Password_changed(QString s)
{
    if(s.size()!=0){
        pushButtonRegister->setEnabled(true);
    }else{
        pushButtonRegister->setEnabled(false);
    }
}




void Register_UI::setPasswordEchoMode(bool checked)
{
    if(checked){
        lineEditPassword->setEchoMode(QLineEdit::Normal);
    }else{
        lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}
void Register_UI::on_btn_register_clicked()
{
    bool isUser=radioUser->isChecked();
    bool isRegistered;
    QString date=dateEditBirthday->text();
    date.replace("/"," ");
    QTextStream stream(&date);
    tm t;
    QString year;
    QString month;
    QString day;
    stream>>month>>day>>year;
    t.tm_year=year.toInt();
    t.tm_mon=month.toInt();
    t.tm_mday=day.toInt();
    if(isUser){
        isRegistered=sign_up_usr(lineEditFullName->text(),t,lineEditUsername->text(),lineEditPassword->text());
    }else{
        isRegistered=sign_up_mgr(lineEditFullName->text(),t,lineEditUsername->text(),lineEditPassword->text());
    }
    if(isRegistered){
        QMessageBox msg;
        msg.setText("Registered!");
        msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        msg.exec();
        this->close();
        parent->show();
    }else{
        QMessageBox msg;
        msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        msg.setText("Username already exists!");
        msg.exec();
    }
}
