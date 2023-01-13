#include "painter.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QPainter>
#include <QHBoxLayout>

#include <QGraphicsLineItem>

#define RADIUS 5

Painter::Painter(QWidget *parent)
    : QGraphicsView(parent),modified(false),paintSize(1)
{
    paintColor=Qt::black;


    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-300,-300,600,600);
    //setScene(scene);
//    QGraphicsLineItem* l = new QGraphicsLineItem;
//    l->setLine(-300,0,300,0);


    imgSize = new QImage();
    imgSize->load("cat.jpg");
    QPixmap buf = QPixmap::fromImage(*imgSize);
    buf = buf.scaled(imgSize->width(), imgSize->height());

    auto dd = new QGraphicsPixmapItem;
    //scene->addItem(l);

    scene->addPixmap(buf);
    setScene(scene);

}

void Painter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect.topLeft(), image, rect); /* 화면에 이미지를 드로잉 */
}


void Painter::mousePressEvent(QMouseEvent *event) /* 마우스를 눌렀을 때 */
{
    prevPos=event->pos();    /* 이전 점의 위치 기억 */
    QPen pen(paintColor,paintSize);
    pen.setCapStyle(Qt::RoundCap);
    QPainter painter(imgSize);
    painter.setPen(pen);
    painter.drawPoint(prevPos); /*현재 위치에 점 그리기 */
    painter.end();
    modified=true;
}

void Painter::mouseMoveEvent(QMouseEvent *event)  /* 마우스 이동시 */
{
    QPointF newPos = event->pos();  /* 이전 점의 위치 기억 */

    if(modified){
        QPen pen(paintColor, paintSize);
        pen.setCapStyle(Qt::RoundCap);  /* 보다 부드러운 선을 위해 설정 */
        pen.setJoinStyle(Qt::RoundJoin);
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(prevPos, newPos);  /* 이전 점에서 현재 점까지 선 그리기 */
        painter.end();

        int x1,x2,y1,y2;
        if(prevPos.x()<newPos.x()){
            x1=prevPos.x();x2=newPos.x();
        }else{
            x1=newPos.x();x2=prevPos.x();

        }

        if(prevPos.y()<newPos.y()){
            y1=prevPos.y();y2=newPos.y();

        }else{
            y1=newPos.y();y2=prevPos.y();

        }

        QRectF rect(x1,y1,x2,y2);
        update(rect.toRect().adjusted(-RADIUS,-RADIUS,+RADIUS,+RADIUS));
        prevPos=newPos;

    }
}

void Painter::mouseReleaseEvent(QMouseEvent *event)
{

    QPen pen(paintColor,paintSize);
    pen.setCapStyle(Qt::RoundCap);
    QPainter painter(&image);
    painter.setPen(pen);
    painter.drawPoint(prevPos); // 점 그리기
    painter.end();
    modified=false;

    update();
}


void Painter::resizeEvent(QResizeEvent*event)
{
    if(width()>image.width()||height()>image.height()){
        int newWidth=qMax(width()+128,image.width());
        int newHeight=qMax(height()+128,image.height());
        resizeImage(&image,QSize(newWidth,newHeight));

        update();
    }
    QWidget::resizeEvent(event);
}

void Painter::resizeImage(QImage *image, const QSize &newSize)
{

    if(image->size()==newSize)return;   /* 새로운 크기로 버퍼를 새롭게 생성 */
    QImage newImage(newSize, QImage::Format_ARGB32);
    newImage.fill(qRgb(255,255,255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0),*image);
    *image = newImage;

}
