#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<unistd.h>
float x , y , r;

void display()
{
    glClearColor(0.0 , 0.0 , 0.0 , 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D( 0.0 , 1080.0 , 0.0 , 720.0 );
    float x1 , y1 , d = 1 - r;
    x1 = 0;
    y1 = r;

    glBegin(GL_POINTS);
    glVertex2i(x+x1,y+y1);
    glVertex2i(x+x1,y-y1);
    glVertex2i(x-x1,y+y1);
    glVertex2i(x-x1,y-y1);
    glVertex2i(x+y1,y+x1);
    glVertex2i(x+y1,y-x1);
    glVertex2i(x-y1,y+x1);
    glVertex2i(x-y1,y-x1);
    glEnd();
    glFlush();

    while( x1 < y1)
    {
        x1+=1;
        if( d < 0)
            d =  d + 2 * x1 + 1;
        else
        {
            d =  d + 2 * ( x1 - y1) + 1;
            y1 = y1 - 1; 
        }
        glBegin(GL_POINTS);
        glVertex2i(x+x1,y+y1);
        glVertex2i(x+x1,y-y1);
        glVertex2i(x-x1,y+y1);
        glVertex2i(x-x1,y-y1);
        glVertex2i(x+y1,y+x1);
        glVertex2i(x+y1,y-x1);
        glVertex2i(x-y1,y+x1);
        glVertex2i(x-y1,y-x1);
        glEnd();
        glFlush();
    }
}

int main(int argc, char** argv)
{
    printf("Enter value of X: ");
    scanf("%f",&x);
    printf("Enter value of Y: ");
    scanf("%f",&y);
    printf("Enter value of radius: ");
    scanf("%f",&r);

    glutInit(&argc , argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(0 , 0);
    glutCreateWindow("Circle Drawing");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}