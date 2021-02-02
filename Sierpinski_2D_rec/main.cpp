/* Sierpinski Gasket that uses recursive sub-division of triangles */

#include<stdio.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(0.0, 0.0, 1.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 10.0, 0.0, 10.0);
     glMatrixMode(GL_MODELVIEW);
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
     glVertex2fv(a);	// Draw the triangle using the vertices a, b, c
     glVertex2fv(b);
     glVertex2fv(c);
}

void draw_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
     GLfloat ab[2], bc[2], ac[2]; // array to hold the co-ordinates of midpoint of each vertices
     int j;

     if(k>0)			// termination condition for recursion
     {
            for(j=0;j<2;j++) ab[j] = ((a[j]+b[j])/2.0);	// compute midpoint between a and b
            for(j=0;j<2;j++) bc[j] = ((b[j]+c[j])/2.0);	// compute midpoint between b and c
            for(j=0;j<2;j++) ac[j] = ((a[j]+c[j])/2.0);	// compute midpoint between a and c

            draw_triangle(a, ab, ac, k-1);		// recursively sub-divide the points to smaller triangles
            draw_triangle(ab, b, bc, k-1);		// recursively sub-divide the points to smaller triangles
            draw_triangle(ac, bc, c, k-1);		// recursively sub-divide the points to smaller triangles
     }
     else
     {
         triangle(a, b, c);				// draw the triangles
     }
}

void display()
{
     GLfloat a[2] = {0.0, 0.0};				// co-ordinates for a, b, c
     GLfloat b[2] = {5.0, 10.0};
     GLfloat c[2] = {10.0, 0.0};

     glClear(GL_COLOR_BUFFER_BIT);			// clear the color buffer

     glBegin(GL_TRIANGLES);
       draw_triangle(a, b, c, 15);			// draw sierpinski with 4 sub-divisions
     glEnd();
     glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sierpenski 2D Recursive Gasket - KARAN");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
return 0;
}
