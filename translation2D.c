#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "mid_point.h"

float points[4],tf[2];

void display();

int main(int argc, char** argv)
{
    printf("Enter the coordinate of the endpoints of the line:\t");
    scanf("%f%f%f%f",&points[0],&points[1],&points[2],&points[3]);
    printf("Enter the translation factor:\t");
    scanf("%f%f",&tf[0],&tf[1]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1920,1050);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Original(GREEN) Translated(RED)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(points[0],points[1]);
    glVertex2f(points[2],points[3]);
    points[0]+=tf[0];
    points[1]+=tf[1];
    points[2]+=tf[0];
    points[3]+=tf[1];
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(points[0],points[1]);
    glVertex2f(points[2],points[3]);
    glEnd();
    glFlush();
}