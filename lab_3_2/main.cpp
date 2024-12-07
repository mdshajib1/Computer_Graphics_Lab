#include <GL/glut.h>
#include <cmath>

void trigonometricEllipse(int h, int k, int a, int b) {
    glBegin(GL_POINTS);
    for (float theta = 0; theta <= 360; theta += 0.1) {
        float x = a * cos(theta * M_PI / 180);
        float y = b * sin(theta * M_PI / 180);
        glVertex2i(h + x, k + y);
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    trigonometricEllipse(250, 250, 150, 100);
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
    glutCreateWindow("Trigonometric Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
