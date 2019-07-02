#include "user_panel_ui.h"

User_Panel_UI::User_Panel_UI(QWidget *parent) : QWidget(parent)
{
   btn_Exit         = new QToolButton();
   btn_explor      = new QToolButton();
   btn_showBalance = new QToolButton();
   btn_addFile      = new QToolButton();
   btn_LogOut       = new QToolButton();
   btn_Icon = new QToolButton();

   btn_Exit->setMinimumSize(70,70);
   btn_explor->setMinimumSize(90,70);
   btn_showBalance->setMinimumSize(90,70);
   btn_addFile->setMinimumSize(90,70);
   btn_LogOut->setMinimumSize(90,70);
   btn_Icon->setMinimumSize(90,80);

   btn_LogOut->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_explor->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_showBalance->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_addFile->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_Exit->setSizePolicy(QSizePolicy ::Minimum , QSizePolicy ::Expanding );


   QPixmap pixmap(":/icons/resource/icons/Exit_Icon.png");
   QIcon btn_log_in_Icon(pixmap);
   btn_Exit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_Exit->setIcon(btn_log_in_Icon);
   btn_Exit->setIconSize(QSize(30, 30));
   btn_Exit->setText("Exit");

   QPixmap pixmap1(":/icons/resource/icons/explore.png");
   QIcon btn_explor_Icon(pixmap1);
   btn_explor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_explor->setIcon(btn_explor_Icon);
   btn_explor->setIconSize(QSize(30, 30));
   btn_explor->setText("Explor");/////////////////////
    btn_explor->setStyleSheet("font: bold");
   QPixmap pixmap2(":/icons/resource/icons/Balance.png");
   QIcon btn_show_balance_Icon(pixmap2);
   btn_showBalance->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_showBalance->setIcon(btn_show_balance_Icon);
   btn_showBalance->setIconSize(QSize(30, 30));
   btn_showBalance->setText("Show Balance");/////////////////////////////////
    btn_showBalance->setStyleSheet("font: bold");

   QPixmap pixmap3(":/icons/resource/icons/AddFile.png");
   QIcon btn_History_Icon(pixmap3);
   btn_addFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_addFile->setIcon(btn_History_Icon);
   btn_addFile->setIconSize(QSize(30, 30));
   btn_addFile->setText("Add File");//////////
   btn_addFile->setStyleSheet("font: bold");

   QPixmap pixmap4(":/icons/resource/icons/logout.png");
   QIcon btn_LogOut_Icon(pixmap4);
   btn_LogOut->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_LogOut->setIcon(btn_LogOut_Icon);
   btn_LogOut->setIconSize(QSize(30, 30));
   btn_LogOut->setText("LogOut");
   btn_LogOut->setStyleSheet("font: bold");

   QPixmap pixmap5(":/icons/resource/icons/house.png");
   QIcon btn_Icon_Icon(pixmap5);
    btn_Icon->setIcon(btn_Icon_Icon);
    btn_Icon->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    btn_Icon->setIcon(btn_Icon_Icon);
    btn_Icon->setIconSize(QSize(30, 30));
    btn_Icon->setText(" Real State");


   //h layout
   my_h_layout = new QHBoxLayout();
   my_h_layout->addWidget(btn_Icon,0,Qt::AlignLeft);
   my_h_layout->addWidget(btn_Exit,0,Qt::AlignRight);
   my_h_layout->setSpacing(0);
   my_h_layout->setMargin(0);

   QFrame *H_frame = new QFrame();
   H_frame->setLayout(my_h_layout);

   H_frame->setStyleSheet("background-color: #91a0a1");

   //v layout

   my_v_layout = new QVBoxLayout();
   my_v_layout->addWidget(btn_addFile);
   my_v_layout->addWidget(btn_explor);
   my_v_layout->addWidget(btn_showBalance);
   my_v_layout->addWidget(btn_LogOut);
   my_v_layout->setSpacing(0);
   my_v_layout->setMargin(0);
   my_v_layout->setAlignment(Qt::AlignTop);
   QFrame *V_fram = new QFrame();
   V_fram->setLayout(my_v_layout);
    V_fram->setStyleSheet("background-color: #91a0a1");
   V_fram->setFixedSize(128,612);


   btn_LogOut->setStyleSheet("QToolButton:hover{ background-color: #34495e; color: wihte;}QToolButton{border:0px;color:white;padding:10px 0;text-align:center}");
   btn_explor->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: wihte;}QToolButton{border:0px;color:white;padding:10px 0;text-align:center}");
   btn_showBalance->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: wihte;}QToolButton{border:0px;color:white;padding:10px 0;text-align:center}");
   btn_addFile->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: wihte;}QToolButton{border:0px;color:white;padding:10px 0;text-align:center}");
   btn_Icon->setStyleSheet("border: 0;font: bold;margin:15px;color:white");
   btn_Exit->setStyleSheet("QToolButton:hover{ background-color: #34495e; color: wihte;}QToolButton{border:0px;color:white;padding:10px 0;text-align:center;}");


   //grid layout


   my_grid_layout = new QGridLayout();

   my_grid_layout->addWidget(H_frame,0,0,1,7,Qt::AlignTop);
   my_grid_layout->addWidget(V_fram,1,0,7,7,Qt::AlignLeft);
   my_grid_layout->setSpacing(0);
   my_grid_layout->setMargin(0);

   QFrame *Grid_frame = new QFrame();
    Grid_frame->setLayout(my_grid_layout);
   Grid_frame->setStyleSheet("background-color: white");

   //
    QGridLayout * my_final_layout = new QGridLayout();
    my_final_layout->addWidget(Grid_frame);
     this->setAttribute(Qt::WA_TranslucentBackground, true);
   this->setLayout(my_final_layout);
}
