#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDialog>

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


private slots:
       // void LoadPushButton_clicked();
        //void on_imageLoad_clicked();

        void on_LoadButton_clicked();

        void circle();
        void triangle();
        void rectangle();

private:

    QMenu* shapemenu;
    QMenu* sharpeningmenu;

    QAction* circleAction;
    QAction* triangleAction;
    QAction* rectangleAction;

    QString mResourceDir;

    QGraphicsScene*scene;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
