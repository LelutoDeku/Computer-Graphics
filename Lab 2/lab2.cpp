#include <GL/glut.h>
#include <math.h>
void mouse(int button,int state,int,int);
float color[3]={1.0f,0.0f,0.0f};
void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POLYGON);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
 	glTranslatef(0.5f * glutGet(GLUT_WINDOW_WIDTH), 0.5f * glutGet(GLUT_WINDOW_HEIGHT),0.0f);
 	glColor3fv(color);
 	glVertex2f(0.5, 0.5);
 	glVertex2f(-0.5, 0.5);
 	glVertex2f(-0.5, -0.5);
 	glVertex2f(0.5, -0.5);
 glEnd();
 glFlush();
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(400, 300);
 glutMouseFunc(mouse);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Hello world!");
 glutDisplayFunc(displayMe);
 glutMainLoop();
 return 0;
}
void mouse(int button, int state, int x,int y)	{
	if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)	{
		color[0]=0.0f;
		color[1]=1.0f;
		color[2]=0.0f;
		}
	}
