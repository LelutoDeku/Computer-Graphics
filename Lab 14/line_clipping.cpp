#include<GL/glut.h>
#include<iostream>
using namespace std;

#define size 4

int winx1=100,winy1=100,winx2=400,winy2=400;
int total_vertex=4;
int v[][2]={
    {50,50},
    {350,350},
    {500,100},
    {100,500}
};

void init()
{
    glClearColor(0,0,0,1);
    glColor3ub(255,255,255);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

int and_operator(int a[],int b[])
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==1 && b[i]==1)
        {
            return 0;
        }
    }
    return 1;
}

int yOnX(int x1,int y1,int x2,float m)
{
   // cout<<"slope ->"<<x1<<" "<<y1<<" "<<x2<<" "<<" "<<m<<" " <<float(y1)+m*float(x2-x1)<<endl;
    return float(y1)+m*float(x2-x1);
}

int xOnY(int x1,int y1,int y2,float m)
{
   // cout<<"slope ->"<<x1<<" "<<y1<<" "<<y2<<" "<<" "<<m<<" "<<float(x1)+(float(y2-y1)/m)<<endl;
    return float(x1)+(float(y2-y1)/m);
}

void check(int v[2],int pos[4])
{
    for(int i=0;i<size;i++)
    {
        pos[i]=0;
    }
    if(v[0]<winx1)
    {
        pos[0]=1;
    }
    else if(v[0]>winx2)
    {
        pos[1]=1;
    }
    if(v[1]<winy1)
    {
        pos[2]=1;
    }
    else if(v[0]>winy2)
    {
        pos[3]=1;
    }

}

void drawline(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void disp()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<total_vertex;i+=2)
    {
        drawline(v[i][0],v[i][1],v[i+1][0],v[i+1][1]);
    }
    glFlush();
    
}
void onClick(int button,int state,int x,int y)
{
    if ( button==GLUT_LEFT_BUTTON )
    {
        glClear(GL_COLOR_BUFFER_BIT);
        int pos[4][4];
        for(int i=0;i<total_vertex;i++)
        {
            check(v[i],pos[i]);
        }
        //drawline(0,250,250,0);
        for(int i=0;i<total_vertex;i=i+2)
        {
            //cout<<i<<" Here..."<<endl;
            int x1,y1,x2,y2;
            //cout<<v[i][0]<<" "<<v[i][1]<<" - ";
            // for(int j=0;j<4;j++)
            // {
            //     cout<<pos[i][j]<<" "<<pos[i+1][j]<<endl;
            // }
            float m=float(v[i+1][1]-v[i][1])/float(v[i+1][0]-v[i][0]);
            float delx=v[i+1][0]-v[i][0],dely=v[i+1][1]-v[i][1];
            //cout<<and_operator(pos[i],pos[i+1])<<endl;
            if(and_operator(pos[i],pos[i+1]))
            {
                //cout<<"Inside...";
                if(v[i][0]>winx1 && v[i][0]<winx2 && v[i][1]>winy1 && v[i][1]<winy2)
                {
                    x1=v[i][0];
                    y1=v[i][1];
                }
                else 
                {
                    
                    int temp=xOnY(v[i][0],v[i][1],winy1,m);
                    if(delx>0 && temp>x2) temp=winx2+1; 
                    if(delx<0 && temp<x2) temp=winx2+1; 
                    if(temp>=winx1 && temp<=winx2)
                    {
                        x1=temp;
                        y1=winy1;
                    }
                    else{
                        temp=xOnY(v[i][0],v[i][1],winy2,m);
                        if(delx>0 && temp>x2) temp=winx2+1; 
                        if(delx<0 && temp<x2) temp=winx2+1; 
                        if(temp>=winx1 && temp<=winx2)
                        {
                            x1=temp;
                            y1=winy2;
                        }
                        else 
                        {
                            temp=yOnX(v[i][0],v[i][1],winx1,m);
                            if(dely>0 && temp>y2) temp=winy2+1; 
                            if(dely<0 && temp<y2) temp=winy2+1; 
                            if(temp>=winy1 && temp<=winy2)
                            {
                                x1=winx1;
                                y1=temp;
                            }
                            else 
                            {
                                temp=yOnX(v[i][0],v[i][1],winx2,m);
                                if(dely>0 && temp>y2) temp=winy2+1; 
                                if(dely<0 && temp<y2) temp=winy2+1; 
                                if(temp>=winy1 && temp<=winy2)
                                {
                                    x1=winx2;
                                    y1=temp;
                                }
                                else 
                                {
                                    x1=0;
                                    y1=0;
                                }
                            }
                        }
                    }
                }

                if(v[i+1][0]>winx1 && v[i+1][0]<winx2 && v[i+1][1]>winy1 && v[i+1][1]<winy2)
                {
                    x2=v[i+1][0];
                    y2=v[i+1][1];
                }
                else 
                {
                    
                    int temp=xOnY(v[i+1][0],v[i+1][1],winy1,m);
                    if(temp>=winx1 && temp<=winx2 && temp!=x1)
                    {
                        x2=temp;
                        y2=winy1;
                    }
                    else{
                        temp=xOnY(v[i+1][0],v[i+1][1],winy2,m);
                        if(temp>=winx1 && temp<=winx2 && temp!=x1)
                        {
                            x2=temp;
                            y2=winy2;

                        }
                        else 
                        {
                            temp=yOnX(v[i+1][0],v[i+1][1],winx1,m);
                            if(temp>=winy1 && temp<=winy2 && temp!=y1)
                            {
                                x2=winx1;
                                y2=temp;
                            }
                            else 
                            {
                                temp=yOnX(v[i+1][0],v[i+1][1],winx2,m);
                                if(temp>=winy1 && temp<=winy2 && temp!=y1)
                                {
                                    x2=winx2;
                                    y2=temp;
                                }
                                else 
                                {
                                    x2=0;
                                    y2=0;
                                }
                            }
                        }
                    }
                }
                //cout<<"Drawline "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                drawline(x1,y1,x2,y2);
            }
        }
        glFlush();
    }
    else if( button==GLUT_RIGHT_BUTTON )
    {
        disp();
    }
}
int main(int a,char **b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Line Clipping");
    glutDisplayFunc(disp);
    glutMouseFunc(onClick);
    init();
    glutMainLoop();
    return 0;
}
