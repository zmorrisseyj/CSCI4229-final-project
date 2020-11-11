#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "fd.h"
//Standard libs ^^

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//OS portability ^^

int ww, hh = 500; //width and height of window
int fov=55; //  perspective attributes - fov
double asp=1; // aspect ratio
double dim=60; //size of world
double theta = 0; //idle variable
int th, ph = 0; //viewing angles

//Globals ^^

void display()
{
  double Ex = -2*dim*Sin(th)*Cos(ph);
  double Ey = +2*dim        *Sin(ph);
  double Ez = +2*dim*Cos(th)*Cos(ph);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
  stage(1,1,1,1,1,1,theta);
  glutSwapBuffers();
}

void idle()//Simple idle func from OpenGL: A Primer by Edward Angel
{
  theta+=0.4;
  if(theta > 360.0) theta -= 360.0;
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  ww = w;
  hh = h; //for global use
  asp = (h>0) ? (double)w/h : 1;
  glViewport(0,0, w,h); //view whole window
  glMatrixMode(GL_PROJECTION); //switch to projection matrix for proper view
  glLoadIdentity(); //change projection to identity matrix
  gluPerspective(fov,asp,dim/16,16*dim); //perspective transformation
  glMatrixMode(GL_MODELVIEW); //change to modelview matrix for drawing shapes
  glLoadIdentity();
  glutPostRedisplay();
}

void special(int key,int x,int y)
{
   if (key == GLUT_KEY_RIGHT)      th += 5;//  Right arrow key - increase angle by 5 degrees
   else if (key == GLUT_KEY_LEFT)  th -= 5;//  Left arrow key - decrease angle by 5 degrees
   else if (key == GLUT_KEY_UP)    ph += 5;//  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)  ph -= 5;//  Down arrow key - decrease elevation by 5 degrees
   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;
   glutPostRedisplay();
}

void key(unsigned char ch,int x,int y)
{
   if (ch == 27) exit(0);  //escape ends program
   else if (ch == '0')  th = ph = 0;
   glutPostRedisplay();
}

int main(int argc, char* argv[]){
  glutInit(&argc, argv); //initialize glut
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //enable double buffering and rgb color
  glutInitWindowSize(ww,hh); //initial size of window
  glutInitWindowPosition(0,0); //window position
  glutCreateWindow("Final Destination - Zach Morrissey - CSCI 4229 Final Project"); //creates window with given title
  glutDisplayFunc(display); //giving GLUT all our callback functions
  glutIdleFunc(idle);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutKeyboardFunc(key);
  glutMainLoop();

}
