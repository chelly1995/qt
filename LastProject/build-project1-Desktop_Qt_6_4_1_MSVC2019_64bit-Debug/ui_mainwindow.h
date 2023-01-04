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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiondraw_line;
    QAction *actiondraw_shape;
    QAction *actionmemo;
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QToolButton *ShapeButton;
    QToolButton *ArrowButton;
    QToolButton *MemoButton;
    QToolButton *StraightMeasureButton;
    QToolButton *TapeMeasureButton;
    QToolButton *protractorButton;
    QToolButton *toolButton_9;
    QToolButton *toolButton_8;
    QToolButton *toolButton_7;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actiondraw_line = new QAction(MainWindow);
        actiondraw_line->setObjectName("actiondraw_line");
        actiondraw_shape = new QAction(MainWindow);
        actiondraw_shape->setObjectName("actiondraw_shape");
        actionmemo = new QAction(MainWindow);
        actionmemo->setObjectName("actionmemo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 101, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ShapeButton = new QToolButton(widget);
        ShapeButton->setObjectName("ShapeButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/shape1.png"), QSize(), QIcon::Normal, QIcon::Off);
        ShapeButton->setIcon(icon);

        gridLayout->addWidget(ShapeButton, 0, 0, 1, 1);

        ArrowButton = new QToolButton(widget);
        ArrowButton->setObjectName("ArrowButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArrowButton->setIcon(icon1);

        gridLayout->addWidget(ArrowButton, 0, 1, 1, 1);

        MemoButton = new QToolButton(widget);
        MemoButton->setObjectName("MemoButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/memo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MemoButton->setIcon(icon2);

        gridLayout->addWidget(MemoButton, 0, 2, 1, 1);

        StraightMeasureButton = new QToolButton(widget);
        StraightMeasureButton->setObjectName("StraightMeasureButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/ruler.png"), QSize(), QIcon::Normal, QIcon::Off);
        StraightMeasureButton->setIcon(icon3);

        gridLayout->addWidget(StraightMeasureButton, 1, 0, 1, 1);

        TapeMeasureButton = new QToolButton(widget);
        TapeMeasureButton->setObjectName("TapeMeasureButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/tapemeasure.png"), QSize(), QIcon::Normal, QIcon::Off);
        TapeMeasureButton->setIcon(icon4);

        gridLayout->addWidget(TapeMeasureButton, 1, 1, 1, 1);

        protractorButton = new QToolButton(widget);
        protractorButton->setObjectName("protractorButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/protractor.png"), QSize(), QIcon::Normal, QIcon::Off);
        protractorButton->setIcon(icon5);

        gridLayout->addWidget(protractorButton, 1, 2, 1, 1);

        toolButton_9 = new QToolButton(widget);
        toolButton_9->setObjectName("toolButton_9");

        gridLayout->addWidget(toolButton_9, 2, 0, 1, 1);

        toolButton_8 = new QToolButton(widget);
        toolButton_8->setObjectName("toolButton_8");

        gridLayout->addWidget(toolButton_8, 2, 1, 1, 1);

        toolButton_7 = new QToolButton(widget);
        toolButton_7->setObjectName("toolButton_7");

        gridLayout->addWidget(toolButton_7, 2, 2, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(11, 131, 101, 61));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_10 = new QToolButton(widget1);
        toolButton_10->setObjectName("toolButton_10");

        gridLayout_2->addWidget(toolButton_10, 0, 0, 1, 1);

        toolButton_11 = new QToolButton(widget1);
        toolButton_11->setObjectName("toolButton_11");

        gridLayout_2->addWidget(toolButton_11, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        toolBar->addAction(actiondraw_line);
        toolBar->addAction(actiondraw_shape);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actiondraw_line->setText(QCoreApplication::translate("MainWindow", "draw_line", nullptr));
        actiondraw_shape->setText(QCoreApplication::translate("MainWindow", "draw_shape", nullptr));
        actionmemo->setText(QCoreApplication::translate("MainWindow", "memo", nullptr));
        ShapeButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ArrowButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        MemoButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        StraightMeasureButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        TapeMeasureButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        protractorButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_10->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_11->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
