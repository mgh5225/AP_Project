#ifndef SHOWALLBUILDINGS_H
#define SHOWALLBUILDINGS_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include "showbuilding_widget.h"
#include <QInputDialog>
class ShowAllBuildings : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    vector<ShowBuilding_widget*> allbu;
    QGridLayout* all;
    QScrollArea* scr;
    QVBoxLayout * side_lay;
    QFrame* side;
    QHBoxLayout* body_lay;
    QToolButton* search_by_price_meter;
    QToolButton* search_by_perimeter;
    QToolButton* sort_by_price;
    QWidget* temp;

public:
    person*  p;
    explicit ShowAllBuildings(person*,QWidget *parent = nullptr);
    QWidget* body;

signals:

public slots:
    void on_btn_search_by_price_meter_clicked();
    void on_btn_search_by_perimeter_clicked();
    void on_btn_sort_by_price_clicked();
};

#endif // SHOWALLBUILDINGS_H
