#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

// add necessary includes here

class GuiTest : public QWidget
{
    Q_OBJECT

public:
    GuiTest(QWidget *parent = nullptr);
    ~GuiTest();

    QLineEdit*lineEdit;

private slots:
    void test_case1();
    void test_case1_data();


};

GuiTest::GuiTest(QWidget*parent):QWidget(parent)
{
    lineEdit = new QLineEdit(this);
}

GuiTest::~GuiTest()
{

}

void GuiTest::test_case1()
{
    //    QFETCH(QTestEventList,e);
    //    QLineEdit lineEdit;
    //    e.simulate(&lineEdit);
    //    QVERIFY(lineEdit.text().isEmpty());


    //        QLineEdit lineEdit;
    //    QTest::keyClicks(&lineEdit, "hi KDE");
    //    QCOMPARE(lineEdit.text(),"hi KDE");
    //    QVERIFY2(true,"Failure");

    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    events.simulate(lineEdit);

    QCOMPARE(lineEdit->text(), expected);

    //    QTestEventList events;
    //    events.addKeyClick('a');
    //    events.addKeyClick(Qt::Key_Backspace);
    //    events.addDelay(200);

    //    QLineEdit *lineEdit = new QLineEdit(myParent);
    //    /* ~ 중간 표시 생략 ~ */
    //    events.simulate(lineEdit);
    //    QCOMPARE(lineEdit->text(),"");
    //    events.simulate(lineEdit);
    //    QCOMPARE(lineEdit->text()," ");

}

void GuiTest::test_case1_data()
{
    //    QTest::addColumn<QString>("string");
    //    QTest::addColumn<QString>("result");
    //    QTest::newRow("lower")<<QString("kde")<<QString("KDE");
    //    QTest::newRow("mixed")<<QString("Kde")<<QString("KDE");

    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there+back-again") << list2 << "a";

}

QTEST_MAIN(GuiTest)

#include "tst_guitest.moc"
