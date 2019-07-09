#ifndef EDITPANEL_UI_H
#define EDITPANEL_UI_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QResource>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFrame>
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

class EditPanel_UI : public QWidget
{
    Q_OBJECT

    QLabel *LabelFullName;
    QLabel *LabelUsername;
    QLabel *LabelPassword;
    QLabel *LabelBalance;


    QLineEdit *LineEditFullName;
    QDateEdit *DateEditBirthDay;
    QLineEdit *LineEditUsername;
    QLineEdit *LineEditPassword;
    QLineEdit *LineEditBalance;

    QPushButton *PushButtonSave;
    QPushButton *PushButtonCancel;

    QVBoxLayout *LayoutVAll;

public:
    explicit EditPanel_UI(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // EDITPANEL_UI_H
