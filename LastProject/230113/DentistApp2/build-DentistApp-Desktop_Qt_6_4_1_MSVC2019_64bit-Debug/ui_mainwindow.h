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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionRedo;
    QAction *actionUndo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_13;
    QSplitter *splitter3;
    QSplitter *splitter10;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *lineEdit;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *BrushtoolButton;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *CircletoolButton;
    QToolButton *RectangletoolButton;
    QToolButton *TriangletoolButton;
    QToolButton *ArrowtoolButton;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *RulertoolButton;
    QToolButton *MeasuretoolButton;
    QToolButton *ProtractortoolButton;
    QToolButton *ColortoolButton;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *ColortoolButton_9;
    QToolButton *ColortoolButton_7;
    QToolButton *ColortoolButton_8;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *SharpentoolButton;
    QToolButton *ColortoolButton_10;
    QToolButton *ColortoolButton_12;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *ColortoolButton_6;
    QToolButton *ColortoolButton_11;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *patientTableView;
    QSplitter *splitter2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_14;
    QSplitter *splitter;
    QMdiArea *mdiArea;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_2;
    QTreeWidget *treeWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1248, 681);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_13 = new QVBoxLayout(centralwidget);
        verticalLayout_13->setObjectName("verticalLayout_13");
        splitter3 = new QSplitter(centralwidget);
        splitter3->setObjectName("splitter3");
        splitter3->setOrientation(Qt::Horizontal);
        splitter10 = new QSplitter(splitter3);
        splitter10->setObjectName("splitter10");
        splitter10->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter10);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout_12 = new QVBoxLayout(layoutWidget);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_12->addWidget(lineEdit);

        toolBox = new QToolBox(layoutWidget);
        toolBox->setObjectName("toolBox");
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 229, 282));
        verticalLayout_11 = new QVBoxLayout(page);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(page);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BrushtoolButton = new QToolButton(page);
        BrushtoolButton->setObjectName("BrushtoolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/draw2.png"), QSize(), QIcon::Normal, QIcon::Off);
        BrushtoolButton->setIcon(icon);

        horizontalLayout_4->addWidget(BrushtoolButton);

        spinBox = new QSpinBox(page);
        spinBox->setObjectName("spinBox");

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        CircletoolButton = new QToolButton(page);
        CircletoolButton->setObjectName("CircletoolButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/circle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        CircletoolButton->setIcon(icon1);
        CircletoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(CircletoolButton);

        RectangletoolButton = new QToolButton(page);
        RectangletoolButton->setObjectName("RectangletoolButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/triangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        RectangletoolButton->setIcon(icon2);
        RectangletoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(RectangletoolButton);

        TriangletoolButton = new QToolButton(page);
        TriangletoolButton->setObjectName("TriangletoolButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/rectangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        TriangletoolButton->setIcon(icon3);
        TriangletoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(TriangletoolButton);

        ArrowtoolButton = new QToolButton(page);
        ArrowtoolButton->setObjectName("ArrowtoolButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/arrow3.png"), QSize(), QIcon::Normal, QIcon::Off);
        ArrowtoolButton->setIcon(icon4);
        ArrowtoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(ArrowtoolButton);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        RulertoolButton = new QToolButton(page);
        RulertoolButton->setObjectName("RulertoolButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/ruler.png"), QSize(), QIcon::Normal, QIcon::Off);
        RulertoolButton->setIcon(icon5);
        RulertoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(RulertoolButton);

        MeasuretoolButton = new QToolButton(page);
        MeasuretoolButton->setObjectName("MeasuretoolButton");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Image/measure.png"), QSize(), QIcon::Normal, QIcon::Off);
        MeasuretoolButton->setIcon(icon6);
        MeasuretoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(MeasuretoolButton);

        ProtractortoolButton = new QToolButton(page);
        ProtractortoolButton->setObjectName("ProtractortoolButton");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Image/progtractor.png"), QSize(), QIcon::Normal, QIcon::Off);
        ProtractortoolButton->setIcon(icon7);
        ProtractortoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(ProtractortoolButton);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        ColortoolButton = new QToolButton(page);
        ColortoolButton->setObjectName("ColortoolButton");
        ColortoolButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton->setIcon(icon8);
        ColortoolButton->setIconSize(QSize(150, 15));

        verticalLayout_5->addWidget(ColortoolButton);


        verticalLayout_11->addLayout(verticalLayout_5);

        toolBox->addItem(page, QString::fromUtf8("Draw"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 229, 282));
        verticalLayout_10 = new QVBoxLayout(page_3);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");

        verticalLayout_8->addWidget(label_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        ColortoolButton_9 = new QToolButton(page_3);
        ColortoolButton_9->setObjectName("ColortoolButton_9");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Image/colorreversal.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_9->setIcon(icon9);
        ColortoolButton_9->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(ColortoolButton_9);

        ColortoolButton_7 = new QToolButton(page_3);
        ColortoolButton_7->setObjectName("ColortoolButton_7");
        ColortoolButton_7->setIcon(icon9);
        ColortoolButton_7->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(ColortoolButton_7);

        ColortoolButton_8 = new QToolButton(page_3);
        ColortoolButton_8->setObjectName("ColortoolButton_8");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Image/reversal.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_8->setIcon(icon10);
        ColortoolButton_8->setIconSize(QSize(30, 30));

        horizontalLayout_7->addWidget(ColortoolButton_8);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        SharpentoolButton = new QToolButton(page_3);
        SharpentoolButton->setObjectName("SharpentoolButton");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Image/sharpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        SharpentoolButton->setIcon(icon11);
        SharpentoolButton->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(SharpentoolButton);

        ColortoolButton_10 = new QToolButton(page_3);
        ColortoolButton_10->setObjectName("ColortoolButton_10");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Image/bright.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_10->setIcon(icon12);
        ColortoolButton_10->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(ColortoolButton_10);

        ColortoolButton_12 = new QToolButton(page_3);
        ColortoolButton_12->setObjectName("ColortoolButton_12");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Image/panning.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_12->setIcon(icon13);
        ColortoolButton_12->setIconSize(QSize(30, 30));

        horizontalLayout_8->addWidget(ColortoolButton_12);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        ColortoolButton_6 = new QToolButton(page_3);
        ColortoolButton_6->setObjectName("ColortoolButton_6");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Image/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_6->setIcon(icon14);
        ColortoolButton_6->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(ColortoolButton_6);

        ColortoolButton_11 = new QToolButton(page_3);
        ColortoolButton_11->setObjectName("ColortoolButton_11");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Image/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        ColortoolButton_11->setIcon(icon15);
        ColortoolButton_11->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(ColortoolButton_11);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(page_3);
        label_5->setObjectName("label_5");

        verticalLayout_7->addWidget(label_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_10->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_10->addWidget(pushButton_4);


        verticalLayout_7->addLayout(horizontalLayout_10);


        verticalLayout_9->addLayout(verticalLayout_7);


        verticalLayout_10->addLayout(verticalLayout_9);

        toolBox->addItem(page_3, QString::fromUtf8("Image Processing"));

        verticalLayout_12->addWidget(toolBox);

        splitter10->addWidget(layoutWidget);
        patientTableView = new QTableView(splitter10);
        patientTableView->setObjectName("patientTableView");
        patientTableView->setAlternatingRowColors(true);
        patientTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter10->addWidget(patientTableView);
        patientTableView->verticalHeader()->setDefaultSectionSize(15);
        splitter3->addWidget(splitter10);
        splitter2 = new QSplitter(splitter3);
        splitter2->setObjectName("splitter2");
        splitter2->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(splitter2);
        layoutWidget1->setObjectName("layoutWidget1");
        verticalLayout_14 = new QVBoxLayout(layoutWidget1);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget1);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        mdiArea = new QMdiArea(splitter);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setViewMode(QMdiArea::TabbedView);
        splitter->addWidget(mdiArea);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName("layoutWidget2");
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(layoutWidget2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");

        verticalLayout_2->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(layoutWidget2);
        toolButton->setObjectName("toolButton");

        horizontalLayout->addWidget(toolButton);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(layoutWidget2);
        toolButton_2->setObjectName("toolButton_2");

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        treeWidget_2 = new QTreeWidget(layoutWidget2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName("treeWidget_2");

        verticalLayout_2->addWidget(treeWidget_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        toolButton_3 = new QToolButton(layoutWidget2);
        toolButton_3->setObjectName("toolButton_3");

        horizontalLayout_2->addWidget(toolButton_3);

        horizontalSpacer_5 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        toolButton_4 = new QToolButton(layoutWidget2);
        toolButton_4->setObjectName("toolButton_4");

        horizontalLayout_2->addWidget(toolButton_4);

        horizontalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget2);

        verticalLayout_14->addWidget(splitter);

        line = new QFrame(layoutWidget1);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line);

        splitter2->addWidget(layoutWidget1);
        layoutWidget3 = new QWidget(splitter2);
        layoutWidget3->setObjectName("layoutWidget3");
        verticalLayout_15 = new QVBoxLayout(layoutWidget3);
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer);

        listWidget = new QListWidget(layoutWidget3);
        listWidget->setObjectName("listWidget");

        verticalLayout_15->addWidget(listWidget);

        splitter2->addWidget(layoutWidget3);
        splitter3->addWidget(splitter2);

        verticalLayout_13->addWidget(splitter3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1248, 17));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuMenu->menuAction());
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
        label->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        BrushtoolButton->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Figure", nullptr));
        CircletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        RectangletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        TriangletoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ArrowtoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Measure", nullptr));
        RulertoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        MeasuretoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ProtractortoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Draw", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        ColortoolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        SharpentoolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_10->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_12->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_6->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ColortoolButton_11->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Initialize", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Image Processing", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "Layout\n"
"Save", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "Layout\n"
"Clear", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
