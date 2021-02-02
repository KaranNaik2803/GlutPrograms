#include<stdio.h>
#include<GL/glut.h>

int width=400, height=400;      /* global varibles to hold width and height */

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

void drawPoint(int x, int y)     /* user defined function to draw a point */
{

     /* Draw the points using the values of x and y */
     glPointSize(4.0);                   /* set the size of pixels to 4 */
     glBegin(GL_POINTS);
       glVertex2i(x, (height - y));        /* convert value of y from viewport co-ordinates
                                            to world (screen) co-ordinates */
     glEnd();                            /* end the procedure */
     glFlush();                          /* flush contente of frame buffer to o/p device */

}

void display()       /* called when window is opened */
{

     glClear(GL_COLOR_BUFFER_BIT);         /* clear the contents of color buffer */
     glFlush();                            /* flush contente of frame buffer to o/p device */
}

void myMouse(int btn, int state, int x, int y)      /* called when mouse is clicked */
{

     if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) /* will be true when left button is clicked
                                                          and button is held down  */
     {
            drawPoint(x, y);   /* call user-defined function to draw a point on window */
     }
     if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
     {
            exit(0);
     }
}

int main(int argc, char** argv)
{

    /* Standard GLUT initialization */
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);     /* default, not needed */
    glutInitWindowSize(width,height);                 /* width x height pixel window */
    glutInitWindowPosition(0,0);                      /* place window top left on display */
    glutCreateWindow("Draw Points - KARAN");                  /* window title */
    myinit();                                         /* set attributes */
    glutDisplayFunc(display);                         /* display callback invoked when window opened */
    glutMouseFunc(myMouse);                           /* mouse callback invoked when mouse clicked */

    glutMainLoop();                                   /* enter event loop */
return 0;

}
