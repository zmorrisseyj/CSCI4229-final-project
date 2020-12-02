
#include "fd.h"
//Standard libs ^^

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//OS portability ^^

int ww = 800; //width and height of window
int hh = 800;
int fov=75; //  perspective attributes - fov
double asp=1; // aspect ratio
double dim=60; //size of world
double theta = 0; //idle variable
int th = 0; //viewing angles
int ph = 10;
int mode = 0; //movement mode
int omode = 1; //object mode
double pos1[3]={-20.0,5.0,0.0};
double pos2[3]={ 20.0,5.0,0.0};
double posavg[3];
int emission  =   5;  // Emission intensity (%)
int ambient   =   30;  // Ambient intensity (%)
int diffuse   =  30;  // Diffuse intensity (%)
int specular  =  60;  // Specular intensity (%)
int shininess =   2;  // Shininess (power of two)
int xx = 20;
int yy = 30;
int zz = 0;
//Globals ^^

double avgpos(){
  posavg[0]=(pos1[0]+pos2[0])/2;
  posavg[1]=(pos1[1]+pos2[1])/2;
  posavg[2]=(pos1[2]+pos2[2])/2;
  double dist = pow((pos1[0]-pos2[0])*(pos1[0]-pos2[0])+(pos1[1]-pos2[1])*(pos1[1]-pos2[1])+(pos1[2]-pos2[2])*(pos1[2]-pos2[2]),0.5);
  return dist;
}

void display()
{
  double dist = avgpos();
  (dist<=30) ? dist = 30 : dist;
  (dist>=1.5*dim) ? dist = 1.5*dim : dist;
  double Ex = -2*dist*Sin(th)*Cos(ph);
  double Ey = +2*dist        *Sin(ph);
  double Ez = +2*dist*Cos(th)*Cos(ph);
  float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
  float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
  float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
  float Position[3];
  Position[0] = xx;
  Position[1] = yy;
  Position[2] = zz;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  gluLookAt(Ex,Ey,Ez , posavg[0],posavg[1],posavg[2] , 0,Cos(ph),0);
  glEnable(GL_NORMALIZE);
  //  Enable lighting
  glEnable(GL_LIGHTING);
  //  Location of viewer for specular calculations
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,0);
  //  glColor sets ambient and diffuse color materials
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  //  Enable light 0
  glEnable(GL_LIGHT0);
  //  Set ambient, diffuse, specular components and position of light 0
  glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
  glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
  glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);

  switch(omode){
    case 0:
      stage(1,1,1,1,1,1,theta);
      Falco(1,pos1[0],pos1[1],pos1[2],0);
      Falco(1,pos2[0],pos2[1],pos2[2],180);
      skybox(3.5*dim, dim, theta);
      break;
    case 1:
      Falco(3,-10,-20,0,0);
      mode = 0;
      skybox(3.5*dim, dim, theta);
      break;
  }
  glColor3f(1,1,1);
  sphere(xx,yy,zz,2,0);
  glLightfv(GL_LIGHT0,GL_POSITION,Position);
  ErrCheck("display");
  glutSwapBuffers();
}

void idle()//Simple idle func from OpenGL: A Primer by Edward Angel
{
  switch (mode){
    case 0:
      break;
    case 1:
      if     (theta>=0   && theta<=90  && pos1[0]>=-50) pos1[0]-=0.1;
      else if(theta>=90  && theta<=180 && pos1[1]<=20)  pos1[1]+=0.1;
      else if(theta>=180 && theta<=270 && pos1[0]<=50)  pos1[0]+=0.1;
      else if(theta>=270 && theta<=360 && pos1[1]>=0)   pos1[1]-=0.1;
      avgpos();
      break;
    case 2:
      if     (theta>=0   && theta<=90  && pos1[0]>=-50) pos1[0]-=0.1;
      else if(theta>=90  && theta<=180 && pos1[1]<=20)  pos1[1]+=0.1;
      else if(theta>=180 && theta<=270 && pos1[0]<=50)  pos1[0]+=0.1;
      else if(theta>=270 && theta<=360 && pos1[1]>=0)   pos1[1]-=0.1;
      if     (theta>=0   && theta<=90  && pos2[0]>=-50) pos2[0]-=0.3;
      else if(theta>=90  && theta<=180 && pos2[1]<=40)  pos2[1]+=0.3;
      else if(theta>=180 && theta<=270 && pos2[0]<=50)  pos2[0]+=0.3;
      else if(theta>=270 && theta<=360 && pos2[1]>=0)   pos2[1]-=0.1;
      avgpos();
      break;
  }
  double t = glutGet(GLUT_ELAPSED_TIME)/2000.0; //borrowed from ex
  theta = fmod(90*t,360);
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
   if      (ch == 27)            exit(0);  //escape ends program
   else if (ch == '0')       th = ph = 0;
   else if (ch == 'm'||ch == 'M') mode = (mode+1)%3;
   else if (ch == 'o'||ch == 'O') omode = 1-omode;
   else if (ch == 'z')              zz-=1;
   else if (ch == 'Z')              zz+=1;
   else if (ch == 'x')              xx-=1;
   else if (ch == 'X')              xx+=1;
   else if (ch == 'y')              yy-=1;
   else if (ch == 'Y')              yy+=1;

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

  tex[0] = LoadTexBMP("skyneb.bmp");
  tex[1] = LoadTexBMP("static.bmp");
  tex[2] = LoadTexBMP("matte.bmp");
  tex[3] = LoadTexBMP("mattegradient.bmp");
  tex[4] = LoadTexBMP("nebula.bmp");

  glutMainLoop();

}
