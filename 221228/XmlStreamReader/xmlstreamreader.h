#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H

#include <QWidget>

class XmlStreamReader : public QWidget
{
    Q_OBJECT

public:
    XmlStreamReader(QWidget *parent = nullptr);
    ~XmlStreamReader();
};
#endif // XMLSTREAMREADER_H
