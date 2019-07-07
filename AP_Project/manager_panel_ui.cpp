#include "manager_panel_ui.h"

Manager_Panel_UI::Manager_Panel_UI(QWidget *parent) : QWidget(parent)
{

   btn_Exit         = new QToolButton();

   btn_addFile      = new QToolButton();
   btn_LogOut       = new QToolButton();
   btn_Icon = new QToolButton();
   btn_explore      = new QToolButton();
   btn_file_Management = new QToolButton();


   btn_Exit->setMinimumSize(70,70);
   btn_file_Management->setMinimumSize(90,70);
   btn_explore->setMinimumSize(90,70);
   btn_addFile->setMinimumSize(90,70);
   btn_LogOut->setMinimumSize(90,70);
   btn_Icon->setMinimumSize(90,80);

   btn_LogOut->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_explore->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_addFile->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
   btn_Exit->setSizePolicy(QSizePolicy ::Minimum , QSizePolicy ::Expanding );
   btn_file_Management->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );

   QPixmap pixmap(":/icons/resource/icons/Exit_Icon.png");
   QIcon btn_log_in_Icon(pixmap);
   btn_Exit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_Exit->setIcon(btn_log_in_Icon);
   btn_Exit->setIconSize(QSize(30, 30));
   btn_Exit->setText("Exit");

   QPixmap pixmap1(":/icons/resource/icons/explore.png");
   QIcon btn_explore_Icon(pixmap1);
   btn_explore->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   btn_explore->setIcon(btn_explore_Icon);
   btn_explore->setIconSize(QSize(30, 30));
   btn_explore->setText("Explore");/////////////////////
    btn_explore->setStyleSheet("font: bold");

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


    //btn_file_managment

    QPixmap pixmap6(":/icons/resource/icons/File_Management.png");
    QIcon btn_Fila_Management_Icon(pixmap6);
     btn_file_Management->setIcon(btn_Fila_Management_Icon);
     btn_file_Management->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     btn_file_Management->setIconSize(QSize(30, 30));
     btn_file_Management->setText(" File Management");


   //h layout
   my_h_layout = new QHBoxLayout();
   my_h_layout->addWidget(btn_Icon,0,Qt::AlignLeft);
   my_h_layout->addWidget(btn_Exit,0,Qt::AlignRight);
   my_h_layout->setSpacing(0);
   my_h_layout->setMargin(0);

   QFrame *H_frame = new QFrame();
   H_frame->setLayout(my_h_layout);

   H_frame->setStyleSheet("background-color: #e67e22");

   //v layout

   my_v_layout = new QVBoxLayout();
   my_v_layout->addWidget(btn_addFile);
   my_v_layout->addWidget(btn_explore);
      my_v_layout->addWidget(btn_file_Management);
   my_v_layout->addWidget(btn_LogOut);

   my_v_layout->setSpacing(0);
   my_v_layout->setMargin(0);
   my_v_layout->setAlignment(Qt::AlignTop);
   QFrame *V_fram = new QFrame();
   V_fram->setLayout(my_v_layout);
    V_fram->setStyleSheet("background-color: #e67e22");
    QSize availableSize = qApp->desktop()->availableGeometry().size();
        int width = availableSize.width();
        int height = availableSize.height();
        //qDebug() << "Available dimensions " << width << "x" << height;
        width *= 0.73; // 90% of the screen size
        height *= 0.8; // 90% of the screen size
        //qDebug() << "Computed dimensions " << width << "x" << height;
        this->move(width/2 , height/2);
        QSize newSize( width, height );

        this->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );

   V_fram->setFixedSize(128,height - 95);
   H_frame->setFixedSize(width,85);


   btn_LogOut->setStyleSheet("QToolButton:hover{ background-color: #d35400; color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
   btn_addFile->setStyleSheet("QToolButton:hover{ background-color: #d35400;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
   btn_explore->setStyleSheet("QToolButton:hover{ background-color: #d35400;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
   btn_Icon->setStyleSheet("border: 0;font: bold;margin:15px;color:white");
   btn_Exit->setStyleSheet("QToolButton:hover{ background-color: #d35400; color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center;}");
   btn_file_Management->setStyleSheet("QToolButton:hover{ background-color: #d35400;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");



   //grid layout


   my_grid_layout = new QGridLayout();

   my_grid_layout->addWidget(H_frame,0,0,1,7,Qt::AlignTop);
   my_grid_layout->addWidget(V_fram,1,0,7,7,Qt::AlignLeft);
   my_grid_layout->setSpacing(0);
   my_grid_layout->setMargin(0);

   QFrame *Grid_frame = new QFrame();
    Grid_frame->setLayout(my_grid_layout);
   Grid_frame->setStyleSheet("background-color: #e3e7e8");

   //
    QGridLayout * my_final_layout = new QGridLayout();
    my_final_layout->addWidget(Grid_frame);

     this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setLayout(my_final_layout);
    this->setWindowFlags(Qt::FramelessWindowHint);

    Building=nullptr;
    Explorer=nullptr;

    connect(btn_addFile,SIGNAL(clicked()),this,SLOT(add_building_clicked()));
    connect(btn_Exit,SIGNAL(clicked()),this,SLOT(on_btn_exit_clicked()));
    connect(btn_explore,SIGNAL(clicked()),this,SLOT(explorer_clicked()));
    Building=nullptr;
    Explorer=nullptr;
}


void Manager_Panel_UI::add_building_clicked()
{
    if(Building!=nullptr){
        Building->close();
    }
    if(Explorer!=nullptr){
        if(Explorer->aptrs){
            Explorer->aptrs->body->close();
            Explorer->aptrs->body=nullptr;
        }
        if(Explorer->svillas){
            Explorer->svillas->scr->close();
            Explorer->svillas->scr=nullptr;
        }
        if(Explorer->nvillas){
            Explorer->nvillas->scr->close();
             Explorer->nvillas->scr=nullptr;
        }
        if(Explorer->allb){
            Explorer->allb->body->close();
            Explorer->allb->body=nullptr;
        }
        Explorer->close();
        Explorer=nullptr;
    }
    Building=new AddBuilding;
    my_grid_layout->addWidget(Building,3,4,1,1,Qt::AlignCenter);
}
void Manager_Panel_UI::explorer_clicked()
{
    if(Building!=nullptr){
        Building->close();
        Building=nullptr;
    }
    if(Explorer!=nullptr){
        if(Explorer->aptrs){
            Explorer->aptrs->body->close();
        }
        Explorer->close();
    }
    Explorer=new explorer(this);
    my_grid_layout->addWidget(Explorer,3,4,1,1,Qt::AlignCenter);
}





