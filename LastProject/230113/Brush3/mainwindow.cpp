#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "brush.h"
#include "painter.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    QPushButton *button1 = new QPushButton;
    //    QPushButton *button2 = new QPushButton;

    //    QSpinBox *spinbox1 = new QSpinBox;

    //    QVBoxLayout *leftlay1 = new QVBoxLayout;
    //    leftlay1->addWidget(button1);
    //    leftlay1->addWidget(button2);

    //    QHBoxLayout *lay = new QHBoxLayout;
    //    lay->addLayout(leftlay1);
    //    lay->addWidget(spinbox1);

    //   QHBoxLayout *Layout = new QHBoxLayout();
    //  ui->buttonframe->setLayout(lay);

    QHBoxLayout *HLayout2 = new QHBoxLayout;
    Painter *painter = new Painter(this);


    HLayout2->addLayout(ui->horizontalLayout);
    HLayout2->addWidget(painter);

    setLayout(HLayout2);

    painter->setGeometry(200,50,500,500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

