#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float sx=1.0, sy=1.0;
void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(1.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-10.0,10.0,-10.0,10.0);
     glMatrixMode(GL_MODELVIEW);
}

void myDisplay()
{
     glClear(GL_COLOR_BUFFER_BIT);

     glFlush();
}

void circle()
{
    GLfloat theta;
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the color buffer */

    glPointSize(1.0);
	glBegin(GL_POLYGON);
	for(theta=0; theta<=360; theta+=0.01) {
      glVertex2f(5*sin(theta*3.142/180), 5*cos(theta*3.142/180));
    }
    glEnd();
    glFlush();
}

void square()
{
    GLfloat theta;
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the color buffer */

    glPointSize(1.0);
	glBegin(GL_QUADS);
	glVertex2f(5.0,5.0);
	glVertex2f(-5.0,5.0);
	glVertex2f(-5.0,-5.0);
	glVertex2f(5.0,-5.0);
	glEnd();
    glFlush();
}

void myKey(unsigned char key, int x, int y)
{

    if(key=='s')
    {
        //sx=sx+0.1;
        //sy=sy+0.1;
        glTranslatef(0.1,0.1,0.0);
        square();
    }
    if(key=='a')
    {
        //sx=sx-0.1;
        //sy=sy-0.1;
        glTranslatef(-0.1,-0.1,0.0);
        square();
    }
}
void myMenu(int id)
{
     switch(id)
     {
               case 1: printf("Circle is selected\n");
                       circle();
                       break;
               case 2: printf("Square is selected\n");
                       square();
                       break;
               case 3: exit(0);
                       break;
     }
}

void subMenu(int id)
{

    switch(id)
    {
        case 1: glColor3f(1.0, 0.0, 0.0);
                break;
        case 2: glColor3f(0.0, 0.0, 1.0);
                break;
        case 3: glColor3f(0.0, 1.0, 0.0);
                break;
        case 4: glColor3f(1.0, 1.0, 0.0);
                break;
    }
}

int main(int argc, char **argv)
{
    int menu_id, sub_menu;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple Menu - KARAN");
    glutDisplayFunc(myDisplay);

    sub_menu = glutCreateMenu(subMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Blue", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Yellow", 4);

    menu_id = glutCreateMenu(myMenu);
    glutAddMenuEntry("Circle", 1);
    glutAddMenuEntry("Square", 2);
    glutAddSubMenu("Colors", sub_menu);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutKeyboardFunc(myKey);
    myInit();

    glutMainLoop();
    return 0;
}
