#ifndef ADDNEWAPARTMENT_UI_H
#define ADDNEWAPARTMENT_UI_H

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

class AddNewApartment_UI : public QWidget
{
    Q_OBJECT

    QLabel *labelApartmentArea;
    QLabel *labelBasePrice;
    QLabel *labelNumberOfFloors;
    QLabel *labelAddress;
    QLabel *labelApartmentPicture;
    QLabel *labeNumberOfUnits;
    QLabel *labelDragAndDrop;
    QLabel *labeDragAndDropUnits;
    QLabel *labelElevator;

    QLabel *labelWhichUnit;
    QLabel *labelUnitFloorNumber;
    QLabel *labelUnitNumberOfRooms;
    QLabel *labelUnitArea;
    QLabel *labelUnitPicture;

    QLineEdit *lineEditApartmentArea;
    QLineEdit *lineEditBasePrice;
    QLineEdit *lineEditNumberOfFloors;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditNumberOfUnits;

    QLineEdit *lineEditUnitFloorNumber;
    QLineEdit *lineEditUnitNumberOfRooms;
    QLineEdit *lineEditUnitArea;

    QComboBox *comboBoxWhichUnit;
    QComboBox *comboBoxElevator;

    QPushButton *pushBottonAdd;
    QPushButton *pushBottonCancel;
    //QPushButton pushBottonAddUnit;

    QFrame *myFrame;
    QFrame *myFinalFrame;

    QVBoxLayout *myFirstVBoxLayOut;
    QVBoxLayout *mySecondVBoxLayOut;
    QHBoxLayout *myHBoxLayOutBotton;
    QGridLayout *myFinalLayOut;




    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

public:
    explicit AddNewApartment_UI(QWidget *parent = nullptr);

signals:

public slots:
    void ChangeFrame(const QString &text);
};

#endif // ADDNEWAPARTMENT_UI_H
