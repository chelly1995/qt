#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>


class Rectangle : public QGraphicsRectItem
{
public:
    Rectangle();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // RECTANGLE_H
