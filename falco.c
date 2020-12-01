#include "fd.h"

void cone(double s, double x, double y, double z){
  glPushMatrix();
  glScaled(s,s,s);
  glTranslated(x,y,z);



  glPopMatrix();
}

void head(double s, double x, double y, double z){
  glPushMatrix();
  glScaled(s,s,s);
  glTranslated(x,y,z);

  //cylinder part of beak
  glBegin(GL_QUAD_STRIP);
  glNormal3d(0,0,1);          glVertex3d(0.7,0.3,0.2);     glVertex3d(1.4,0.3,0.2);
  glNormal3d(0,0.866,0.5);    glVertex3d(0.7,0.4,0.173);   glVertex3d(1.4,0.4,0.173);
  glNormal3d(0,0.5,0.866);    glVertex3d(0.7,0.473,0.1);   glVertex3d(1.4,0.473,0.1);
  glNormal3d(0,1,0);          glVertex3d(0.7,0.5,0);       glVertex3d(1.4,0.5,0);
  glNormal3d(0,0.5,-0.866);   glVertex3d(0.7,0.473,-0.1);  glVertex3d(1.4,0.473,-0.1);
  glNormal3d(0,0.866,-0.5);   glVertex3d(0.7,0.4,-0.173);  glVertex3d(1.4,0.4,-0.173);
  glNormal3d(0,0,-1);         glVertex3d(0.7,0.3,-0.2);    glVertex3d(1.4,0.3,-0.2);
  glEnd();

  //front rounded part of beak


  glScaled(1.05,1.2,0.8);
  sphere(0.45,0.3,0,0.5); //main head shape
  //cones here



  glPopMatrix();
}

void Falco(double s, double x, double y, double z){
  glPushMatrix();
  glScaled(s,s,s);
  glColor3f(1,1,1);
  head(1,0,0,0);
  glPopMatrix();
}
