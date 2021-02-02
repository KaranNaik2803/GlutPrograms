#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(1.0, 0.0, 0.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
     glMatrixMode(GL_MODELVIEW);

}

void display()
{
     float x,y,radius=2,theta;
     glClear(GL_COLOR_BUFFER_BIT);
     glPointSize(1.0);
     glBegin(GL_POINTS);
       for(theta=0;theta<=3600;theta=theta+0.01)
       {
          x = 0.01*cos(theta*3.1412/180)*pow(1.618282,(0.01*theta));
          y = 0.01*sin(theta*3.1412/180)*pow(1.618282,(0.01*theta));
          glVertex2f(x, y);
       }
     glEnd();
     glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Equiangular Spiral - KARAN");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
