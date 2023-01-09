#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDialog>

class ScratchPad;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ScratchPad *m_scratchPad;

private slots:
    void on_toolButton1_clicked();

    void on_toolButton_2_clicked();

    void on_LoadButton_clicked();



    void on_ColorButton_clicked();

private:
    Ui::MainWindow *ui;

    //    QGraphicsRectItem *item;
    //    QGraphicsEllipseItem *ellipse;
    //    QGraphicsRectItem *rectangle;
    //    QGraphicsScene *scene;

    //    void resizeImage(QImage*image, const QSize&newSize);

    //    bool modified;
    //    QImage image;
    //    QPointF prevPos;
    //    QColor paintColor;
    //    qreal paintSize;
    QGraphicsScene*scene;
    QString mResourceDir;

protected:
    //    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;
    //    void resizeEvent(QResizeEvent *event)Q_DECL_OVERRIDE;

    //    void mousePressEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    //    void mouseMoveEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    //    void mouseReleaseEvent(QMouseEvent*event)Q_DECL_OVERRIDE;


};
#endif // MAINWINDOW_H
