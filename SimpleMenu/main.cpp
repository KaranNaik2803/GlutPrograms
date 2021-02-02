#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(1.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-10.0,10.0,-10.0,10.0);
     glMatrixMode(GL_MODELVIEW);
}

void pentagon()
{
    GLfloat theta;
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the color buffer */

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
	glBegin(GL_POLYGON);
	for(theta=0; theta<=360; theta+=360.0/5) {
      glVertex2f(5*sin(theta*3.142/180), 5*cos(theta*3.142/180));
    }
    glEnd();
    glFlush();
}

void triangle()
{
     GLfloat theta;
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the color buffer */

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-5.0,-5.0);
	glVertex2f(0.0,5.0);
	glVertex2f(5.0,-5.0);
	glEnd();
    glFlush();
}

void myDisplay()
{
     glClear(GL_COLOR_BUFFER_BIT);

     glFlush();
}

void myMenu(int id)
{
     printf("MyMenu called with ID: %d\n",id);
     switch(id)
     {
               case 1: triangle();
                       break;
               case 2: pentagon();
                       break;
               case 3: exit(0);
                       break;
     }
}
void myKey(unsigned char key, int x, int y)
{
    if(key=='c'||key=='C')
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
    if(key=='q'||key=='Q')
        exit(0);
}
int main(int argc, char **argv)
{
    int menu_id;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple Menu - KARAN");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKey);

    menu_id = glutCreateMenu(myMenu);
    glutAddMenuEntry("Triangle", 1);
    glutAddMenuEntry("Pentagon", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    myInit();

    glutMainLoop();

    return 0;
}
