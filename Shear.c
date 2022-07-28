#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
 
void Init(float a,float b,float c)

{

    glClearColor(0.0,0.0,0.0,1.0);

    glColor3f(a,b,c);



}

void plot(int arr[3][4])

{

    //int i,j;

//    for(j=0;j<3;j++)

//    {
        Init(1,0,0);

        glBegin(GL_LINES);

        glVertex2i(10,10);

        glVertex2i(20,20);       

        glEnd();
        
        Init(0,1,0);
        
        glBegin(GL_LINES);

        glVertex2i(100,200);

        glVertex2i(350,600);       

        glEnd();

  //  }

}

void translation(int obj[3][4], int tx, int ty)

{

    int trans[3][3]={{2,0,0},{0,2,0},{0,0,1}}, i, j, k, final[3][4], a = 0;

    printf("Before Scaling:\n");

    plot(obj);

    printf("After Scaling:\n");

    

    for(i=0;i<3;i++)

    for(j=0;j<3;j++)

    final[i][j]=0;

    for (i = 0; i < 3; i++)

    {

        for (j = 0; j < 3; j++)

        {

            for (k = 0; k < 3; k++)

            {

                final[i][j] += trans[i][k] * obj[k][j];

                

            }

        

        }

        printf("\n");

    }

    final[0][3] = final[0][0];

    final[1][3] = final[1][0];

    final[2][3] = final[2][0];

    plot(final);

}


void user()

{

    int obj[3][4]={{100,200,200},{100,100,200},{1,1,1}}, i, j, tx, ty;

    obj[0][3]=obj[0][0];

    obj[1][3]=obj[1][0];

    obj[2][3]=obj[2][0];

    printf("Enter the scaling factors:");

    //scanf("%d %d", &tx, &ty);

    plot(obj);

    translation(obj, tx, ty);

}

void output(void)

{

    glClear(GL_COLOR_BUFFER_BIT);

    user();

    

    glFlush();

}





int main(int argc, char **argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0,0);

    glutInitWindowSize(640,480);

    glutCreateWindow("2d transformation");

    Init(1.0,0,0);

    glViewport(0 , 0 , 640,480);

    gluOrtho2D(0 ,640 , 0 , 480);

    glutDisplayFunc(output);

    glutMainLoop();

}
