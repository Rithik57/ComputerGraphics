#include <iostream>
#include <glut.h>
using namespace std;

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
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);
	
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
