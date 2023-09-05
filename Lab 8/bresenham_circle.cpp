#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;

void bresenhamCircle();

int xc,yc,r;
void plotPoints(int x ,int y)	{

	glBegin(GL_POINTS);
	glVertex2i(x+xc,y+yc);
	glEnd();
	
}

void display()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,10.f,1.0f);
	glPointSize(1.0);
	
	bresenhamCircle();
	
	glFlush();
	
}

void myInit()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	
}

int main( int argc, char** argv)	{


	cout<<"Enter x-coordinate of circle: ";
	cin>>xc;
	cout<<"Enter y-cordinate of circle: ";
	cin>>yc;
	cout<<"Enter radius of circle: ";
	cin>>r;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham Circle");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	
return 0;
}

void bresenhamCircle()	{

	int x=0,y=r;
	float p=3-2*r;
	plotPoints(x,y);
	while(x<y)	{
	
		if(p<0)	
		{
			x++;
			p+=4*x+6;
		}
		else	
		{
			x++;
			y--;
			p+=4*(x-y)+10;

		}
		
			
		plotPoints(x,y);
		plotPoints(-x,y);
		plotPoints(y,x);
		plotPoints(-y,-x);
		plotPoints(y,-x);
		plotPoints(-y,x);
		plotPoints(x,-y);
		plotPoints(-x,-y);
	
	}
	

	

}
