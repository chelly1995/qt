#include "widget.h"

#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

    xAngle = 0, yAngle =0, zAngle = 0;
    EnvMode = GL_REPLACE;
    TexFilter = GL_LINEAR;

    setWindowTitle("OpenGL TextureMapping");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{

    glViewport(0,0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
}


void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLubyte *data;

    glClear(GL_COLOR_BUFFER_BIT);

    // 텍스처 이미지 준비
    glEnable(GL_TEXTURE_2D);
    QImage*image = new QImage("texturemapping.bmp");
    data = image->bits();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,image->width(), image->height(), 0,GL_RGB, GL_UNSIGNED_BYTE, data);

    // 텍스처 환경 설정
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,EnvMode);

    // 텍스처 필터 설정
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,TexFilter);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,TexFilter);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    // 아랫면 흰 바닥면
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glTexCoord2f(0.0,1.0);
    glVertex2f(-0.5,0.5);
    glTexCoord2f(1.0,1.0);
    glVertex2f(0.5,0.5);
    glTexCoord2f(0.0,0.0);
    glVertex2f(-0.5,-0.5);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    // 위쪽 빨간면
    glColor3f(1,0,0);
    glTexCoord2f(0.5,0.5);
    glVertex3f(0.0,0.0,-0.8);
    glTexCoord2f(1.0,1.0);
    glVertex2f(0.5,0.5);
    glTexCoord2f(0.0,1.0);
    glVertex2f(-0.5,0.5);

    // 왼쪽 노란면
    glColor3f(1,1,0);
    glTexCoord2f(0.0,0.0);
    glVertex2f(-0.5,-0.5);

    // 아래쪽 초록면
    glColor3f(0,1,0);
    glTexCoord2f(1.0,0.0);
    glVertex2f(0.5, -0.5);

    // 오른쪽 파란면
    glColor3f(0,0,1);
    glTexCoord2f(1.0,1.0);
    glVertex2f(0.5,0.5);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent*event)
{

    switch(event->key()){

    case Qt::Key_A:
        EnvMode = GL_REPLACE;
        break;

    case Qt::Key_S:
        EnvMode = GL_MODULATE;
        break;


    case Qt::Key_D:
        EnvMode = GL_ADD;
        break;

    case Qt::Key_F:
        TexFilter = GL_NEAREST;
        break;

    case Qt::Key_G:
        TexFilter = GL_LINEAR;
        break;


    case Qt::Key_1:             // Scissor ON
        yAngle += 2;
        break;

    case Qt::Key_2:             // Scissor OFF
        yAngle -= 2;
        break;

    case Qt::Key_3:             // Stencil ON
        xAngle += 2;
        break;

    case Qt::Key_4:             // Stencil OFF
        xAngle -= 2;
        break;

    case Qt::Key_5:             // Equal
        zAngle += 2;
        break;

    case Qt::Key_6:             // Not Equal
        zAngle -= 2;
        break;

    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;


    };

    QString str = QString("x:%.1f, y:%.1f,z:%.1f").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);


    update();
}