#include <GL/glut.h>
#include <cmath>

void polynomialLine(float x1, float y1, float x2, float y2) {
    float m = (y2 - y1) / (x2 - x1);
    float c = y1 - m * x1;
    glBegin(GL_POINTS);
    for (float x = x1; x <= x2; x += 0.01) {
        float y = m * x + c;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    polynomialLine(100, 100, 400, 300);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polynomial Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
