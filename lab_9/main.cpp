#include <GL/glut.h>
#include <iostream>
using namespace std;

int projectionType = 0;

void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);

    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);

    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5, -0.5);

    // Bottom face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f(-0.5, -0.5,  0.5);

    // Right face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);

    // Left face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    glEnd();
}

void setOrthographicProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
}

void setPerspectiveProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    if (projectionType == 1) {
        glTranslatef(0.0, 0.0, -5.0);
    }

    glRotatef(30.0, 1.0, 1.0, 0.0);

    drawCube();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'p') {
        projectionType = 1;
        setPerspectiveProjection();
    } else if (key == 'o') {
        projectionType = 0;
        setOrthographicProjection();
    }
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    setOrthographicProjection();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube Projection");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
