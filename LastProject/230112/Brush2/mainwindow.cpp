#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString img_path = "C:\Image\cat.jpg";
//    QImage img(img_path);
//    QPixmap buf = QPixmap::fromImage(img);

//    buf = buf.scaled(1024,1024);

//    QGraphicsScene* scene = new QGraphicsScene;
//    ui->graphicsView->setScene(scene);

//    scene->addPixmap(buf);

    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load Image"),
                                                    mResourceDir,
                                                    tr("Images (*.png *.jpg)"));

    if (filename.isEmpty())  {
        return;
    }

    QPixmap p(filename);
   // QPixmap buf = QPixmap::fromImage(p);

    //p.scaled(2048,2048);
    p.size();

    if (! ui->graphicsView->scene()) {
        qDebug() << "No Scene!";

        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    }
    ui->graphicsView->scene()->addPixmap(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}



