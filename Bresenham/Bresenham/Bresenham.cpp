#include <GL/glut.h>

int x1, y1, x2, y2;

void plotPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    int dx1 = 2 * dx;
    int dy1 = 2 * dy;

    int p = dy1 - dx;

    plotPixel(x, y);

    while (x < x2) {
        x++;
        if (p >= 0) {
            y++;
            p += dy1 - dx1;
        }
        else {
            p += dy1;
        }
        plotPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    drawLine(x1, y1, x2, y2);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    printf("Masukkan koordinat titik awal (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Masukkan koordinat titik akhir (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
