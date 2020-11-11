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

int ww = 500;
int hh = 500; //width and height of window
int fov=55; //  perspective attributes - fov
double asp=1; // aspect ratio
double dim=60; //size of world
double theta = 0; //idle variable
int th, ph = 0; //viewing angles
int mode = 1; //camera mode
unsigned int sky[3];
unsigned int tex[5];
double pos1[3]={-20.0,5.0,0.0};
double pos2[3]={ 20.0,5.0,0.0};
double posavg[3];
int state1[2]={1,1};


//Globals ^^

static void skybox(double D)
{
   glColor3f(1,1,1);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D,sky[0]);
   glBegin(GL_QUADS);
   glTexCoord2f(1,0); glVertex3f(+D,-D,-D);
   glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
   glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
   glTexCoord2f(1,1); glVertex3f(+D,+D,-D);
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

void avgpos(){
  posavg[0]=(pos1[0]+pos2[0])/2;
  posavg[1]=(pos1[1]+pos2[1])/2;
  posavg[2]=(pos1[2]+pos2[2])/2;
}

void display()
{
  double Ex = -2*dim*Sin(th)*Cos(ph);
  double Ey = +2*dim        *Sin(ph);
  double Ez = +2*dim*Cos(th)*Cos(ph);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  gluLookAt(Ex,Ey,Ez , posavg[0],posavg[1],posavg[2] , 0,Cos(ph),0);
  stage(1,1,1,1,1,1,theta);
  sphere(pos1[0],pos1[1],pos1[2],3,0);
  sphere(pos2[0],pos2[1],pos2[2],3,0);
  skybox(3.5*dim);
  glutSwapBuffers();
}

void idle()//Simple idle func from OpenGL: A Primer by Edward Angel
{
  switch (mode){
    case 0:
      break;
    case 1:
      if     (theta>=0 && theta<=90)    pos1[0]-=0.25;
      else if(theta>=90 && theta<=180)  pos1[1]+=0.25;
      else if(theta>=180 && theta<=270) pos1[0]+=0.25;
      else if(theta>=270 && theta<=360) pos1[1]-=0.25;
      avgpos();
      break;
    case 2:
      if     (theta>=0 && theta<=90)    pos1[0]-=0.25;
      else if(theta>=90 && theta<=180)  pos1[1]+=0.25;
      else if(theta>=180 && theta<=270) pos1[0]+=0.25;
      else if(theta>=270 && theta<=360) pos1[1]-=0.25;
      if     (theta>=0 && theta<=90)    pos2[0]-=0.1;
      else if(theta>=90 && theta<=180)  pos2[1]+=0.4;
      else if(theta>=180 && theta<=270) pos2[0]+=0.1;
      else if(theta>=270 && theta<=360) pos2[1]-=0.4;
      avgpos();
      break;
  }
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
   else if (ch == 'm') mode = (mode+1)%3;
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

  sky[0] = LoadTexBMP("static.bmp");

  glutMainLoop();

}
