#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void Init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    //glPointSize(3.0);
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    
}

void setPixel(double xcoordinate, double ycoordinate)
{
    glBegin(GL_POINTS);
    glVertex2d(xcoordinate,ycoordinate);
    glEnd();
    glFlush();
}

void lineDDA(double x0,double y0,double xEnd,double yEnd)
{
    double dx = abs(xEnd-x0);
    double dy = abs(yEnd-y0);
    int steps,k;
    double xIncrement,yIncrement,x=x0,y=y0;

    if(dx>dy)
        steps = dx;
    else
        steps = dy;

    xIncrement = dx/(float)steps;
    yIncrement = dy/(float)steps;
    setPixel(round(x),round(y));

    for(k=1; k<steps; k++)
    {
        x+= xIncrement;
        y+= yIncrement;
        setPixel(round(x),round(y));
    }
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    

    int a[3][3]={{0,1,0},{1,0,1},{0,0,1}};
    int b[3][3]={{100,100,200},{100,200,200},{1,1,1}};
    int c[3][3];
    
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         int sum=0;
         for(int k=0;k<3;k++){
	    sum+=a[i][k]*b[k][j];
         }
         c[i][j]=sum;
      }
     }

    
    
     int x1=b[0][0];
     int x2=b[0][1];
     int x3=b[0][2];
     int y1=b[1][0];
     int y2=b[1][1];
     int y3=b[1][2];
      
      lineDDA(x1,y1,x2,y2);
      lineDDA(x2,y2,x3,y3); 
      lineDDA(x1,y1,x3,y3);
      
     x1=c[0][0];
     x2=c[0][1];
     x3=c[0][2];
     y1=c[1][0];
     y2=c[1][1];
     y3=c[1][2];
     
      lineDDA(x1,y1,x2,y2);
      lineDDA(x2,y2,x3,y3); 
      lineDDA(x1,y1,x3,y3);
      
      
    
 
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Rotation");
    glutDisplayFunc(Display);
    Init();
    gluOrtho2D(0.0,640.0,0.0,480.0);
    glutMainLoop();
    return 0;
}
