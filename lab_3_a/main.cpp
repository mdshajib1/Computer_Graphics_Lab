#include <GL/glut.h>
#include <cmath>

void polynomialEllipse(int h, int k, int a, int b) {
    glBegin(GL_POINTS);
    for (int x = -a; x <= a; x++) {
        float y = b * sqrt(1 - (float)(x * x) / (a * a));
        glVertex2i(h + x, k + y);
        glVertex2i(h + x, k - y);
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    polynomialEllipse(250, 250, 150, 100);
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
    glutCreateWindow("Polynomial Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
