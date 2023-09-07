#include<GL/glut.h>
#include<iostream>
void boundary_fill(int,int);
int b_color[3]={0,255,0},f_color[]={255,0,0};
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,4,0,4);
}
void draw_line(int x1,int y1,int x2,int y2)
{
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
}

void onClick(int x,int y,int button,int state)
{
    boundary_fill(x,y);
}

void boundary_fill(int x,int y)
{
    int count=0;
    GLubyte color[3];
    glReadPixels(x,4-y,1,1,GL_RGB ,GL_UNSIGNED_BYTE,color);
    for(int i=0;i<3;i++)
    {
        if(int(color[i])==b_color[i])
        {
            std::cout<<"Check border... ";
            count++;
        }
    }
     std::cout<<x<<" "<<y<<" "<<int(color[0])<<" "<<int(color[1])<<" "<<int(color[3])<<std::endl;
    // int read;
    // std::cin>>read;
    if(count!=3)
    {
        count=0;
        for(int i=0;i<3;i++)
        {
            if(int(color[i])==f_color[i])
            {
                std::cout<<"Check fill... ";
                count++;
            }
        }
        if(count!=3)
        {
            
            std::cout<<"YESSS...";
            //std::cout<<"YESSSS..."<<std::endl;
            glBegin(GL_POINTS);
            glColor3ub(255,0,0);
            glVertex2f(float(x),4-float(y));
            glEnd();
            glFlush();
            glReadPixels(x,4-y,1,1,GL_RGB ,GL_UNSIGNED_BYTE, color);
            std::cout<<x<<" "<<y<<" "<<int(color[0])<<" "<<int(color[1])<<" "<<int(color[3])<<std::endl;
            int read;
            std::cin>>read;
            boundary_fill(x+1,y);
            boundary_fill(x-1,y);
            boundary_fill(x,y+1);
            boundary_fill(x,y-1);
         }
    }
}
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    
    glColor3ub(0,255,0);
    draw_line(0,0,2,2);
    draw_line(2,2,4,0);
    draw_line(4,0,0,0);
    glEnd();
    //glFlush();
   // glColor3d(1,0,0);
//    glBegin(GL_LINES);
//    glColor3ub(0,0,255);
//     draw_line(2,1,1,1);
//     glEnd();

    glFlush();

    // glColor3ub(0,0,255);
    // glBegin(GL_LINES);
    // glVertex2d(2,1);
    // glVertex2d(0,0);


    glutMouseFunc(onClick);
    //glEnd();
    glFlush();
}

int main(int argv,char** argc )
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Boundary fill...");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
    return 0;
}
