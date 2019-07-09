#ifndef FILEMANAGEMENT_UI_H
#define FILEMANAGEMENT_UI_H

#include "requests_ui.h"
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
#include "salerent_ui.h"
class FileManagement_UI : public QWidget
{
    Q_OBJECT
    QPushButton *PushButtonSalesFile;
    QPushButton *PushButtonRentsFile;
    QPushButton *PushButtonRequests;

    QGridLayout *GridLayoutButtons;

public:

    Requests_Ui *Requests;
    SaleRent_ui *sales;
    SaleRent_ui *rents;


    explicit FileManagement_UI(QWidget *parent = nullptr);


signals:

public slots:
    void PushButtonRequestsClicked();
};

#endif // FILEMANAGEMENT_UI_H
