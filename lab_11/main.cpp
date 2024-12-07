#include <GL/glut.h>
#include <cmath>

const int numPoints = 4;
float controlPoints[numPoints][2] =
{
    { -0.8, 0.3 }, { -0.4, 0.3 }, { 0.0, 0.3 }, { 0.4, 0.3 }
};

float waveAmplitude = 0.1;
float waveFrequency = 3.0;
float waveSpeed = 0.1;
float timeStep = 0.0;

void computeBezierPoint(float t, float& x, float& y)
{
    float u = 1 - t;
    float b0 = u * u * u;
    float b1 = 3 * t * u * u;
    float b2 = 3 * t * t * u;
    float b3 = t * t * t;

    x = b0 * controlPoints[0][0] + b1 * controlPoints[1][0] +
        b2 * controlPoints[2][0] + b3 * controlPoints[3][0];
    y = b0 * controlPoints[0][1] + b1 * controlPoints[1][1] +
        b2 * controlPoints[2][1] + b3 * controlPoints[3][1];
}

void drawBezierCurve()
{
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.01)
    {
        float x, y;
        computeBezierPoint(t, x, y);
        glVertex2f(x, y);
    }
    glEnd();
}
void animateFlag()
{
    for (int i = 1; i < numPoints - 1; ++i)
    {
        controlPoints[i][1] = 0.3 + waveAmplitude
        * sin(waveFrequency * controlPoints[i][0]
              + waveSpeed * timeStep);
    }
    timeStep += 0.05;
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBezierCurve();
    glutSwapBuffers();
}

void timer(int value)
{
    animateFlag();
    glutTimerFunc(16, timer, 0);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animated Flag using Bezier Curves");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
