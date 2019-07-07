#ifndef SHOWSOUTHVILLAS_H
#define SHOWSOUTHVILLAS_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include "showbuilding_widget.h"
class ShowSouthVillas : public QWidget
{
    Q_OBJECT
    QWidget* parent;
    vector<ShowBuilding_widget*> aptrs;
    QGridLayout* all;
    QWidget* temp;

public:
    explicit ShowSouthVillas(QWidget *parent = nullptr);
    QScrollArea* scr;

signals:

public slots:
};

#endif // SHOWSOUTHVILLAS_H
