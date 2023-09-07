#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;

int x,y;

void translation_2d();
void display();
void init();

int main(int argc, char** argv)	{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2-D Transformation");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	
	return 0;
	
}

void init()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	
}

void display()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2f(200,0);
		glVertex2f(400,0);
		glVertex2f(400,200);
		glVertex2f(200,200);
	glEnd();
	glFlush();
	
	cout<<"Enter translation along x-axis: ";
	cin>>x;
	cout<<"Enter translation along y-axis: ";
	cin>>y;
	glColor3f(1.0,0.0f,0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(200+x,0+y);
		glVertex2f(400+x,0+y);
		glVertex2f(400+x,200+y);
		glVertex2f(200+x,200+y);
	glEnd();
	glFlush();

	
}


void translation_2d()	{

		
}
