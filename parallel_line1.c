#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float d;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.7);
    glVertex2f(0.0, -0.5);
    glVertex2f(d, 0.7);
    glVertex2f(d, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    printf("Enter the distance between the lines:\t");
    scanf("%f", &d);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("LINE");
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}