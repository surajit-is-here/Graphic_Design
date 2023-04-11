#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "DDALine.h"

void myInit(void);
void draw(void);
void point(int, int);
void polygon(int *, int *);
void reflection();

int n, a, b, xb, yb, xe, ye, ch1, ch2;
int *x, *y, *p, *q;

int main(int argc, char **argv)
{
    printf("Enter no. of vertices :\t");
    scanf("%d", &n);

    x = (int *)calloc(n, sizeof(int));
    y = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter x%d & y%d :\n", i + 1, i + 1);
        scanf("%d %d", x + i, y + i);
    }

    printf("\nReflection along :-\n1. Axis\t2. Point\t3. Arbitrary line:\t");
    scanf("%d", &ch1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Reflection");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void draw(void)
{
    glColor3f(1.0, 1.0, 1.0);
    line(0, -350, 0, 350);
    line(-530, 0, 530, 0);
    glColor3f(1.0, 0.0, 0.0);
    polygon(x, y);
    reflection();
}

void point(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glVertex2i(x - 1, y);
    glVertex2i(x + 1, y);
    glVertex2i(x, y - 1);
    glVertex2i(x, y + 1);
    glEnd();
    glFlush();
}
void polygon(int *x, int *y)
{
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            line(x[i], y[i], x[i + 1], y[i + 1]);
            continue;
        }
        line(x[i], y[i], x[0], y[0]);
    }
}
void reflection()
{
    float c, m;
    p = (int *)calloc(n, sizeof(int));
    q = (int *)calloc(n, sizeof(int));

    switch (ch1)
    {
    case 1:
        printf("\n1. along X-axis\t2. along Y-axis:\t");
        scanf("%d", &ch2);
        if (ch2 == 1)
        {
            printf("Enter Y :\n");
            scanf("%d", &yb);
            glColor3f(1, 1, 0);
            line(-530, yb, 530, yb);
            for (int i = 0; i < n; i++)
            {
                p[i] = x[i];
                q[i] = 2 * yb - y[i];
            }
        }
        if (ch2 == 2)
        {
            printf("Enter X :\n");
            scanf("%d", &xb);
            glColor3f(1, 1, 0);
            line(xb, -350, xb, 350);
            for (int i = 0; i < n; i++)
            {
                p[i] = 2 * xb - x[i];
                q[i] = y[i];
            }
        }
        break;
    case 2:
        printf("Enter coordinates x & y :\t");
        scanf("%d %d", &xb, &yb);
        glColor3f(1, 1, 0);
        glPointSize(5.0);
        point(xb, yb);
        for (int i = 0; i < n; i++)
        {
            p[i] = 2 * xb - x[i];
            q[i] = 2 * yb - y[i];
        }
        break;
    case 3:
        printf("Enter the coordinates of the endpoints of the line:\t");
        scanf("%d%d%d%d",&xb,&yb,&xe,&ye);

        m = (ye - yb) / (float)(xe - xb);
        c = ye - m * xe;

        glColor3f(1, 1, 0);
        line(xb, yb, xe, ye);
        for (int i = 0; i < n; i++)
        {
            p[i] = (1 - m * m) * x[i] / (m * m + 1) + 2 * m * y[i] / (m * m + 1) - 2 * c * m / (m * m + 1);
            q[i] = 2 * m * x[i] / (m * m + 1) + (m * m - 1) * y[i] / (m * m + 1) + 2 * c / (m * m + 1);
        }
        break;
    default:
        printf("Invalid choice");
        exit(0);
    }
    glPointSize(2.0);
    polygon(p, q);
}