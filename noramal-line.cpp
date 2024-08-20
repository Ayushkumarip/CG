#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
double x1,y1,x2,y2;
int selection = 1;

class Line {
public:
    void LineDDA() {
        cout << "DDA" << endl;
        float dx = x2 - x1;
        float dy = y2 - y1;
        float step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float xin = dx / step;
        float yin = dy / step;
        float x = x1;
        float y = y1;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        for (int k = 1; k <= step; ++k) {
            x = x + xin;
            y = y + yin;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        glFlush();
    }

    static void display() {
        Line l;
        l.LineDDA();
    }
};

void Init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
}

void lineGeneration(int i) {
    if (i == 4) exit(0);
    selection = i;
}

void createMenu() {
    int s_id = glutCreateMenu(lineGeneration);
    glutAddMenuEntry("DDA Algorithm", 1);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    cout << "Enter the First coordinates \n";
    cin >> x1 >> y1;
    cout << "Enter the Second coordinates \n";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Line Generation");
    Init();
    glutDisplayFunc(Line::display);
    createMenu();
    glutMainLoop();
    return 0;
}

