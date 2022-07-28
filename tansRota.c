#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
int x1, z1, x2, z2;

void myInit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glColor3f(0.0, 1.0 , 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)

{
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void bres_general(int x1, int z1, int x2, int z2)
{
int dx, dy, i, e;
int incx, incy, inc1, inc2;
int x,y;
dx = x2-x1;
dy = z2-z1;
if (dx < 0) dx = -dx;
if (dy < 0) dy = -dy;
incx = 1;
if (x2 < x1) incx = -1;
incy = 1;
if (z2 < z1) incy = -1;
x = x1; y = z1;
if (dx > dy)
{
draw_pixel(x, y);
e = 2 * dy-dx;
inc1 = 2*(dy-dx);
inc2 = 2*dy;
for (i=0; i<dx; i++)
{
if (e >= 0)
{
y += incy;
e += inc1;
}
else
e += inc2;
x += incx;
draw_pixel(x, y);
}
}

else
{
draw_pixel(x, y);
e = 2*dx-dy;
inc1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i<dy; i++)
{
if (e >= 0)
{
x += incx;
e += inc1;
}
else
e += inc2;
y += incy;
draw_pixel(x, y);
}
}
}
void draw(void)
{
    float x=(3.14/180)*30;
    
    float tx=50,ty=30;
    float a[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
    float ob[3][3]={{100,200,300},{100,200,100},{1,1,1}}; //object matrix
    float rt[3][3]={{cos(x),-sin(x),0},{sin(x),cos(x),0},{0,0,1}}; //rotation matrix
    float c[3][3];
    float ans[3][3];
    
    
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         int sum=0;
         for(int k=0;k<3;k++){
	    sum+=a[i][k]*ob[k][j];
         }
         c[i][j]=sum;
      }
     }
     
     for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         int sum=0;
         for(int k=0;k<3;k++){
	    sum+=c[i][k]*rt[k][j];
         }
         ans[i][j]=sum;
      }
     }
    
    glClear(GL_COLOR_BUFFER_BIT);
    
     int x1=ob[0][0];
     int x2=ob[0][1];
     int x3=ob[0][2];
     int y1=ob[1][0];
     int y2=ob[1][1];
     int y3=ob[1][2];
      
      bres_general(x1,y1,x2,y2);
      bres_general(x2,y2,x3,y3);
      bres_general(x1,y1,x3,y3);
      
     x1=ans[0][0];
     x2=ans[0][1];
     x3=ans[0][2];
     y1=ans[1][0];
     y2=ans[1][1];
     y3=ans[1][2];
      
      bres_general(x1,y1,x2,y2);
      bres_general(x2,y2,x3,y3);
      bres_general(x1,y1,x3,y3);
 
  

   glFlush();
}

int main(int argc, char **argv){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(600, 600);
glutInitWindowPosition(100, 100);
glutCreateWindow("Translation and Rotation");
myInit();
glutDisplayFunc(draw);
glutMainLoop();

return 0;
}
