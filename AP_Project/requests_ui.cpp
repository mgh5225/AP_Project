#include "requests_ui.h"

Requests_Ui::Requests_Ui(QWidget *parent) : QWidget(parent)
{



    listWidget_all = new QListWidget;
    listWidget_all->addItem("txt");


    btn_deny = new QPushButton(tr("Deny"));
    btn_Accept = new QPushButton(tr("Accept"));

    widget_Request = new QWidget();
    widget_Request->setFixedWidth(700);
    lbl_Request = new QLabel(tr("Accept or Deny the Request!"));

    layout_all = new QVBoxLayout;
    layout_all->addWidget(listWidget_all);
    //layout_all->addWidget(widget_Request);

    layout_widget_H_Btn = new QHBoxLayout();

    layout_widget_H_Btn->addWidget(btn_Accept);
    layout_widget_H_Btn->addWidget(btn_deny);

    layout_widget_V = new QVBoxLayout();
    layout_widget_V->addWidget(lbl_Request);
    layout_widget_V->addLayout(layout_widget_H_Btn);
    widget_Request->hide();

    widget_Request->setLayout(layout_widget_V);
    widget_Request->setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(layout_all);
    connect(listWidget_all,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(ListWidgetDoubleClicked(QListWidgetItem *)));

    btn_Accept->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif}");
    btn_deny->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");
}

void Requests_Ui::ListWidgetDoubleClicked(QListWidgetItem *item)
{
    widget_Request->adjustSize();
    widget_Request->move(QApplication::desktop()->screen()->rect().center()
                         - widget_Request->rect().center());

    widget_Request->show();
}
