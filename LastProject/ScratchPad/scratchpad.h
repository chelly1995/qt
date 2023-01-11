#ifndef SCRATCHPAD_H
#define SCRATCHPAD_H

#include <QWidget>



class ScratchPad:public QWidget
{
    Q_OBJECT
public:
    explicit ScratchPad(QWidget*parent=0);


protected:                              // 이벤트 핸들러 추가
    void paintEvent(QPaintEvent*event)Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent*event)Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent*event)Q_DECL_OVERRIDE;

private:
    void resizeImage(QImage*image,const QSize &newSize);

    bool modified;          // 버튼을 눌렸는지를 확인하는 변수 : 드로잉시 이용
    QImage image;           // 그림을 그리는데 사용하는 버퍼 이미지
    QPointF prevPos;        // 선을 그릴때 이전 점의 위치를 기억하는 변수
    QColor paintColor;      // 색상을 기억하는 변수
    qreal paintSize;        // 선의 크기를 기억하는 변수



public slots:
    void saveImage();
    void setPaintColor();
    void setPaintSize(qreal);

};

#endif // SCRATCHPAD_H
