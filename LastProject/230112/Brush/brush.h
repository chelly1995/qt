#ifndef BRUSH_H
#define BRUSH_H

#include <QWidget>

class Brush : public QWidget
{
    Q_OBJECT
public:
    explicit Brush(QWidget *parent = nullptr);

signals:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


};

#endif // BRUSH_H
