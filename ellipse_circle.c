#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "mid_point.h"

void draw(void);
void myInit(void);
void ellipse(int, int, int, int);
void plot(int, int);
void circle(int r);

int a, b, rx, ry;

int main(int argc, char **argv)
{
	printf("Enter coordinates of the center :\n");
	scanf("%d %d", &a, &b);
	printf("Enter Rx & Ry :\n");
	scanf("%d %d", &rx, &ry);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1920, 1050);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ellipse Drawing");
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
	coordinate(a, b);
	ellipse(a, b, rx, ry);
	circle(rx);
	circle(ry);
}

void ellipse(int x1, int y1, int r1, int r2)
{
	int rx2 = r1 * r1;
	int ry2 = r2 * r2;
	int Trx2 = 2 * rx2;
	int Try2 = 2 * ry2;
	int p;
	int x = 0;
	int y = r2;
	int px = 0;
	int py = Trx2 * y;
	plot(x, y);

	p = (int)(ry2 - (rx2 * r2) + (0.25 * rx2));
	while (px < py)
	{
		x++;
		px += Try2;
		if (p < 0)
		{
			p += ry2 + px;
		}
		else
		{
			y--;
			py -= Trx2;
			p += ry2 + px - py;
		}
		plot(x, y);
	}

	p = (int)(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
	while (y > 0)
	{
		y--;
		py -= Trx2;
		if (p > 0)
		{
			p += rx2 - py;
		}
		else
		{
			x++;
			px += Try2;
			p += rx2 + px - py;
		}
		plot(x, y);
	}
}

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(a + x, b + y);
	glVertex2i(a - x, b + y);
	glVertex2i(a + x, b - y);
	glVertex2i(a - x, b - y);
	glEnd();
	glFlush();
}
void circle(int r)
{
	float x1, y1, d = 1 - r;
	x1 = 0;
	y1 = r;

	glBegin(GL_POINTS);
	glVertex2i(a + x1, b + y1);
	glVertex2i(a + x1, b - y1);
	glVertex2i(a - x1, b + y1);
	glVertex2i(a - x1, b - y1);
	glVertex2i(a + y1, b + x1);
	glVertex2i(a + y1, b - x1);
	glVertex2i(a - y1, b + x1);
	glVertex2i(a - y1, b - x1);
	glEnd();
	glFlush();

	while (x1 < y1)
	{
		x1 += 1;
		if (d < 0)
			d = d + 2 * x1 + 1;
		else
		{
			d = d + 2 * (x1 - y1) + 1;
			y1 = y1 - 1;
		}
		glBegin(GL_POINTS);
		glVertex2i(a + x1, b + y1);
		glVertex2i(a + x1, b - y1);
		glVertex2i(a - x1, b + y1);
		glVertex2i(a - x1, b - y1);
		glVertex2i(a + y1, b + x1);
		glVertex2i(a + y1, b - x1);
		glVertex2i(a - y1, b + x1);
		glVertex2i(a - y1, b - x1);
		glEnd();
		glFlush();
	}
}