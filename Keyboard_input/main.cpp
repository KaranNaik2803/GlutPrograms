#include<stdio.h>
#include<GL/glut.h>

int width = 500, height = 500;

void myinit()                   /* function to initialize the attributes
                                   and states of OpenGL */
{

       /* attributes */
      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glColor3f(1.0, 0.0, 0.0);         /* draw in red */

      /* set up viewing */
      /* width x height window with origin lower left */
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);   /* setup viewing rectangle
                                                                    equal to window width and height */
      glMatrixMode(GL_MODELVIEW);
}

void display()       /* called when window is opened */
{

     glClear(GL_COLOR_BUFFER_BIT);         /* clear the contents of color buffer */
     glFlush();                            /* flush contente of frame buffer to o/p device */
}

void myKey(unsigned char key, int x, int y)      /* called when key is depressed */
{
     printf("You pressed %c key\n", key);
     if(key == 'Q' || key == 'q')
            exit(0);
}

int main(int argc, char** argv)
{

    /* Standard GLUT initialization */
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);     /* default, not needed */
    glutInitWindowSize(width,height);                 /* width x height pixel window */
    glutInitWindowPosition(0,0);                      /* place window top left on display */
    glutCreateWindow("Draw Points");                  /* window title */
    myinit();                                         /* set attributes */
    glutDisplayFunc(display);                         /* display callback invoked when window opened */
    glutKeyboardFunc(myKey);                           /* key callback invoked when a key is depressed */

    glutMainLoop();                                   /* enter event loop */
return 0;

}
