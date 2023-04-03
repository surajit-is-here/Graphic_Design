#include<stdlib.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<unistd.h>



void midpoint(float x1, float y1,float x2,float y2)
{ 
    float d , x , y , dx = x2 - x1 , dy = y2 - y1;

    if( dy <= dx )
    {
        d = dy - dx/2;
        x = x1 , y = y1;
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
            glBegin(GL_POINTS);
            glVertex2i( x , y);
            glEnd();
            glFlush();
        }
    }

    else
    {
        d = dx - dy/2;
        x = x1 , y = y1;
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
            glBegin(GL_POINTS);
            glVertex2i( x , y);
            glEnd();
            glFlush();
        }
    }    
}
void coordinate(float x1, float y1)
{
    midpoint(-1000.0, y1, 1000.0, y1);
    midpoint( x1, -1000.0, x1, 1000.0);
}