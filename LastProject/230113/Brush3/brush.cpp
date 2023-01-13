#include "brush.h"


#include <QPushButton>
#include <QSpinBox>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>

#define RADIUS 5

Brush::Brush(QWidget *parent)
    : QWidget{parent}
{

    /* 레이아웃 생성 */
    createLayout();

//    paintColor=Qt::black;

}


void Brush::createLayout()
{
    QPushButton *button1 = new QPushButton;
    QPushButton *button2 = new QPushButton;

    QSpinBox *spinbox1 = new QSpinBox;

    QVBoxLayout *leftlay1 = new QVBoxLayout;
    leftlay1->addWidget(button1);
    leftlay1->addWidget(button2);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addLayout(leftlay1);
    lay->addWidget(spinbox1);

//    QGraphicsView *graphics = new QGraphicsView;

//    QHBoxLayout *layout = new QHBoxLayout(this);
//    layout->addLayout(lay);
//    layout->addWidget(graphics);

//    QGraphicsScene *scene = new QGraphicsScene;
    //graphics->setScene(scene);


//    imgSize = new QImage();
//        imgSize->load("cat.jpg");
//        QPixmap buf = QPixmap::fromImage(*imgSize);
//        buf = buf.scaled(imgSize->width(), imgSize->height());

//        scene->addPixmap(buf);
//        graphics->setScene(scene);

        //graphics->setBackgroundBrush(Qt::NoBrush);
}

//void Brush::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    QRect rect = event->rect();
//    painter.drawImage(rect.topLeft(), image, rect); /* 화면에 이미지를 드로잉 */
//}


//void Brush::mousePressEvent(QMouseEvent *event) /* 마우스를 눌렀을 때 */
//{
//   prevPos=event->pos();    /* 이전 점의 위치 기억 */
//   QPen pen(paintColor,paintSize);
//   pen.setCapStyle(Qt::RoundCap);
//   QPainter painter(imgSize);
//   painter.setPen(pen);
//   painter.drawPoint(prevPos); /*현재 위치에 점 그리기 */
//   painter.end();
//   modified=true;
//}

//void Brush::mouseMoveEvent(QMouseEvent *event)  /* 마우스 이동시 */
//{
//    QPointF newPos = event->pos();  /* 이전 점의 위치 기억 */

//    if(modified){
//        QPen pen(paintColor, paintSize);
//        pen.setCapStyle(Qt::RoundCap);  /* 보다 부드러운 선을 위해 설정 */
//        pen.setJoinStyle(Qt::RoundJoin);
//        QPainter painter(&image);
//        painter.setPen(pen);
//        painter.drawLine(prevPos, newPos);  /* 이전 점에서 현재 점까지 선 그리기 */
//        painter.end();

//        int x1,x2,y1,y2;
//        if(prevPos.x()<newPos.x()){
//            x1=prevPos.x();x2=newPos.x();
//        }else{
//            x1=newPos.x();x2=prevPos.x();

//        }

//        if(prevPos.y()<newPos.y()){
//            y1=prevPos.y();y2=newPos.y();

//        }else{
//            y1=newPos.y();y2=prevPos.y();

//        }

//        QRectF rect(x1,y1,x2,y2);
//        update(rect.toRect().adjusted(-RADIUS,-RADIUS,+RADIUS,+RADIUS));
//        prevPos=newPos;

//    }
//}

//void Brush::mouseReleaseEvent(QMouseEvent *event)
//{

//    QPen pen(paintColor,paintSize);
//    pen.setCapStyle(Qt::RoundCap);
//    QPainter painter(&image);
//    painter.setPen(pen);
//    painter.drawPoint(prevPos); // 점 그리기
//    painter.end();
//    modified=false;

//    update();
//}


//void Brush::resizeEvent(QResizeEvent*event)
//{
//    if(width()>image.width()||height()>image.height()){
//        int newWidth=qMax(width()+128,image.width());
//        int newHeight=qMax(height()+128,image.height());
//        resizeImage(&image,QSize(newWidth,newHeight));

//        update();
//    }
//    QWidget::resizeEvent(event);
//}

//void Brush::resizeImage(QImage *image, const QSize &newSize)
//{

//    if(image->size()==newSize)return;   /* 새로운 크기로 버퍼를 새롭게 생성 */
//    QImage newImage(newSize, QImage::Format_ARGB32);
//    newImage.fill(qRgb(255,255,255));
//    QPainter painter(&newImage);
//    painter.drawImage(QPoint(0,0),*image);
//    *image = newImage;

//}
