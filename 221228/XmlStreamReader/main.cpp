#include "xmlstreamreader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XmlStreamReader w;
    w.show();
    return a.exec();
}
