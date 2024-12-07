#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

float angleX = 0.0, angleY = 0.0, angleZ = 0.0;

// Function to draw the cube
void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Back face
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Left face
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Right face
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Top face
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply rotation on the cube
    glPushMatrix();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);

    drawCube();

    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    angleX += 1.0;
    angleY += 1.0;
    angleZ += 1.0;

    if (angleX >= 360) angleX -= 360;
    if (angleY >= 360) angleY -= 360;
    if (angleZ >= 360) angleZ -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glEnable(GL_DEPTH_TEST); //
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 200.0);
    glTranslatef(0.0, 0.0, -6.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cube Rotation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
