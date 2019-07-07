#include "addnewflat_ui.h"
#include "headers.h"
AddNewFlat_UI::AddNewFlat_UI(QWidget *parent) : QWidget(parent)
{
    listWidget_all = new QListWidget;
    for(auto i = apartments.begin() ; i!= apartments.end() ; i++){
        QString txt;
        txt += "ID: ";
        txt += i->second.get_id();
        txt += " Address: ";
        txt += i->second.get_address();
        listWidget_all->addItem(txt);
    }


    tmp_v = new QVBoxLayout;
    tmp_v->addWidget(listWidget_all);

    this->setLayout(tmp_v);
    listWidget_all->setFixedWidth(700);
    listWidget_all->setStyleSheet("background-color:#f2f2f2;color:#595959;padding:10px;border:1px solid #bfbfbf; font-weight:bold;font-family:Serif");
    connect(listWidget_all,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(ListWidgetDoubleClicked(QListWidgetItem *)));

}

void AddNewFlat_UI::ListWidgetDoubleClicked(QListWidgetItem *item)
{
    QString id ;
    for(int i = 4 ; i !=item->text().length();i++){
        if(item->text()[i] == " ")
            break;
        id += item->text()[i];
    }
    apartmentflat = new AddNewApartment_UI(apartments[id]);
    for (int i = 0; i < tmp_v->count(); ++i)
    {
      QWidget *widget = tmp_v->itemAt(i)->widget();
      if (widget != nullptr)
      {
          widget->close();
      }
    }
    tmp_v->addWidget(apartmentflat);
}
