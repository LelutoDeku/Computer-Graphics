#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;


int rx,ry,xc,yc;

void init()	{

	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
	
}

void display()	{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0,0,0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
		
		int x=0, y=ry;
		int dx=2*ry*ry*x;
		int dy=2*rx*rx*y;
		int p=ry*ry+(0.25)*rx*rx-rx*rx*ry;
		while(dx<dy)	{
		
			dx=2*ry*ry*x;
			dy=2*rx*rx*y;
			glVertex2d(x,y);
			glVertex2d(-x,y);
			glVertex2d(-x,-y);
			glVertex2d(x,-y);
			
			if(p<0)	{
			
				x++;
				p+=2*ry*ry*x+ry*ry;
			}
			
			else	{
			
				x++;
				y--;
				p+=2*ry*ry*x-rx*rx*y*2+ry*ry;
				
			}
			
		}
			
			
		while(y>=0)	{
		
			glVertex2d(x,y);
			glVertex2d(-x,y);
			glVertex2d(x,-y);
			glVertex2d(-x,-y);
			
			if(p>0)	{

				y--;
				p+= rx*rx - rx*rx*y*2;
				
			}
			
			else	{
			
				x++;
				y--;
				p+= -2*rx*rx*y + 2*ry*ry*x + rx*rx;
				
			}
			
		}
		
		glEnd();
		glFlush();
			

}
int main(int argc, char** argv)	{

	cout<<"Enter rx axis: ";
	cin>>rx;
	cout<<"Enter ry axis: ";
	cin>>ry;
	cout<<"Enter centre for x-axis: ";
	cin>>xc;
	cout<<"Enter centre for y-axis: ";
	cin>>yc;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham Ellipse");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	
	return 0;
}

