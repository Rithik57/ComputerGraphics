#include <iostream>
#include <glut.h>
using namespace std;
float coordinates[6];
void makeTriangle() {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i = i + 2) {
		glVertex2f(coordinates[i], coordinates[i + 1]);
	}
	glEnd();
}

void translate(float t1,float t2) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i = i + 2) {
		glVertex2f(coordinates[i]+t1, coordinates[i + 1]+t2);
	}
	glEnd();
}

void scaling(float sx, float sy) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i = i + 2) {
		glVertex2f(coordinates[i]*sx, coordinates[i + 1]*sy);
	}
	glEnd();
}

void rotation(float angle) {
	angle = angle * 3.14159 / 180;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i = i + 2) {
		glVertex2f(coordinates[i]*cos(angle) - coordinates[i+1]*sin(angle), 
			coordinates[i]*sin(angle)+coordinates[i+1]*cos(angle));
	}
	glEnd();
}

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 200);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,100.0,0.0,100.0);
	glutCreateWindow("My Window");
}
void display() {
	glClearColor(0, 0, 0, 0); //black window
	cout << "Background_Set" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);
	coordinates[0] = 0.10;
	coordinates[1] = 0.10;
	coordinates[2] = 0.30;
	coordinates[3] = 0.10;
	coordinates[4] = 0.20;
	coordinates[5] = 0.20;
	makeTriangle();
	rotation(45);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
