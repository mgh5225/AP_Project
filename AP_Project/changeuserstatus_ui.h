#ifndef CHANGEUSERSTATUS_UI_H
#define CHANGEUSERSTATUS_UI_H

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
#include <QDialog>

class ChangeUserStatus_UI : public QWidget
{
    Q_OBJECT

     QListWidget * ListWidgetUsers;
     QWidget * WidgetUser;
     QPushButton *PushButtonActive;
     QPushButton *PushButtonBan;
     QLabel *LabelMassage;
     QGridLayout *GridLayout_all;


public:
    explicit ChangeUserStatus_UI(QWidget *parent = nullptr);

signals:

public slots:

     void ListWidgetDoubleClicked(QListWidgetItem *);
};

#endif // CHANGEUSERSTATUS_UI_H
