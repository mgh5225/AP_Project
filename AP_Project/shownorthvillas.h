#ifndef SHOWNORTHVILLAS_H
#define SHOWNORTHVILLAS_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include "showbuilding_widget.h"
class ShowNorthVillas : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    vector<ShowBuilding_widget*> aptrs;
    QGridLayout* all;
    QWidget* temp;

public:
    person*  p;
    explicit ShowNorthVillas(person*,QWidget *parent = nullptr);
    QScrollArea* scr;

signals:

public slots:
};

#endif // SHOWNORTHVILLAS_H
