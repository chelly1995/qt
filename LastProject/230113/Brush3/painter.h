#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QGraphicsView>
#include <QColor>
//#include <QImage>
//#include <QPoint>

class Painter : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent*event)override;
    void resizeEvent(QResizeEvent*event)override;
    void mousePressEvent(QMouseEvent*event)override;
    void mouseMoveEvent(QMouseEvent*event)override;
    void mouseReleaseEvent(QMouseEvent*event)override;


signals:

private:
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;   // 버튼이 눌렸는지를 확인하는 변수 : 드로잉 시 이용
    QImage image;       // 그림을 그리는데 사용하는 버퍼 이미지
    QPointF prevPos;    // 선을 그릴때 이전 점의 위치를 기억하는 변수
    QColor paintColor;  // 색상을 기억하는 변수
    qreal paintSize;    // 선의 크기를 기억하는 변수
    QImage *imgSize;
};

#endif // PAINTER_H
