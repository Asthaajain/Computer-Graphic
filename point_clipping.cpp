#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
using namespace std;
int a=100,b=120,c=200,d=220;
int x=150,y=175;
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,700,0,700);
}
void point()
{
    glColor3f(0,1,0);
    glPointSize(5.0);  
    glBegin (GL_POINTS);
    glVertex2i (x,y);
    glEnd();
    glFlush();
    
}
/*void coordinates()
{
	printf("Enter Bottom Left cordinates i.e a and b");
	scanf("%d %d ",&a,&b);
	printf("Enter Top Right cordinates i.e c & d");
	scanf("%d %d", &c,&d);
	printf("\nEnter the co-ordinates of the point");
	printf("\nEnter the value of x: ");
	scanf("%d", &x);
	printf("Enter the value of y: ");
	scanf("%d", &y);
}*/

void clipping()
{
	if(x >= a && x <= c && y >= b && y <= d)
	{
	    point();
	}
	else
	{
		printf("Point is outside the viewport");
	}
	glFlush();
}

void drawLine()
{
  glColor3f(1,0,0);
  glBegin (GL_LINE_LOOP);
  glVertex2i (a,b);
  glVertex2i (c,b);
  glVertex2i (c,d);
  glVertex2i (a,d);
  glEnd();
  glFlush();
}
void draw()
{
	drawLine();
	clipping();
}

int main(int argc,char** argv)
{
	//coordinates();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("point_clipping");
	glutDisplayFunc(draw);
	init();
    glutMainLoop();
    return 0;
}

