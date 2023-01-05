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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiondraw_line;
    QAction *actiondraw_shape;
    QAction *actionmemo;
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QToolButton *ShapeButton;
    QToolButton *ArrowButton;
    QToolButton *TextButton;
    QToolButton *StraightMeasureButton;
    QToolButton *TapeMeasureButton;
    QToolButton *protractorButton;
    QToolButton *ContrastButton;
    QToolButton *ColorInvertButton;
    QToolButton *SharpeningButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QToolButton *MemoButton;
    QToolButton *KeyboardButton;
    QLabel *Initialize_Label;
    QToolButton *DrawButton;
    QToolButton *InsertImplantButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *SaveButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QComboBox *ThicknesscomboBox;
    QToolButton *ColorButton;
    QLabel *Load_Label;
    QPushButton *LoadButton;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1216, 769);
        actiondraw_line = new QAction(MainWindow);
        actiondraw_line->setObjectName("actiondraw_line");
        actiondraw_shape = new QAction(MainWindow);
        actiondraw_shape->setObjectName("actiondraw_shape");
        actionmemo = new QAction(MainWindow);
        actionmemo->setObjectName("actionmemo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 0, 171, 701));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 169, 699));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 151, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ShapeButton = new QToolButton(layoutWidget);
        ShapeButton->setObjectName("ShapeButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/shape1.png"), QSize(), QIcon::Normal, QIcon::Off);
        ShapeButton->setIcon(icon);

        gridLayout->addWidget(ShapeButton, 0, 0, 1, 1);

        ArrowButton = new QToolButton(layoutWidget);
        ArrowButton->setObjectName("ArrowButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/arrow1.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArrowButton->setIcon(icon1);

        gridLayout->addWidget(ArrowButton, 0, 1, 1, 1);

        TextButton = new QToolButton(layoutWidget);
        TextButton->setObjectName("TextButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        TextButton->setIcon(icon2);

        gridLayout->addWidget(TextButton, 0, 2, 1, 1);

        StraightMeasureButton = new QToolButton(layoutWidget);
        StraightMeasureButton->setObjectName("StraightMeasureButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/ruler.png"), QSize(), QIcon::Normal, QIcon::Off);
        StraightMeasureButton->setIcon(icon3);

        gridLayout->addWidget(StraightMeasureButton, 1, 0, 1, 1);

        TapeMeasureButton = new QToolButton(layoutWidget);
        TapeMeasureButton->setObjectName("TapeMeasureButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/tapemeasure.png"), QSize(), QIcon::Normal, QIcon::Off);
        TapeMeasureButton->setIcon(icon4);

        gridLayout->addWidget(TapeMeasureButton, 1, 1, 1, 1);

        protractorButton = new QToolButton(layoutWidget);
        protractorButton->setObjectName("protractorButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/protractor.png"), QSize(), QIcon::Normal, QIcon::Off);
        protractorButton->setIcon(icon5);

        gridLayout->addWidget(protractorButton, 1, 2, 1, 1);

        ContrastButton = new QToolButton(layoutWidget);
        ContrastButton->setObjectName("ContrastButton");
        ContrastButton->setBaseSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/contrast.png"), QSize(), QIcon::Normal, QIcon::Off);
        ContrastButton->setIcon(icon6);

        gridLayout->addWidget(ContrastButton, 2, 0, 1, 1);

        ColorInvertButton = new QToolButton(layoutWidget);
        ColorInvertButton->setObjectName("ColorInvertButton");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/colorinvert.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColorInvertButton->setIcon(icon7);

        gridLayout->addWidget(ColorInvertButton, 2, 1, 1, 1);

        SharpeningButton = new QToolButton(layoutWidget);
        SharpeningButton->setObjectName("SharpeningButton");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/sharpening2.png"), QSize(), QIcon::Normal, QIcon::Off);
        SharpeningButton->setIcon(icon8);

        gridLayout->addWidget(SharpeningButton, 2, 2, 1, 1);

        layoutWidget1 = new QWidget(scrollAreaWidgetContents);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 140, 151, 61));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        MemoButton = new QToolButton(layoutWidget1);
        MemoButton->setObjectName("MemoButton");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/memo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MemoButton->setIcon(icon9);

        gridLayout_2->addWidget(MemoButton, 0, 0, 1, 1);

        KeyboardButton = new QToolButton(layoutWidget1);
        KeyboardButton->setObjectName("KeyboardButton");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../../../Users/KOSA/Downloads/keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        KeyboardButton->setIcon(icon10);

        gridLayout_2->addWidget(KeyboardButton, 0, 1, 1, 1);

        Initialize_Label = new QLabel(scrollAreaWidgetContents);
        Initialize_Label->setObjectName("Initialize_Label");
        Initialize_Label->setGeometry(QRect(10, 570, 131, 21));
        Initialize_Label->setBaseSize(QSize(40, 60));
        QFont font;
        font.setPointSize(11);
        Initialize_Label->setFont(font);
        DrawButton = new QToolButton(scrollAreaWidgetContents);
        DrawButton->setObjectName("DrawButton");
        DrawButton->setGeometry(QRect(10, 260, 151, 31));
        InsertImplantButton = new QToolButton(scrollAreaWidgetContents);
        InsertImplantButton->setObjectName("InsertImplantButton");
        InsertImplantButton->setGeometry(QRect(10, 300, 151, 31));
        layoutWidget2 = new QWidget(scrollAreaWidgetContents);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 600, 168, 81));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName("pushButton");
        pushButton->setBaseSize(QSize(40, 40));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setBaseSize(QSize(40, 40));
        pushButton_3->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        SaveButton = new QPushButton(layoutWidget2);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setFont(font1);

        verticalLayout->addWidget(SaveButton);

        layoutWidget3 = new QWidget(scrollAreaWidgetContents);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(11, 210, 151, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ThicknesscomboBox = new QComboBox(layoutWidget3);
        ThicknesscomboBox->addItem(QString());
        ThicknesscomboBox->addItem(QString());
        ThicknesscomboBox->setObjectName("ThicknesscomboBox");
        ThicknesscomboBox->setFont(font1);

        horizontalLayout->addWidget(ThicknesscomboBox);

        ColorButton = new QToolButton(layoutWidget3);
        ColorButton->setObjectName("ColorButton");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../build-project1-Desktop_Qt_6_4_1_MSVC2019_64bit-Debug/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColorButton->setIcon(icon11);

        horizontalLayout->addWidget(ColorButton);

        Load_Label = new QLabel(scrollAreaWidgetContents);
        Load_Label->setObjectName("Load_Label");
        Load_Label->setGeometry(QRect(10, 500, 101, 16));
        Load_Label->setFont(font);
        LoadButton = new QPushButton(scrollAreaWidgetContents);
        LoadButton->setObjectName("LoadButton");
        LoadButton->setGeometry(QRect(10, 530, 151, 31));
        LoadButton->setFont(font1);
        scrollArea->setWidget(scrollAreaWidgetContents);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(190, 10, 1011, 691));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1216, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

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
        TextButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        StraightMeasureButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        TapeMeasureButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        protractorButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ContrastButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColorInvertButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        SharpeningButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        MemoButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        KeyboardButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        Initialize_Label->setText(QCoreApplication::translate("MainWindow", "Initialize", nullptr));
        DrawButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        InsertImplantButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "All", nullptr));
        SaveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        ThicknesscomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Thick", nullptr));
        ThicknesscomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Thin", nullptr));

        ColorButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        Load_Label->setText(QCoreApplication::translate("MainWindow", "Image Load", nullptr));
        LoadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
