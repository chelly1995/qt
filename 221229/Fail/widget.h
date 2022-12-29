#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QTest>
//#include <QWidget>

class Widget : public QObject
{
    Q_OBJECT

public:
    explicit Widget(QObject *parent = nullptr);
    void setAge(int value);
~Widget();
private slots:
    void testFail();
    void testAge();
    void testWidget();

private:
    int age;

  //  Widget(QWidget *parent = nullptr);
};
#endif // WIDGET_H
