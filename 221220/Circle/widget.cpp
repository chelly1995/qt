#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    rectPosX=0.0f;
    rectPosY=0.0f;
    rectSize=250;

    xStep = 5.0f;
    yStep = 5.0f;

    //setWindowTitle("Hello OpenGL");
    setWindowTitle("OpenGL Point");
    resize(600,600);

    QTimer*timer = new QTimer();
    connect(timer, SIGNAL(timeout()),SLOT(timerFunction()));
    timer->start(1000/60);
}

Widget::~Widget()
{


}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,0.0);
}

void Widget::resizeGL(int w, int h)
{
    windowWidth = w;
    windowHeight= h;

    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(-1*w, w, -1*h, h, -1.0,  1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0,  1.0);

}

void Widget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);   // R,G,B 색상 : 흰색


    GLushort arPat[] = {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa,
                        0x33ff, 0x33ff, 0x33ff, 0x57ff, 0x57ff};

    GLint arFac[] = {1, 2, 3, 4, 1, 2, 3, 1, 2};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);   // R,G,B 색상 : 흰색

    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx = 0;
    for(y=0.8; y>-0.8; y-=0.2){
        glLineStipple(arFac[idx],arPat[idx]);
        glBegin(GL_LINES);
        glVertex2f(-0.8,y);
        glVertex2f(0.8,y);
        glEnd();
        idx++;
    }





    // 선의 두께
//    GLfloat w = 1, y;
//    for(y=0.8; y>-0.8; y-=0.2){
//        glLineWidth(w++);   // 라인 두께
//        glBegin(GL_LINES);
//        glVertex2f(-0.8,y); // 라인 시작 범위 지정
//        glVertex2f(0.8,y);  // 라인 끝 범위 지정
//        glEnd();

//    };


    // 원

//    double rad=0.5;
//    glLineWidth(20.0);  // 선의 크기 조정
//    glEnable(GL_LINE_SMOOTH);   // 선 안티알리아싱
//    glBegin(GL_LINE_LOOP);

//    for(int i=0; i<360; i++){
//        double angle, x, y;
//        angle=i*3.141592/180;
//        x=rad*cos(angle);
//        y=rad*sin(angle);
//        glVertex2f(x,y);

//    }

//    glPointSize(10.0);  // 점의 크기 조정
//    glEnable(GL_POINT_SMOOTH);  // 점을 동그랗게 -> 안티알리아싱 지정

    //glBegin(GL_POLYGON);
    //  glBegin(GL_POINTS);
//    glBegin(GL_LINES);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i=0; i<6; i++){
//        glVertex2f(x,y);
//        x += 0.3;
//        y*=-1;

//    };


    // 사각형
//    glVertex3f(rectPosX,rectPosY,0.0);
//    glVertex3f(rectPosX,rectPosY-rectSize,0.0);
//    glVertex3f(rectPosX+rectSize,rectPosY-rectSize,0.0);
//    glVertex3f(rectPosX+rectSize,rectPosY,0.0);

    //정육각형

//    glVertex2f(0.0, 0.6);
//    glColor3f(1.0,0.0,0.0);
//    glVertex2f(-0.6, 0.0);
//    glVertex2f(-0.4, -0.6);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(0.4, -0.6);
//    glColor3f(0.0,0.0,1.0);
//    glVertex2f(0.6, 0.0);


      // 점

//      glVertex2f(0.0, 0.5);
//      glVertex2f(-0.5, -0.5);
//      glVertex2f(0.5, -0.5);

    glEnd();

    glFlush();
}



void Widget::timerFunction()
{
    if(rectPosX>windowWidth-rectSize||rectPosX<-windowWidth)
    xStep=-xStep;

    if(rectPosY>windowHeight||rectPosY< -windowHeight+rectSize)
    yStep= -yStep;

    rectPosX+=xStep;
    rectPosY+=yStep;

    if(rectPosX>(windowWidth-rectSize+xStep))
        rectPosX=windowWidth-rectSize-1;
    else if(rectPosX<-(windowWidth+xStep))
        rectPosX= -windowWidth-1;

    if(rectPosY>(windowHeight+yStep))
        rectPosY=windowHeight-1;
    else if(rectPosY<-(windowHeight-rectSize+yStep))
        rectPosY= -windowHeight+rectSize-1;

    repaint();
}
