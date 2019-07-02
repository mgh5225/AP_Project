#include "main_ui.h"

Main_UI::Main_UI(QWidget *parent) : QMainWindow(parent)
{
    btn_exit = new QToolButton();
    btn_log_in = new QToolButton();
    btn_sign_up = new QToolButton();
    btn_exit->setMinimumSize(70,70);
    btn_log_in->setMinimumSize(70,70);
    btn_sign_up->setMinimumSize(70,70);



    QPixmap pixmap(":/icons/resource/icons/User_Login.png");
    QIcon btn_log_in_Icon(pixmap);

    btn_log_in->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_log_in->setIcon(btn_log_in_Icon);
    btn_log_in->setIconSize(QSize(30, 30));
    btn_log_in->setText("Log In");


    QPixmap pixmap2(":/icons/resource/icons/Exit_Icon.png");
    QIcon btn_exit_Icon(pixmap2);

    btn_exit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_exit->setIcon(btn_exit_Icon);
    btn_exit->setIconSize(QSize(30, 30));
    btn_exit->setText("Exit");

    QPixmap pixmap3(":/icons/resource/icons/Sign_Up_Icon.png");
    QIcon btn_sign_up_Icon(pixmap3);

    btn_sign_up->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_sign_up->setIcon(btn_sign_up_Icon);
    btn_sign_up->setIconSize(QSize(30, 30));
    btn_sign_up->setText("Sign up");








    toolbar = new QHBoxLayout();

    my_grid_layout = new QGridLayout();
    myFrame = new QFrame();

    //set layout

    toolbar->addWidget(btn_log_in,0,Qt::AlignLeft);
    toolbar->addWidget(btn_sign_up,1,Qt::AlignLeft);
    toolbar->addWidget(btn_exit,0,Qt::AlignRight);


    // 2-4 for show building!!!
    frameToolBar = new QFrame();
    frameToolBar->setLayout(toolbar);
    frameToolBar->setStyleSheet("border-bottom: 1px solid gray;border-radius:0");
    my_grid_layout->addWidget(frameToolBar,0,0,1,5,Qt::AlignTop);
   // my_grid_layout->addLayout(toolbar,0,0,1,5,Qt::AlignTop);


    myFrame->setLayout(my_grid_layout);
    myFrame->setStyleSheet("background-color:white;border-radius: 5px;");




    ////////////////////////////////////////
    //set frame



    QGridLayout *temp = new QGridLayout();
    temp->addWidget(myFrame);

    QWidget *widget = new QWidget();
    widget->setLayout(temp);
    this->setCentralWidget(widget);
    /////////////////////////////////////
    // round window!!
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////
    //css

    btn_log_in->setStyleSheet("QToolButton:pressed {background-color: #00cc00;color:#b3ffb3;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;} QToolButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} ");
    btn_sign_up->setStyleSheet("QToolButton:pressed {background-color: #2980b9;color:#B3E5FC;padding:10px;border:1px solid #3498db; font-weight:bold;font-family:Serif;} QToolButton{ background-color:#B3E5FC;color:#2980b9;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif} ");
    btn_exit->setStyleSheet("QToolButton:pressed {background-color:#ff1a1a;color:#ffb3b3;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QToolButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");


}
