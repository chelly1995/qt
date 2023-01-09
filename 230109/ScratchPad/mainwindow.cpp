#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scratchpad.h"

#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scratchPad=new ScratchPad(this);
    ui->tabWidget->addTab(m_scratchPad,tr("Scratch Pad"));
    ui->actionSave->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    ui->actionColor->setIcon(style()->standardIcon(QStyle::SP_DriveCDIcon));

    QDoubleSpinBox *spinBox=new QDoubleSpinBox(this);
    spinBox->setValue(10.0f);
    connect(spinBox, SIGNAL(valueChanged(double)), m_scratchPad, SLOT(setPaintSize(qreal)));
    ui->toolBar->addWidget(spinBox);




    resize(1024,800);

   // QSpintBox* spinBox = new QSpinBox(this);
   // ui->toolBar->addWidget(spinBox);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSave_triggered()
{
    m_scratchPad->saveImage();
}



void MainWindow::on_actionColor_triggered()
{
     m_scratchPad->setPaintColor();
}

