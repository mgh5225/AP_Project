#ifndef SHOWLOG_UI_H
#define SHOWLOG_UI_H

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
#include <QListWidget>

class ShowLog_UI : public QWidget
{
    Q_OBJECT
    QListWidget *ListWidgetShowLog;
    QPushButton *PushButtonExit;

    QGridLayout *GridLayout_All;
public:
    explicit ShowLog_UI(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SHOWLOG_UI_H
