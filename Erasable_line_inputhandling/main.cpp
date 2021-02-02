#include <GL/glut.h>

void drawLine()
{
     glColor3f(1.0, 0.0, 1.0);
     glLineWidth(4.0);
    glLogicOp(GL_XOR);
    glBegin(GL_LINES);
    	glVertex2f(1, 1);
		glVertex2f(8, 8);
	glEnd();
	glFlush();
}

void mydisplay(){

   glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
      glVertex2f(2,2);
      glVertex2f(6,2);
      glVertex2f(6,6);
      glVertex2f(2,6);
    glEnd();
    glFlush();
   }

void init()
{
    glClearColor (1.0, 1.0, 1.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(0.0, 10.0, 0.0, 10.0, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void myMouse(int button, int state, int x, int y)
{
     if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
     {
         drawLine();
     }
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);/*initializes window s/m */
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Erasable Line - KARAN");
	glutDisplayFunc(mydisplay);
	glutMouseFunc(myMouse);
    glEnable(GL_COLOR_LOGIC_OP);

	init(); /*User-defined function that contains initialization code*/

	glutMainLoop();
}
