#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shapemenu = new QMenu(this);
    shapemenu->addAction("circle")->setIcon(QIcon("circle.png"));
    shapemenu->addAction("triangle")->setIcon(QIcon("triangle.png"));
    shapemenu->addAction("rectangle")->setIcon(QIcon("rectangle.png"));

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




