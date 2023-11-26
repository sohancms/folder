#include <GL/glut.h>
#include <iostream>

int x1, y1, x2, y2;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 100, 0, 100); // Set the 2D coordinate system
}

void set_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    printf("%d %d \n", x, y);
    glEnd();
}
void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int incx = 1, incy = 1;

    if (x2 < x1)
        incx = -1;
    if (y2 < y1)
        incy = -1;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (dx > dy)
    {
        // Slope less than 1
        set_pixel(x, y);
        int p = 2 * dy - dx;
        printf("%d\n ", p);
        for (int i = 0; i < dx; i++)
        {
            if (p >= 0)
            {
                y += incy;
                p += 2 * (dy - dx);
                printf("%d ", p);
            }
            else
            {
                p += 2 * dy;
                printf("%d ", p);
            }
            x += incx;
            set_pixel(x, y);
        }
    }
    else
    {
        // Slope greater than 1
        set_pixel(x, y);
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (p >= 0)
            {
                x += incx;
                p += 2 * (dx - dy);
            }
            else
                p += 2 * dx;
            y += incy;
            set_pixel(x, y);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0); // Set line color to white
    glPointSize(3.0);
    glBegin(GL_POINTS);
    bresenhamLine(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char **argv)
{
    std::cout << "Enter x1 y1 x2 y2: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);     // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("Bresenham Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
