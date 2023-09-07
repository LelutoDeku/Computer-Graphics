#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14;
using namespace std;

float a,x=0,y=100,x2=100,y2=100;
float radians=(a*180)/PI;

void rotation_2d(int,int,int,int);
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
	glColor3f(1.0f,1.0f,1.0f);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,1000);
	
}

void display()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,1.0f,0.0f);
	/*cout<<"Enter coordinates of square: ";
	cout<<"x1: ";
	cin>>x;
	cout<<"y1: ";
	cin>>y;
	cout<<"x2: ";
	cin>>x2;
	cout<<"y2: ";
	cin>>y2;*/
	glBegin(GL_POLYGON);
		glVertex2f(x+100,x+100); //(0,0)
		glVertex2f(y+100,x+100);//(100,0)
		glVertex2f(x2+100,y2+100);//(100,100)
		glVertex2f(x+100,y+100);//(0,100)
	glEnd();
	glFlush();
	
	
	cout<<"Enter rotation angle: ";
	cin>>a;
	glColor3f(1.0f,0.0f,0.0f);
	int centre=-(x+y+200)/2;
	glBegin(GL_POLYGON); //first translating to origin it wont be visible on screen becoz its in 4th quadrant
		glVertex2f(x+centre,x+centre);
		glVertex2f(y+centre,x+centre);
		glVertex2f(x2+centre,y2+centre);
		glVertex2f(x+centre,y+centre);
	glEnd();
	glFlush();
	
	//now rotating
	glColor3f(0.0f,0.0f,1.0f);
	int p=x+centre,q=y+centre,s=x2+centre,t=y2+centre;
	 glBegin(GL_POLYGON);
		glVertex2f(p*cos(a)-p*sin(a)+300,p*sin(a)+p*cos(a)+300);
		glVertex2f(q*cos(a)-p*sin(a)+300,q*sin(a)+p*cos(a)+300);
		glVertex2f(s*cos(a)-t*sin(a)+300,s*sin(a)+t*cos(a)+300);
		glVertex2f(p*cos(a)-q*sin(a)+300,p*sin(a)+q*cos(a)+300);
	glEnd();
	glFlush();
	
}
