#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu = new QMenu(this);
    menu->addAction("circle")->setIcon(QIcon("circle.png"));
    menu->addAction("triangle")->setIcon(QIcon("triangle.png"));
    menu->addAction("rectangle")->setIcon(QIcon("rectangle.png"));


    /* 버튼 아이콘 사이즈 설정 */

    ui->ShapeButton->setIconSize(QSize(100,100));
    ui->ArrowButton->setIconSize(QSize(100,100));
    ui->MemoButton->setIconSize(QSize(100,100));

    ui->StraightMeasureButton->setIconSize(QSize(100,100));
    ui->TapeMeasureButton->setIconSize(QSize(100,100));
    ui->protractorButton->setIconSize(QSize(100,100));


    ui->ShapeButton->setMenu(menu);


    ui->ShapeButton->setPopupMode(QToolButton::InstantPopup);   // 도형 버튼 화살표
    QObject::connect(this, SIGNAL(triggered(QAction*)),this, SLOT(setDefaultAcion(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_ShapeButton_triggered(QAction *arg1)
//{
//   // ui->
//}

//void MainWindow::createActions(){

//    circleAction = new QAction("circle",this);
//    triangleAction = new QAction("triangle",this);
//    rectangleAction = new QAction("rectangle",this);

//    circleAction->setIcon(QIcon("circle.png"));
//    triangleAction->setIcon(QIcon("triangle"));
//    retangleAction->setIcon(QIcon("rectangle"));

//    QObject::connect(circleAction, SIGNAL(triggered()),this,SLOT(circle()));
//}
