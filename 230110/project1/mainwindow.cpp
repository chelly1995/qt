#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "circle.h"

#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QFileDialog>

class QAction;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    shapemenu = new QMenu(this);

    circleAction = new QAction("circle",this);
    shapemenu->addAction(circleAction);
    circleAction->setIcon(QIcon("circle.png"));
    QObject::connect(circleAction, SIGNAL(triggered()),
                     this, SLOT(circle()));


    rectangleAction = new QAction("rectangle",this);
    shapemenu->addAction(rectangleAction);
    rectangleAction->setIcon(QIcon("rectangle.png"));
    QObject::connect(rectangleAction, SIGNAL(triggered()),this, SLOT(rectangle()));

    //shapemenu->addAction("circle")->setIcon(QIcon("circle.png"));
    shapemenu->addAction("triangle")->setIcon(QIcon("triangle.png"));
    //shapemenu->addAction("rectangle")->setIcon(QIcon("rectangle.png"));

    sharpeningmenu = new QMenu(this);
    sharpeningmenu ->addAction("circle")->setIcon(QIcon("circle.png"));
    sharpeningmenu ->addAction("triangle")->setIcon(QIcon("triangle.png"));
    sharpeningmenu ->addAction("rectangle")->setIcon(QIcon("rectangle.png"));


    /* 버튼 아이콘 사이즈 설정 */


    ui->ShapeButton->setIconSize(QSize(30,30));
    ui->ArrowButton->setIconSize(QSize(30,30));
    ui->TextButton->setIconSize(QSize(30,30));

    ui->StraightMeasureButton->setIconSize(QSize(30,30));
    ui->TapeMeasureButton->setIconSize(QSize(30,30));
    ui->protractorButton->setIconSize(QSize(30,30));

    ui->ContrastButton->setIconSize(QSize(30,30));
    ui->ColorInvertButton->setIconSize(QSize(30,30));
    ui->SharpeningButton->setIconSize(QSize(30,30));


    ui->MemoButton->setIconSize(QSize(30,30));
    ui->KeyboardButton->setIconSize(QSize(30,30));


    ui->ColorButton->setIconSize(QSize(20,20));

    ui->DrawButton->setIcon(QIcon("draw.png"));
    ui->DrawButton->setIconSize(QSize(30,100));
    ui->DrawButton->setText("Draw Nerve");
    ui->DrawButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->InsertImplantButton->setIcon(QIcon("Implant3.png"));
    ui->InsertImplantButton->setIconSize(QSize(30,100));
    ui->InsertImplantButton->setText("Insert Implant");
    ui->InsertImplantButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    ui->ThicknesscomboBox->setItemIcon(0,QIcon("Thickness.png"));
    //ui->ThicknesscomboBox->


    /* 아래 화살표 추가 */

    ui->ShapeButton->setMenu(shapemenu);
    ui->SharpeningButton->setMenu(sharpeningmenu);

    ui->ShapeButton->setPopupMode(QToolButton::InstantPopup);   // 도형 버튼 화살표
    ui->SharpeningButton->setPopupMode(QToolButton::InstantPopup);

    // GraphicsScene

    scene = new QGraphicsScene(this);
    //  scene->setBackgroundBrush(QBrush(QColor(Qt::yellow)));
    scene->setSceneRect(-500,-500,600,600);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
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



void MainWindow::circle()
{
    qDebug() << "MainWindow::circle()";

    QPen mPen;
    mPen.setWidth(5);
    mPen.setColor(Qt::blue);

    Circle *circleItem=new Circle();
    circleItem->setRect(-150,0,150,150);
    circleItem->setFlag(QGraphicsItem::ItemIsMovable);
    circleItem->setFlag(QGraphicsItem::ItemIsSelectable);
    circleItem->setPen(mPen);
    circleItem->setBrush(QBrush(Qt::NoBrush));


    scene->addItem(circleItem);



}

void MainWindow::triangle()
{
    qDebug() << "MainWindow::triangle()";

}

void MainWindow::rectangle()
{

    qDebug() << "MainWindow::rectangle()";

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

}
