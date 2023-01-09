#include <QtWidgets>

#include "scratchpad.h"

#define RADIUS 5

ScratchPad::ScratchPad(QWidget*parent):
    QWidget(parent),modified(false),paintSize(1)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    setAttribute(Qt::WA_StaticContents);
    paintColor=Qt::black;

}


void ScratchPad::paintEvent(QPaintEvent*event){
    QPainter painter(this);
    const QRect rect=event->rect();
    painter.drawImage(rect.topLeft(),image,rect);


}


void ScratchPad::resizeEvent(QResizeEvent*event)
{
    if(width()>image.width()||height()>image.height()){
        int newWidth=qMax(width()+128,image.height());
        int newHeight=qMax(height()+128,image.height());
        resizeImage(&image,QSize(newWidth,newHeight));

        update();
    }
    QWidget::resizeEvent(event);
}

void ScratchPad::resizeImage(QImage *image,const QSize&newSize)
{
    if(image->size()==newSize)return;       // 새로운 크기로 버퍼를 새롭게 생성
    QImage newImage(newSize,QImage::Format_RGB32);
    newImage.fill(qRgb(255,255,255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0),*image);
    *image=newImage;

}


void ScratchPad::mousePressEvent(QMouseEvent*event) /* 마우스 눌렸을 때 */
{
    prevPos=event->pos();           /* 이전 점의 위치 기억 */
    QPen pen(paintColor,paintSize);
    pen.setCapStyle(Qt::RoundCap);
    QPainter painter(&image);
    painter.setPen(pen);
    painter.drawPoint(prevPos);     /* 현재의 위치에 점 그리기 */
    painter.end();
    modified=true;

}


void ScratchPad::mouseMoveEvent(QMouseEvent*event)  /* 마우스 이동시 */
{

    QPointF newPos=event->pos();    /* 이전 점의 위치 기억 */
    if(modified){
            QPen pen(paintColor,paintSize);
            pen.setCapStyle(Qt::RoundCap);  /* 보다 부드러운 선을 위해 설정 */
            pen.setJoinStyle(Qt::RoundJoin);
            QPainter painter(&image);
            painter.setPen(pen);
            painter.drawLine(prevPos,newPos);
            painter.end();

    }

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



void ScratchPad::mouseReleaseEvent(QMouseEvent*event)   // 마우스를 놓았을때
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



void ScratchPad::setPaintColor(){

    paintColor=QColorDialog::getColor(paintColor,this);
}

void ScratchPad::saveImage(){

    QString filename=QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+".png";
    image.save(filename);

}

void ScratchPad::setPaintSize(qreal size){

    paintSize=size;
}
