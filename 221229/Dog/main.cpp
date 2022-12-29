#include "dog.h"

#include <QApplication>
#include <QDebug>
#include <QTest>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dog dog;
    QTest::qExec(&dog);


   return a.exec();
}
