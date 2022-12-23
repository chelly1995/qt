#include "widget.h"
#include "qtglut.h"

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 0, yAngle=0, zAngle=0;

    setWindowTitle("OpenGL Human-Body");
    resize(300,300);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);

}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-700.0, 700.0, 700.0, -700.0, 700.0);
    glClearColor(0.5, 0.5, 0.5, 0.0);   // 회색

}


void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    // 카메라 셋팅(시점조정관련)
    gluLookAt(50,50,50,0,0,0,0,1,0);

    // 몸통
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(1,1,0.5);

    // 몸의 1/2만큼 상향이동
    glTranslatef(0,128/2-10,0);
    glutSolidCube(128);
    glPopMatrix();
}

void Widget::keyPressEvent(QKeyEvent*event)
{




}
