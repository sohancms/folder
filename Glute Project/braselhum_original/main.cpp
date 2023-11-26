#include<GL/gl.h>
#include<GL/glut.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float x1,y1,x2,y2;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(3.0);
    //glBegin(GL_POINT);
    float dy,dx,x,y,m,p,xin,yin;

    dx=x2-x1 ;
    dy=y2-y1 ;

    m=abs(dy)/abs(dx);

    cout<<"m="<<m;

    glBegin(GL_POINTS);
    x=x1,y=y1;


    if(m<1 && dx>0 && dy>0 )
    {
        cout<<"rule1"<<endl;
        p=2*abs(dy)-abs(dx);
        while(x<=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dy);
                x=x+1 ;
            }
            else
            {
                glVertex2i(x,y);

                p=p+2*abs(dy)-abs(dx) ;

                x=x+1;
                y=y+1 ;
            }
        }
    }

    else if(m<1 && dx<0 && dy>0)
    {
        cout<<"rule2"<<endl;
        p=2*abs(dy)-abs(dx);
        while(x>=x2 && y<=y2)
        {

            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dy);
                x=x-1 ;
            }
            else
            {
                glVertex2i(x,y);

                p=p+2*abs(dy)-abs(dx) ;

                x=x-1;
                y=y+1 ;
            }
        }
    }

    else if(m<1 && dx>0 && dy<0)
    {
        cout<<"rule3"<<endl;
        p=2*abs(dy)-abs(dx);

        while(x<=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dy);
                x=x+1 ;
            }
            else
            {
                glVertex2i(x,y);

                p=p+2*abs(dy)-abs(dx) ;

                x=x+1;
                y=y-1 ;
            }

        }
    }

    else if(m<1 && dx<0 && dy<0)
    {
        cout<<"rule4"<<endl;
        p=2*abs(dy)-abs(dx);
        while(x>=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dy);
                x=x-1 ;
            }
            else
            {
                glVertex2i(x,y);

                p=p+2*abs(dy)-abs(dx) ;

                x=x-1;
                y=y-1 ;
            }
        }
    }


    else if(m>=1 && dx>0 && dy>0 )
    {
        cout<<"rule5"<<endl;
        cout<<"dx= \n dy= \n"<<dx<<" "<<dy;
        p=2*abs(dx)-abs(dy);
        cout<<"p="<<p<<endl;
        while(x<=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dx) ;
                y=y+1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) + 2*abs(dx) - abs(dy);

                x=x+1 ;
                y=y+1 ;

            }
            cout<<"x="<<x<<" y="<<y<<endl;
        }
    }
    else if(m>=1 && dx<=0 && dy>0)
    {
        p=2*abs(dx)-abs(dy);
        cout<<"rule6"<<endl;
        while(x>=x2 && y<=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dx) ;
                y=y+1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) + 2*abs(dx) - abs(dy);

                x=x-1 ;
                y=y+1 ;

            }
        }
    }

    else if(m>=1 && dx>0 && dy<0)
    {
        p=2*abs(dx)-abs(dy);
        cout<<"rule7"<<endl;
        while(x<=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dx) ;
                y=y-1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) + 2*abs(dx) - abs(dy);

                x=x+1 ;
                y=y-1 ;
            }
        }
    }

    else if(m>=1 && dx<0 && dy<0)
    {
        p=2*abs(dx)-abs(dy);
        cout<<"rule8"<<endl;
        while(x>=x2 && y>=y2)
        {
            if(p<0)
            {
                glVertex2i(x,y);

                p=p+2*abs(dx) ;
                y=y-1;
            }
            else
            {
                glVertex2i(x,y);
                p=p+2*abs(dx) + 2*abs(dx) - abs(dy);

                x=x-1 ;
                y=y-1 ;

            }
            cout<<"p="<<p;
        }
    }

    else
    {
        cout<<"Error";

    }

    glEnd();
    glFlush();
}


void backGround()
{
    glClearColor(0.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);


}
int main(int argc, char** argv)
{
    cout<<"Enter the value of (x1 and y1): ";
    cin>>x1>>y1;

    cout<<"Enter the value of (x2 and y2): ";
    cin>>x2>>y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition (100,100);
    glutCreateWindow("line draw");
    glutDisplayFunc(display);


    backGround();
    glutMainLoop();

}
