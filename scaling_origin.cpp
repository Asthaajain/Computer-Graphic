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
  glVertex2i (200,320);
  glVertex2i (280,380);
  glVertex2i (200,380);
  //glVertex2i (280,380);
  //glVertex2i (100,280);
  glEnd();
  glFlush();
}
void transformation()
{
	float sx=1.5,sy=1.8;
	int xf=220,yf=330;
    float a[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
    float a1[3][3]={{sx,0,xf*(1-sx)},{0,sy,yf*(1-sy)},{0,0,1}};
    float b[3][3]={{180,260,180},{300,360,360},{1,1,1}};
    float c[3][3];
    float c1[3][3];
    
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         float sum=0;
         for(int k=0;k<3;k++){
	    sum+=a[i][k]*b[k][j];
         }
         c[i][j]=sum;
      }
     }
     for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         float sum=0;
         for(int k=0;k<3;k++){
	    sum+=a1[i][k]*b[k][j];
         }
         c1[i][j]=sum;
      }
     }
     
    drawLine();
     
     float x1=c[0][0];
     float x2=c[0][1];
     float x3=c[0][2];
     float y1=c[1][0];
     float y2=c[1][1];
     float y3=c[1][2];
     printf("C matrix \n");
     for(int i=0;i<3;i++)
     {
     	for(int j=0;j<3;j++)
     	{
     		printf("%f \t",c[i][j]);
		 }
		 printf("\n");
	 }
	 float X1=c1[0][0];
     float X2=c1[0][1];
     float X3=c1[0][2];
     float Y1=c1[1][0];
     float Y2=c1[1][1];
     float Y3=c1[1][2];
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
     glVertex2f (X1,Y1);
     glVertex2f (X2,Y2);
  	 glVertex2f (X3,Y3);
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
    glutCreateWindow("sca_triangle");
    glutDisplayFunc(drawLine);
    glutDisplayFunc(transformation);
    init();
    glutMainLoop();
    return 0;
}
