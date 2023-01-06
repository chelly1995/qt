#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton1_clicked()
{
    scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);

        QBrush greenBrush(Qt::green);
        QBrush blueBrush(Qt::blue);
        QPen outlinePen(Qt::black);
        outlinePen.setWidth(2);

        rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);


}

