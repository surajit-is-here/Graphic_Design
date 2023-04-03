#include<stdlib.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<unistd.h>

float x1 , x2 , y11 , y2 ;

void midpoint()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
    glColor3ub(255,0,0);
    
    float d , x , y , dx = x2 - x1 , dy = y2 - y11;

    if( dy <= dx )
    {
        d = dy - dx/2;
        x = x1 , y = y11;
        glBegin(GL_POINTS);
        glVertex2i( x ,y );
        glEnd();
        glFlush();

        while( x < x2)
        {
            x = x + 1;

            if( d < 0)
                d = d + dy;
            else
            {
                d = d + dy - dx;
                y = y + 1;
            }
            sleep(0.9);

            glBegin(GL_POINTS);
            glVertex2i( x , y);
            glEnd();
            glFlush();
        }
    }

    else if(dx < dy)
    {
        d = dx - dy/2;
        x = x1 , y = y11;
        glBegin(GL_POINTS);
        glVertex2i( x ,y );
        glEnd();
        glFlush();

        while( y < y2)
        {
            y = y + 1;

            if( d < 0)
                d = d + dx;
            else
            {
                d = d + dx - dy;
                x = x + 1;
            }
            sleep(0.9);

            glBegin(GL_POINTS);
            glVertex2i( x , y);
            glEnd();
            glFlush();
        }
    }
    
}
int main( int argc , char **argv)
{
    printf("Value of x1 : ");
    scanf("%f", & x1);
    printf("Value of y1 : ");
    scanf("%f", & y11);
    printf("Value of x2 : ");
    scanf("%f", & x2);
    printf("Value of y2 : ");
    scanf("%f", & y2);

    glutInit(&argc , argv);
    glutInitWindowSize( 1080 , 720 );
    glutInitWindowPosition(0 , 0 );
    glutCreateWindow("Midpoint Line Drawing");
    glutDisplayFunc(midpoint);
    glutMainLoop();
    
    return 0;
}