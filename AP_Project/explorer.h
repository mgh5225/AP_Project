#ifndef EXPLORER_H
#define EXPLORER_H

#include <QObject>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QFrame>
#include "showapartments.h"
class explorer : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    QToolButton *btn_ShowApartments;
    QToolButton *btn_ShowSouthVillas;
    QToolButton *btn_ShowNorthVillas;
    QToolButton *btn_ShowAllBuildings;
    QGridLayout *my_grid_Layout;

public:
    explicit explorer(QWidget *parent = nullptr);
    ShowApartments* aptrs;

signals:

public slots:
    void show_aptrs();
};

#endif // EXPLORER_H
