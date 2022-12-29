#include <QApplication>
#include <QTest>

#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setAge(0);
    QTest::qExec(&w);


   // w.show();
    return a.exec();
}
