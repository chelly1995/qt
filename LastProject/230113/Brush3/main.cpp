#include "mainwindow.h"
//#include "brush.h"
#include "painter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


//    QApplication a(argc, argv);
//    Brush w;
//    w.show();
//    return a.exec();

}
