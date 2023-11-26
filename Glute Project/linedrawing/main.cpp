#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
float x1, x2, y1, y2, xinc, yinc;
float dx, dy, step, m, i, x, y;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.5, 1.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    dx = (x2 - x1);
    dy = (y2 - y1);
    m = abs(dy) / abs(dx);
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }
    if (m <= 1 && dx > 0 && dy > 0)
    {
        xinc = 1;
        yinc = m;
    }
    else if (m <= 1 && dx <= 0 && dy > 0)
    {
        xinc = -1;
        yinc = m;
    }
    else if (m <= 1 && dx > 0 && dy <= 0)
    {
        xinc = 1;
        yinc = -m;
    }
    else if (m <= 1 && dx <= 0 && dy <= 0)
    {
        xinc = -1;
        yinc = -m;
    }
    else if (m > 1 && dx > 0 && dy > 0)
    {
        xinc = (1 / m);
        yinc = 1;
    }
    else if (m > 1 && dx <= 0 && dy > 0)
    {
        xinc = -(1 / m);
        yinc = 1;
    }
    else if (m > 1 && dx > 0 && dy <= 0)
    {
        xinc = (1 / m);
        yinc = -1;
    }
    else if (m > 1 && dx <= 0 && dy <= 0)
    {
        xinc = -(1 / m);
        yinc = -1;
    }
    else if (m < 0)
    {
        printf("error");
    }
    x = x1;
    y = y1;
    for (i = 1; i <= step; i++)
    {
        x = x + xinc;
        y = y + yinc;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();
}
int main(int argc, char **argv)
{
    printf("Enter the value of x1, y1 : ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the value of x2, y2 : ");
    scanf("%f %f", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm:");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
