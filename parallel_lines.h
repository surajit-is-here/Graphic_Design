#include <GL/glut.h>
#include<stdio.h>

float d=0.53;
void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.7);
    glVertex2f(0.0, -0.5);
    glVertex2f(d, 0.7);
    glVertex2f(d, -0.5);
    glColor3ub(155,5,0);
    glEnd();
    glFlush();
}
