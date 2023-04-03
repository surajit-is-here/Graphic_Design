#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES); 
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 2.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1920,1050);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("LINE");
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}