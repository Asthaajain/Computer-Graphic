#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
using namespace std;
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,700,0,700);
}

void drawLine()
{
  glColor3f(1,0,0);
  //glPointSize(5.0);
  glBegin (GL_LINE_LOOP);
  glVertex2i (50,50);
  glVertex2i (80,80);
  glVertex2i (50,80);
  glEnd();
  glFlush();
}
void transformation()
{
	int m=1,k=1;
	float a[3][3]={{1-m*m/1+m*m,2*m/1+m*m,-2*m*k/1+m*m},{2*m/1+m*m,-(1-m*m)/(1+m*m),2*k/1+m*m},{0,0,1}};
    int  b[3][3]={{50,80,50},{50,80,80},{1,1,1}};
    float c[3][3];
    
    for ( int i = 0 ; i < 3 ; i++ )
    {
      for (int j = 0 ; j < 3 ; j++ )
      {
      	int sum=0;
        for (int k = 0 ; k < 3 ; k++ )
        {
          sum = sum + a[i][k]*b[k][j];
        }
        c[i][j] = sum;
      }
    }
    drawLine();
     int x1=c[0][0];
     int x2=c[0][1];
     int x3=c[0][2];
     int y1=c[1][0];
     int y2=c[1][1];
     int y3=c[1][2];
     printf("C matrix \n");
     for(int i=0;i<3;i++)
     {
     	for(int j=0;j<3;j++)
     	{
     		printf("%f \t",c[i][j]);
		 }
		 printf("\n");
	 }
     glBegin (GL_LINE_LOOP);
     glVertex2f (x1,y1);
     glVertex2f (x2,y2);
  	 glVertex2f (x3,y3);
  	 glEnd();
  	 glFlush();
  	//glVertex2i (180,280);
  	//glVertex2i (100,280);
    
}

int main(int argc, char** argv)
{
   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("reflected_triangle");
    //glutDisplayFunc(drawLine);
    glutDisplayFunc(transformation);
    init();
    glutMainLoop();
    return 0;
}
