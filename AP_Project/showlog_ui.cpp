#include "showlog_ui.h"

ShowLog_UI::ShowLog_UI(QWidget *parent) : QWidget(parent)
{
    ListWidgetShowLog = new QListWidget;
    ///set this shit!

    PushButtonExit = new QPushButton("Exit");

    PushButtonExit->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");

    PushButtonExit->setFixedWidth(700);

    GridLayout_All = new QGridLayout;

    GridLayout_All->addWidget(ListWidgetShowLog,0,0);
    GridLayout_All->addWidget(PushButtonExit,1,0);
    this->setLayout(GridLayout_All);
    connect(PushButtonExit,SIGNAL(clicked()),this,SLOT(close()));
}
