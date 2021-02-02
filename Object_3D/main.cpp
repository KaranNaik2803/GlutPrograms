#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glColor3f(1.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);	// set viewing volume to 2 X 2 X 2
     glMatrixMode(GL_MODELVIEW);

     float material_ambient[]  = {0.25, 0.25, 0.25};
     float material_diffuse[]  = {0.90, 0.90, 0.90};
     float material_specular[] = {0.90, 0.90, 0.90};
     float material_shininess  =  50.0;

     glMaterialfv(GL_FRONT, GL_AMBIENT,   material_ambient);
     glMaterialfv(GL_FRONT, GL_DIFFUSE,   material_diffuse);
     glMaterialfv(GL_FRONT, GL_SPECULAR,  material_specular);
     glMaterialf (GL_FRONT, GL_SHININESS, material_shininess);

     float light0_diffuse [] = {1.0, 0.0, 0.0, 1.0};
     float light1_diffuse [] = {0.0, 0.0, 1.0, 1.0};
     float light2_diffuse [] = {0.0, 1.0, 0.0, 1.0};

     float light0_position[] = {0.0, 0.0, 1.0, 0.0};
     float light1_position[] = {1.0, 0.0, 0.0, 0.0};
     float light2_position[] = {0.0, 1.0, 0.0, 0.0};

     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHT1);
     glEnable(GL_LIGHT2);

     glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
     glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
     glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
     glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
     glLightfv(GL_LIGHT2, GL_DIFFUSE,  light2_diffuse);
     glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

}

void display()
{
     glRotatef(0.1, 1.0, 1.0, 1.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	// clear color buffer and depth buffer for HSR
     glutSolidTeapot(1.0);
     //glutSolidCone(.8, 1, 5, 6);
     //glutSolidTorus(0.4,0.8,10,4);
     //glutSolidSphere(0.8,6,4);
     //glutSolidCube(1);
     //glutWireTorus(0.4,0.8,10,4);
     //glutWireTeapot(1.0);
     glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB );	// use GLUT_DEPTH if HSR is being used
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("3D Objects");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);  // enable Hidden Surface Removal Algorithm
    myInit();
    glutMainLoop();
return 0;
}

