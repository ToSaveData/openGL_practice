#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = yAngle = zAngle = 0.0;

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

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, -1, 1);

}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);


    GLdouble size = 0.1;
    GLdouble innerRadius = 0.1;
    GLdouble outerRadius = 0.2;
    GLint nsides = 5;
    GLint rings = 6;
    GLdouble radius = 0.1;
    GLint slices = 100;
    GLint stacks = 100;

    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);


//    glutWireTeapot(0.3);
    glutWireCube(size);
    glPushMatrix();
    glTranslatef(-0.2, -0.2, 0.0);
//    glutWireCube(0.4);
    glutSolidCube(size);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2, -0.2, 0.0);
//    glutWireSphere(0.3, 20, 20);
    glutWireTorus(innerRadius, outerRadius, nsides, rings);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0.2, 0.0);
//    glutWireCone(0.3, 0.6, 20, 10);
    glutSolidTorus(innerRadius, outerRadius, nsides, rings);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.2, 0.0);
//    glutWireTorus(0.1, 0.2, 20, 20);
    glutSolidSphere(radius, slices, stacks);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.2, 0.0);
    glutWireSphere(radius, slices, stacks);

    glPopMatrix();
    glFlush();

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){

    case Qt::Key_1:
        yAngle+=2;
        break;
    case Qt::Key_2:
        yAngle-=2;
        break;
    case Qt::Key_3:
        xAngle+=2;
        break;
    case Qt::Key_4:
        xAngle-=2;
        break;
    case Qt::Key_5:
        zAngle+=2;
        break;
    case Qt::Key_6:
        zAngle-=2;
        break;
    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;
    }

    QString str=QString("Pyramid 3d x: %1, y:%2 z: %3").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);
    //str.arg(xAngle,yAngle,zAngle);

    update();
}
