#include <GL/glut.h>

// Define the colors of the square
GLfloat red[] = { 1.0f, 0.0f, 0.0f };
GLfloat green[] = { 0.0f, 1.0f, 0.0f };

// Counter for the number of left mouse clicks
int clickCount = 0;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   
   // Determine the current color of the square based on the number of clicks
   GLfloat* currentColor = (clickCount % 2 == 0) ? red : green;

   // Draw the square with the current color
   glColor3fv(currentColor);
   glBegin(GL_QUADS);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(-0.5f, 0.5f);
      glVertex2f(0.5f, 0.5f);
      glVertex2f(0.5f, -0.5f);
   glEnd();

   glFlush();
}

void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      // Increment the click count and toggle the color of the square
      clickCount++;
      
      glutPostRedisplay();
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Color Change on Multiple Mouse Clicks");
   
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

   glutDisplayFunc(display);
   glutMouseFunc(mouse);

   glutMainLoop();
   return 0;
}

