#include<GL/glut.h>
int winx1=100,winy1=100,winx2=300,winy2=300;

int ver[][2]={
    {50,50},
    {110,450},
    {450,300},
    {400,200},
    {300,100}
};
struct vertex
{
    int x;
    int y;
    struct vertex *next;
    struct vertex *prev;
}*head=NULL;
int n=5;

void init()
{
    glClearColor(0,0,0,1);
    glColor3ub(255,255,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
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
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    struct vertex *ptr=head;
    glBegin(GL_POLYGON);
    while(ptr->next!=NULL)
    {
        glVertex2f(ptr->x,ptr->y);
        ptr=ptr->next;
    }
    glEnd();
    glFlush();
}
void onClick(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        struct vertex *ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->x < winx1 )
            {
                float m=float(ptr->next->y - ptr->y)/float(ptr->next->x - ptr->x);
                int temp=yOnX(ptr->x,ptr->y,winx1,m);
                if(temp<=winy2 && temp>=winy1)
                {
                    ptr->x=winx1;
                    ptr->y=temp;
                }
            }
            ptr=ptr->next;
        }
        disp();
    }
    else if(button == GLUT_RIGHT_BUTTON)
    {
        disp();
    }
}
int main(int a,char** b)
{
    struct vertex *v=head;
    for(int i=0;i<n;i++)
    {
        if(head==NULL)
        {
            struct vertex *ptr=new struct vertex;
            ptr->x=ver[i][0];
            ptr->y=ver[i][1];
            ptr->next=NULL;
            ptr->prev=NULL;
            v=ptr;
            head=ptr;
        }
        else{
            struct vertex *ptr=new struct vertex;
            ptr->x=ver[i][0];
            ptr->y=ver[i][1];
            ptr->next=NULL;
            ptr->prev=v;
            v->next=ptr;
            v=ptr;
        }

    }
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Polygon Clipping");
    glutDisplayFunc(disp);
    glutMouseFunc(onClick);
    init();
    glutMainLoop();
    return 0;
}
