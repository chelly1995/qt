#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "circle.h"
#include "scratchpad.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QFileDialog>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scratchPad=new ScratchPad(ui->graphicsView);

//    QGraphicsScene scene1;
//    scene1.addRect(QRectF(0, 0, 100, 200), QPen(Qt::black), QBrush(Qt::green));

//    QPixmap pixmap;
//    QPainter painter(&pixmap);
//    painter.setRenderHint(QPainter::Antialiasing);
//    scene1.render(&painter);
//    painter.end();

//    pixmap.save("scene.png");

    QGraphicsScene*scene = new QGraphicsScene(this);
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(Qt::yellow)));
    scene->setSceneRect(-500,-500,600,600);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton1_clicked()
{
    QPen mPen;
    mPen.setWidth(5);
    mPen.setColor(Qt::red);

    Circle *circleItem=new Circle();
    circleItem->setRect(-150,0,150,150);
    circleItem->setFlag(QGraphicsItem::ItemIsMovable);
    circleItem->setFlag(QGraphicsItem::ItemIsSelectable);
    circleItem->setPen(mPen);
    circleItem->setBrush(QBrush(Qt::NoBrush));


    scene->addItem(circleItem);

}


void MainWindow::on_toolButton_2_clicked()
{
    QPen mPen;
    mPen.setWidth(5);
    mPen.setColor(Qt::red);

    Rectangle *rectItem=new Rectangle();
    rectItem->setRect(-10,-10,200,200);
    rectItem->setFlag(QGraphicsItem::ItemIsFocusable);
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsItem::ItemIsSelectable);
    rectItem->setFocus();

    rectItem->setPen(mPen);
    rectItem->setBrush(QBrush(Qt::NoBrush));


    scene->addItem(rectItem);

    //ui->graphicsView->setScene(scene);

}



void MainWindow::on_LoadButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Load Image"),
                                                    mResourceDir,
                                                    tr("Images (*.png *.jpg)"));

    if (filename.isEmpty())  {
        return;
    }

    QPixmap p(filename);
    if (! ui->graphicsView->scene()) {
        qDebug() << "No Scene!";

        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    }
    ui->graphicsView->scene()->addPixmap(p);
}



void MainWindow::on_ColorButton_clicked()
{
    //m_scratchPad->setPaintColor();
}

