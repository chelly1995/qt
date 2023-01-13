#ifndef BRUSH_H
#define BRUSH_H

#include <QColor>
//#include <QImage>
//#include <QPoint>
#include <QWidget>


class Brush : public QWidget
{
    Q_OBJECT
public:
    explicit Brush(QWidget *parent = nullptr);

    void createLayout();


protected:
//    void paintEvent(QPaintEvent*event)override;
//    void resizeEvent(QResizeEvent*event)override;
//    void mousePressEvent(QMouseEvent*event)override;
//    void mouseMoveEvent(QMouseEvent*event)override;
//    void mouseReleaseEvent(QMouseEvent*event)override;

private:

//    void resizeImage(QImage *image, const QSize &newSize);

//    bool modified;   // 버튼이 눌렸는지를 확인하는 변수 : 드로잉 시 이용
//    QImage image;       // 그림을 그리는데 사용하는 버퍼 이미지
//    QPointF prevPos;    // 선을 그릴때 이전 점의 위치를 기억하는 변수
//    QColor paintColor;  // 색상을 기억하는 변수
//    qreal paintSize;    // 선의 크기를 기억하는 변수
    QImage *imgSize;

public slots:
    //    void setPaintColor();
    //    void setPaintSize(qreal);


signals:

};

#endif // BRUSH_H
