#ifndef EXPLORER_H
#define EXPLORER_H

#include <QObject>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QFrame>
#include "showapartments.h"
#include "showsouthvillas.h"
#include "shownorthvillas.h"
#include "showallbuildings.h"
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
    explicit explorer(person*,QWidget *parent = nullptr);
    ShowApartments* aptrs;
    ShowSouthVillas* svillas;
    ShowNorthVillas* nvillas;
    ShowAllBuildings* allb;
    person*  p;

signals:

public slots:
    void show_aptrs();
    void show_svillas();
    void show_nvillas();
    void show_allb();
};

#endif // EXPLORER_H
