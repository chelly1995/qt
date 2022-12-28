#include "qteditor.h"

#include <QApplication>
#include<QtWidgets>
//#include<QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    auto i =  translator.load("hello_ko");
    if(i)
    {
    a.installTranslator(&translator);
    }
    //QPushButton hello(QObject::tr("Hello World"));
   // hello.resize(100,30);

    QtEditor w;
    w.show();

    return a.exec();
}
