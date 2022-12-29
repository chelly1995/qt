#include <QApplication>
#include <QPushButton>


#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit",this);
    connect(quit, SIGNAL(clicked()),qApp,SLOT(quit()));
    quit->dumpObjectInfo();
    quit->resize(75,35);
}

Widget::~Widget()
{
}

