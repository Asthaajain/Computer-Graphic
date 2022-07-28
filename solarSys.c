#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;
int x,y,centerx,centery,r,g,b; 

void delay(unsigned int ms)
{
	clock_t goal = ms + clock();
	while(goal>clock());
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,320,0,240);
}
void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{ 
	glColor3f(r,g,b);
	glPointSize(3.0);
	glBegin (GL_POINTS);
	glVertex2i (x,y);
	glEnd();
}
void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{
	drawDot (xc + x, yc + y, r,g,b);
	drawDot (xc - x, yc + y,r,g,b);
	drawDot (xc + x, yc - y,r,g,b);
	drawDot (xc - x, yc - y,r,g,b);
}
void Ellipse (int a, int b, int xc, int yc, float r, float g, float bl)
{ 
	int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
	aSq = a*a;
  	bSq = b*b;
  	twoASq = 2*aSq;
  	twoBSq = 2*bSq;
  	d = bSq - b*aSq + aSq/4;
  	dx = 0;
  	dy = twoASq*b;
  	x = 0;
  	y = b;
  	symmetricPixels(x,y,xc,yc,r,g,bl);
  	while (dx < dy)
  	{ 
  		x++;
    		dx += twoBSq;
    		if (d >= 0)
    		{ 
    			y--;
      			dy -= twoASq;
    		}
    		if (d < 0)
    		{
     			d += bSq + dx;
     		}
    		else
    		{
     		d += bSq + dx - dy;
     		}
    		symmetricPixels (x,y,xc,yc,r,g,bl);
  	}
  	d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) - aSq*bSq);
  	while (y > 0)
  	{ 
  		y--;
    		dy -= twoASq;
    		if (d <= 0)
    		{ 
    			x++;
      			dx += twoBSq;
    		}
    		if (d > 0)
    		{
         		d += aSq - dy;
         	}
    		else
    		{
         		d += aSq -dy +dx;
         	}
    	symmetricPixels(x,y,xc,yc,r,g,bl);
  	}
  	glFlush();
}
void plot_point(int xc, int yc, int x, int y)
{
	  glBegin(GL_POINTS);
	  glVertex2i(xc+x, yc+y);
	  glVertex2i(xc+x, yc-y);
	  glVertex2i(xc+y, yc+x);
	  glVertex2i(xc+y, yc-x);
	  glVertex2i(xc-x, yc-y);
	  glVertex2i(xc-y, yc-x);
	  glVertex2i(xc-x, yc+y);
	  glVertex2i(xc-y, yc+x);
	  glEnd();
}
void bresenham_circle(int radius, int xc, int yc, float r, float g, float b)
{
	  int x=0,y=radius;
	  float pk=3-2*radius;
	  /* Plot the points */
	  /* Plot the first point */
	  glColor3f(r,g,b);
	  plot_point(xc,yc,x,y);
	  int k;
	  /* Find all vertices till x=y */
	  while(x < y)
	  {
		    x = x + 1;
		    if(pk < 0)
		    {
		      pk = pk + 2*x+1;
		    }
		    else
		    {
		      y = y - 1;
		      pk = pk + 2*(x - y) + 1;
		    }
		    plot_point(xc,yc,x,y);
	  }
	  glFlush();
}
void Display()
{
	Ellipse(8 , 8, 150 ,110, 1, 0, 0);
	Ellipse(37, 30, 150 ,110, 1, 1, 1);
	Ellipse(57, 50, 150 ,110, 1, 1, 1);
	Ellipse(77, 70, 150 ,110, 1, 1, 1);
	Ellipse(97, 90, 150 ,110, 1, 1, 1);
	Ellipse(117, 110, 150 ,110, 1, 1, 1);
	Ellipse(137, 130, 150 ,110, 1, 1, 1);
	
	bresenham_circle(10,225,225,1,0.5,0.5);
	bresenham_circle(10,100,100,0,1,0);
	bresenham_circle(10,50,50,0,0,0.5);
	bresenham_circle(10,70,70,1,0,0);
	bresenham_circle(10,110,50,0,1,0.5);
	bresenham_circle(10,170,85,1,0,0.5);
	
	bresenham_circle(20,290,220,1,1,1);
	
}

int main(int argc, char** argv)
{
    	glutInit(&argc,argv);
	  /* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	  /* Set the initial window position and size */
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	  /* Create the window with title "DDA_Line" */
	glutCreateWindow("solar Planet");
    	init();
    	glutDisplayFunc(Display);
    	glutMainLoop();
    	return 0;
}
