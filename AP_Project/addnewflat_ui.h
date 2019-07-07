#ifndef ADDNEWFLAT_UI_H
#define ADDNEWFLAT_UI_H
#include "addnewapartment_ui.h"

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QLineEdit>
#include<QResource>
#include<QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include<QFrame>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateEdit>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include <QRadioButton>
#include <QListWidget>

class AddNewFlat_UI : public QWidget
{
    Q_OBJECT

    QListWidget * listWidget_all;
    AddNewApartment_UI * apartmentflat;
    QVBoxLayout *tmp_v;


public:
    explicit AddNewFlat_UI(QWidget *parent = nullptr);

signals:

public slots:
    void ListWidgetDoubleClicked(QListWidgetItem * item);
};

#endif // ADDNEWFLAT_UI_H
