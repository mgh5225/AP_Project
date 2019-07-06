#ifndef SHOWAPARTMENTS_H
#define SHOWAPARTMENTS_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include "showbuilding_widget.h"
#include <QInputDialog>
class ShowApartments : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    vector<ShowBuilding_widget*> aptrs;
    QGridLayout* all;
    QScrollArea* scr;
    QVBoxLayout * side_lay;
    QFrame* side;
    QHBoxLayout* body_lay;
    QToolButton* search_by_flat;
    QToolButton* search_by_meter;
    QToolButton* search_by_rooms;
    QWidget* temp;

public:
    explicit ShowApartments(QWidget *parent = nullptr);
    QWidget* body;

signals:

public slots:
    void on_btn_search_by_flat_clicked();
    void on_btn_search_by_meter_clicked();
    void on_btn_search_by_rooms_clicked();
};
#endif // SHOWAPARTMENTS_H
