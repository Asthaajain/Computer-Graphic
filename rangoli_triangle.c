// Bresenham's Circle Drawing
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = 320, yc = 240;
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
  glClear(GL_COLOR_BUFFER_BIT);
  bres_general(100,100,400,100);
  bres_general(100,100,100,400);
  bres_general(100,400,400,100);
   glFlush();
}


// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
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

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=3-(2*r);

  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + (4*x)+6;
    else
    {
      y = y - 1;
      pk = pk + (4*(x - y)) + 10;
    }
    plot_point(x,y);
  }
  glFlush();
}

// Function to draw two concentric circles
void concentric_circles(void)
{
  /* Clears buffers to preset values */
  glClear(GL_COLOR_BUFFER_BIT);
	draw();
  xc=100;
  yc=100;
  bresenham_circle(80);
  xc=400;
  yc=100;
  bresenham_circle(80);
  xc=100;
  yc=400;
  bresenham_circle(80);
  xc=188;
  yc=188;
  bresenham_circle(87);
  
  glFlush();
}

void Init()
{
  /* Set clear color to white */
  glClearColor(0.0,0.0,0.0,0.0);
  /* Set fill color to black */
  glColor3f(1.0,0.0,1.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("bresenham_circle");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(concentric_circles);
  /* Keep displaying untill the program is closed */

  glutMainLoop();
  return 0;
}
