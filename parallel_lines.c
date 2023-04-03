#include "parallel_lines.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Parallel Lines");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}