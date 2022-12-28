#include <QtGui>
#include <QtWidgets>
#include <QDomDocument>


#include "xmlstreamreader.h"

XmlStreamReader::XmlStreamReader(QWidget *parent)
    : QWidget(parent)
{

    QStringList labels;
    labels << tr("Name") << tr("Telephone No.");
    QTreeWidget*treeWidget = new QTreeWidget(this);
    treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    treeWidget->setHeaderLabels(labels);

    QFile file("Sample.xml");
    file.open(QIODevice::ReadOnly | QFile::Text);
    QXmlStreamReader xmlReader(&file);

    xmlReader.readNextStartElement();
    if(xmlReader.name().toString() == "phonebook"){
        qDebug() <<1;
        while(xmlReader.readNextStartElement()){
            if(xmlReader.name().toString() == "phoneNumber"){
                QTreeWidgetItem*item=new QTreeWidgetItem(treeWidget);

                foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()){
                    if(attr.name().toString()==QLatin1String("Name"))
                        item->setText(0, attr.value().toString());
                    if(attr.name().toString()==QLatin1String("TelNo"))


                        item->setText(1,attr.value().toString());

                }

            }else{
                xmlReader.skipCurrentElement();
                xmlReader.readNextStartElement();
            }

        }
    }
}

XmlStreamReader::~XmlStreamReader()
{
}

