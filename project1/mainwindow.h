#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDebug>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
//    void circle();
//    void triangle();
//    void rectangle();

private slots:


    //void on_ShapeButton_triggered(QAction *arg1);

private:

  //  void createActions();


//    QAction* circleAction;
//    QAction* triangleAction;
//    QAction* rectangleAction;

    QMenu* menu;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
