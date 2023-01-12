/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionRedo;
    QAction *actionUndo;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QListWidget *listWidget;
    QTreeWidget *treeWidget;
    QTreeWidget *treeWidget_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *ColortoolButton;
    QToolButton *BrushtoolButton;
    QSpinBox *spinBox;
    QToolButton *ArrowtoolButton;
    QToolButton *RectangletoolButton;
    QToolButton *CircletoolButton;
    QToolButton *TriangletoolButton;
    QToolButton *RulertoolButton;
    QToolButton *MeasuretoolButton;
    QToolButton *ProtractortoolButton;
    QWidget *page_3;
    QToolButton *ColortoolButton_6;
    QToolButton *ColortoolButton_7;
    QToolButton *ColortoolButton_8;
    QToolButton *ColortoolButton_10;
    QToolButton *ColortoolButton_11;
    QToolButton *ColortoolButton_12;
    QToolButton *SharpentoolButton;
    QLabel *label_4;
    QToolButton *ColortoolButton_9;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(938, 652);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setGeometry(QRect(180, 10, 631, 441));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(180, 460, 741, 101));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(820, 10, 111, 141));
        treeWidget_2 = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName("treeWidget_2");
        treeWidget_2->setGeometry(QRect(820, 190, 111, 192));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(850, 160, 20, 19));
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setGeometry(QRect(880, 160, 20, 19));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(830, 390, 41, 18));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(880, 390, 41, 18));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 370, 151, 192));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(10, 40, 151, 311));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 151, 263));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 38, 12));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 70, 38, 12));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 140, 38, 12));
        ColortoolButton = new QToolButton(page);
        ColortoolButton->setObjectName("ColortoolButton");
        ColortoolButton->setGeometry(QRect(10, 210, 131, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton->setIcon(icon);
        BrushtoolButton = new QToolButton(page);
        BrushtoolButton->setObjectName("BrushtoolButton");
        BrushtoolButton->setGeometry(QRect(0, 30, 91, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/draw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        BrushtoolButton->setIcon(icon1);
        spinBox = new QSpinBox(page);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(100, 30, 51, 31));
        ArrowtoolButton = new QToolButton(page);
        ArrowtoolButton->setObjectName("ArrowtoolButton");
        ArrowtoolButton->setGeometry(QRect(120, 96, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/arrow3.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArrowtoolButton->setIcon(icon2);
        RectangletoolButton = new QToolButton(page);
        RectangletoolButton->setObjectName("RectangletoolButton");
        RectangletoolButton->setGeometry(QRect(40, 96, 31, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/triangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        RectangletoolButton->setIcon(icon3);
        CircletoolButton = new QToolButton(page);
        CircletoolButton->setObjectName("CircletoolButton");
        CircletoolButton->setGeometry(QRect(0, 96, 31, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/circle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        CircletoolButton->setIcon(icon4);
        TriangletoolButton = new QToolButton(page);
        TriangletoolButton->setObjectName("TriangletoolButton");
        TriangletoolButton->setGeometry(QRect(80, 96, 31, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/rectangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        TriangletoolButton->setIcon(icon5);
        RulertoolButton = new QToolButton(page);
        RulertoolButton->setObjectName("RulertoolButton");
        RulertoolButton->setGeometry(QRect(10, 160, 31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/ruler.png"), QSize(), QIcon::Normal, QIcon::Off);
        RulertoolButton->setIcon(icon6);
        MeasuretoolButton = new QToolButton(page);
        MeasuretoolButton->setObjectName("MeasuretoolButton");
        MeasuretoolButton->setGeometry(QRect(60, 160, 31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/measure.png"), QSize(), QIcon::Normal, QIcon::Off);
        MeasuretoolButton->setIcon(icon7);
        ProtractortoolButton = new QToolButton(page);
        ProtractortoolButton->setObjectName("ProtractortoolButton");
        ProtractortoolButton->setGeometry(QRect(110, 160, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/progtractor.png"), QSize(), QIcon::Normal, QIcon::Off);
        ProtractortoolButton->setIcon(icon8);
        toolBox->addItem(page, QString::fromUtf8("Draw"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 151, 263));
        ColortoolButton_6 = new QToolButton(page_3);
        ColortoolButton_6->setObjectName("ColortoolButton_6");
        ColortoolButton_6->setGeometry(QRect(30, 130, 31, 31));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_6->setIcon(icon9);
        ColortoolButton_7 = new QToolButton(page_3);
        ColortoolButton_7->setObjectName("ColortoolButton_7");
        ColortoolButton_7->setGeometry(QRect(60, 30, 31, 31));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/colorreversal.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_7->setIcon(icon10);
        ColortoolButton_8 = new QToolButton(page_3);
        ColortoolButton_8->setObjectName("ColortoolButton_8");
        ColortoolButton_8->setGeometry(QRect(110, 30, 31, 31));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/reversal.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_8->setIcon(icon11);
        ColortoolButton_10 = new QToolButton(page_3);
        ColortoolButton_10->setObjectName("ColortoolButton_10");
        ColortoolButton_10->setGeometry(QRect(60, 80, 31, 31));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/bright.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_10->setIcon(icon12);
        ColortoolButton_11 = new QToolButton(page_3);
        ColortoolButton_11->setObjectName("ColortoolButton_11");
        ColortoolButton_11->setGeometry(QRect(90, 130, 31, 31));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_11->setIcon(icon13);
        ColortoolButton_12 = new QToolButton(page_3);
        ColortoolButton_12->setObjectName("ColortoolButton_12");
        ColortoolButton_12->setGeometry(QRect(110, 80, 31, 31));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/panning.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_12->setIcon(icon14);
        SharpentoolButton = new QToolButton(page_3);
        SharpentoolButton->setObjectName("SharpentoolButton");
        SharpentoolButton->setGeometry(QRect(10, 80, 31, 31));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("../build-DentistApp-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/sharpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        SharpentoolButton->setIcon(icon15);
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 0, 51, 21));
        ColortoolButton_9 = new QToolButton(page_3);
        ColortoolButton_9->setObjectName("ColortoolButton_9");
        ColortoolButton_9->setGeometry(QRect(10, 30, 31, 31));
        ColortoolButton_9->setIcon(icon10);
        label_5 = new QLabel(page_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 180, 51, 16));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 210, 71, 31));
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(80, 210, 71, 31));
        toolBox->addItem(page_3, QString::fromUtf8("Image Processing"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 10, 101, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 938, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addSeparator();
        toolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\354\240\200\354\236\245", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Button", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Button", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Figure", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Measure", nullptr));
        ColortoolButton->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        BrushtoolButton->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        ArrowtoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        RectangletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        CircletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        TriangletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        RulertoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        MeasuretoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ProtractortoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Draw", nullptr));
        ColortoolButton_6->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_10->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_11->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_12->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        SharpentoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        ColortoolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Initialize", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Image Processing", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
