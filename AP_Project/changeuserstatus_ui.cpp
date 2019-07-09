#include "changeuserstatus_ui.h"

ChangeUserStatus_UI::ChangeUserStatus_UI(QWidget *parent) : QWidget(parent)
{
    ListWidgetUsers = new QListWidget;
    WidgetUser = new QWidget;
    LabelMassage = new QLabel(tr("Active or Ban the User!"));
    PushButtonBan = new QPushButton(tr("Ban"));
    PushButtonActive = new QPushButton(tr("Active"));

    GridLayout_all = new QGridLayout();


    GridLayout_all->addWidget(LabelMassage,0,0,1,2);
    GridLayout_all->addWidget(PushButtonBan,1,1);
    GridLayout_all->addWidget(PushButtonActive,1,0);
    WidgetUser->setLayout(GridLayout_all);
    WidgetUser->hide();

    QGridLayout *temp = new QGridLayout();
    temp->addWidget(ListWidgetUsers,0,0,1,3);





    PushButtonActive->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif}");
    PushButtonBan->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");
    connect(ListWidgetUsers,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(ListWidgetDoubleClicked(QListWidgetItem *)));
    this->setLayout(temp);
}

void ChangeUserStatus_UI::ListWidgetDoubleClicked(QListWidgetItem *)
{
    WidgetUser->adjustSize();
    WidgetUser->move(QApplication::desktop()->screen()->rect().center()
                         - WidgetUser->rect().center());

    WidgetUser->show();
    WidgetUser->setWindowFlag(Qt::FramelessWindowHint);
}
