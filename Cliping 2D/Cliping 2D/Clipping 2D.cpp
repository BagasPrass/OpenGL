#include <GL/glut.h>

int x1, y1, x2, y2;

void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void clipAndDraw() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set clipping region using glScissor
    glEnable(GL_SCISSOR_TEST);
    glScissor(x1, y1, x2 - x1, y2 - y1);

    // Draw the line
    glColor3f(1.0, 1.0, 1.0);
    drawLine(0, 0, 100, 100);

    glDisable(GL_SCISSOR_TEST);
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
    glutCreateWindow("2D Clipping in OpenGL");

    init();
    glutDisplayFunc(clipAndDraw);
    glutMainLoop();

    return 0;
}
