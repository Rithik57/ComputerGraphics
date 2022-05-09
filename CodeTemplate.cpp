#include <iostream>
#include <glut.h>
using namespace std;

void init() {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Main Window");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
