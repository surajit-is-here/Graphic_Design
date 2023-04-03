//DDA algorithm using c
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {
    glColor3f(0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
      glVertex3f(-100.0,0.0f,0.0f);
      glVertex3f(100.0,0.0f,0.0f);
glBegin(GL_LINES);
      glVertex3f(0.0,-100.0f,0.0f);
      glVertex3f(0.0,100.0f,0.0f);
    glEnd();
    glFlush();
}

void myInit (void) {
    glPointSize(3.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (400, 400);
  glutInitWindowPosition (200,100);
  glutCreateWindow("");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}