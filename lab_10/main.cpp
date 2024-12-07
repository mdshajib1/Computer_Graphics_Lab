#include <GL/glut.h>
#include <iostream>

using namespace std;

int recursionLevel = 3;

GLfloat vertices[4][3] = {
    {0.0, 0.0, 1.0}, {0.0, 0.9428, -0.3333},
    {-0.8165, -0.4714, -0.3333}, {0.8165, -0.4714, -0.3333}
};

void drawTriangle(GLfloat* v1, GLfloat* v2, GLfloat* v3) {
    glBegin(GL_TRIANGLES);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glEnd();
}

void divideTriangle(GLfloat* v1, GLfloat* v2, GLfloat* v3, int level) {
    if (level == 0) {
        drawTriangle(v1, v2, v3);
    } else {
        GLfloat mid[3][3];
        for (int i = 0; i < 3; i++) {
            mid[0][i] = (v1[i] + v2[i]) / 2.0;
            mid[1][i] = (v2[i] + v3[i]) / 2.0;
            mid[2][i] = (v3[i] + v1[i]) / 2.0;
        }
        divideTriangle(v1, mid[0], mid[2], level - 1);
        divideTriangle(mid[0], v2, mid[1], level - 1);
        divideTriangle(mid[2], mid[1], v3, level - 1);
    }
}

void divideTetrahedron(GLfloat* v0, GLfloat* v1, GLfloat* v2, GLfloat* v3, int level) {
    glColor3f(1.0, 0.0, 0.0);
    divideTriangle(v0, v1, v2, level);
    glColor3f(0.0, 1.0, 0.0);
    divideTriangle(v0, v2, v3, level);
    glColor3f(0.0, 0.0, 1.0);
    divideTriangle(v0, v3, v1, level);
    glColor3f(1.0, 1.0, 0.0);
    divideTriangle(v1, v2, v3, level);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -2.5);
    divideTetrahedron(vertices[0], vertices[1], vertices[2], vertices[3], recursionLevel);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '+') recursionLevel++;
    if (key == '-' && recursionLevel > 0) recursionLevel--;
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
