#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bDepthTest = GL_TRUE;
    bCullFace = GL_FALSE;
    polygonMode = GL_FILL;
    shadeMode = GL_FLAT;


    setWindowTitle("Hello OpenGL");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(shadeMode);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0, 0.0, -0.8);
        glColor3f(1,0,0);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);

        glColor3f(1,1,0);
        glVertex2f(-0.5, -0.5);

        glColor3f(0,1,0);
        glVertex2f(0.5, -0.5);

        glColor3f(0,0,1);
        glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(0, w/this->size().width(), 0, h/this->size().height(), -1, 1);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_1:
        polygonMode = GL_POINT;
        break;
    case Qt::Key_2:
        polygonMode = GL_LINE;
        break;
    case Qt::Key_3:
        polygonMode = GL_FILL;
        break;
    case Qt::Key_4:
        shadeMode = GL_FILL;
        break;
    case Qt::Key_5:
        shadeMode = GL_SMOOTH;
        break;
    case Qt::Key_6:
        shadeMode = GL_FLAT;
        break;
    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;
    }

    QString str = QString("Pyramid3D : x: %1, y: %2, z: %3").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);

    update();

}
