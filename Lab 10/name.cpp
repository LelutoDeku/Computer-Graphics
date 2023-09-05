#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display();

int main(int argc, char** argv)	{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Name inside triangle");
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
	
}

void display()	{

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	float val=sqrt(0.75);
	glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(1.0,0.0,0.0);
		glVertex3f(0.5,val,0.0);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(0.35,0.3);
	char name[]="Hammad";
	for( int i=0; name[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
	glutSwapBuffers();
	
}
