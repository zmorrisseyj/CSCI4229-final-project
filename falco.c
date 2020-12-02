#include "fd.h"

void headcone(double s, double x, double y, double z){ //cone function from scratch
  glPushMatrix();
  glTranslated(x,y,z);
  glScaled(0.8*s,1.5*s,0.8*s);
  glColor3f(0.05,0,0.5);
  for (int i = 0; i<10; i++){ //increments height
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j<=360; j+=30){ //draws each circular section of cone
      glNormal3d(Sin(j),1,Cos(j)); glVertex3d(Sin(j)*i,i,Cos(j)*i);
      glNormal3d(Sin(j),1,Cos(j)); glVertex3d(Sin(j)*(i+1),i+1,Cos(j)*(i+1));
    }
    glEnd();
  }

  glPopMatrix();
}

void head(double s, double x, double y, double z){
  glPushMatrix();
  glTranslated(x,y,z);
  glScaled(s,s,s);

  //cylinder part of beak
  glColor3f(0.5,0.5,0);
  glBegin(GL_QUAD_STRIP);
  glNormal3d(0,0,1);          glVertex3d(0.7,0.3,0.2);     glNormal3d(0.1,0.1,1);       glVertex3d(1.2, 0.3,0.2);
  glNormal3d(0,0.866,0.5);    glVertex3d(0.7,0.4,0.173);   glNormal3d(0.1,0.71,0.71);   glVertex3d(1.2, 0.4,0.173);
  glNormal3d(0,0.5,0.866);    glVertex3d(0.7,0.473,0.1);   glNormal3d(0.15,0.866,0.5);  glVertex3d(1.2,0.473,0.1);
  glNormal3d(0,1,0);          glVertex3d(0.7,0.5,0);       glNormal3d(0.15,1,0);        glVertex3d(1.2,0.5,0);
  glNormal3d(0,0.5,-0.866);   glVertex3d(0.7,0.473,-0.1);  glNormal3d(0.15,0.866,-0.5); glVertex3d(1.2,0.473,-0.1);
  glNormal3d(0,0.866,-0.5);   glVertex3d(0.7,0.4,-0.173);  glNormal3d(0.1,0.71,-0.71);  glVertex3d(1.2,0.4,-0.173);
  glNormal3d(0,0,-1);         glVertex3d(0.7,0.3,-0.2);    glNormal3d(0.1,0.1,-1);      glVertex3d(1.2, 0.3,-0.2);
  glEnd();

  //front rounded part of beak
  glBegin(GL_TRIANGLE_FAN);
  glNormal3d(0.5,1,0);         glVertex3d(1.4,0.473,0);
  glNormal3d(0.15,0.866,0.5);  glVertex3d(1.2,0.473,0.1);
  glNormal3d(0.15,1,0);        glVertex3d(1.2,0.5,0);
  glNormal3d(0.15,0.866,-0.5); glVertex3d(1.2,0.473,-0.1);
  glEnd();

  glBegin(GL_TRIANGLE_FAN); //positive z half
  glNormal3d(0.1,0.1,1);       glVertex3d(1.2, 0.3,0.2);
  glNormal3d(0.1,0.71,0.71);   glVertex3d(1.2, 0.4,0.173);
  glNormal3d(0.15,0.64,0.71);  glVertex3d(1.4, 0.375,0.173);
  glNormal3d(0.25,0.5,0.71);   glVertex3d(1.55,0.34,0.15);
  glNormal3d(0.3,0.1,0.3);     glVertex3d(1.6, 0.3,0.14);
  glNormal3d(1,0,1);           glVertex3d(1.6, 0.25,0.13);
  glEnd();

  glBegin(GL_QUAD_STRIP);
  glNormal3d(0.15,0.866,0.5);  glVertex3d(1.2,0.473,0.1);
  glNormal3d(0.1,0.71,0.71);   glVertex3d(1.2,0.4,0.173);
  glNormal3d(0.5,1,0);         glVertex3d(1.4,0.473,0);
  glNormal3d(0.15,0.64,0.71);  glVertex3d(1.4, 0.375,0.173);
  glNormal3d(0.5,0.75,0);      glVertex3d(1.5,0.44,0);
  glNormal3d(0.25,0.5,0.71);   glVertex3d(1.55,0.34,0.15);
  glNormal3d(0.75,0.75,0);     glVertex3d(1.65,0.35,0);
  glNormal3d(0.3,0.1,0.3);     glVertex3d(1.6, 0.3,0.14);
  glNormal3d(1,0,0);           glVertex3d(1.7,0.25,0);
  glNormal3d(1,0,1);           glVertex3d(1.6, 0.25,0.13);
  glEnd();

  glBegin(GL_TRIANGLE_FAN);//negative z half
  glNormal3d(0.1,0.1,-1);      glVertex3d(1.2, 0.3,-0.2);
  glNormal3d(0.1,0.71,-0.71);  glVertex3d(1.2, 0.4,-0.173);
  glNormal3d(0.15,0.64,-0.71); glVertex3d(1.4, 0.375,-0.173);
  glNormal3d(0.25,0.5,-0.71);  glVertex3d(1.55,0.34,-0.15);
  glNormal3d(0.3,0.1,-0.3);    glVertex3d(1.6, 0.3,-0.14);
  glNormal3d(1,0,-1);          glVertex3d(1.6, 0.25,-0.13);
  glEnd();

  glBegin(GL_QUAD_STRIP);
  glNormal3d(0.15,0.866,-0.5); glVertex3d(1.2,0.473,-0.1);
  glNormal3d(0.1,0.71,-0.71);  glVertex3d(1.2,0.4,-0.173);
  glNormal3d(0.5,1,0);         glVertex3d(1.4,0.473,0);
  glNormal3d(0.15,0.64,-0.71); glVertex3d(1.4, 0.375,-0.173);
  glNormal3d(0.5,0.75,0);      glVertex3d(1.5,0.44,0);
  glNormal3d(0.25,0.5,-0.71);  glVertex3d(1.55,0.34,-0.15);
  glNormal3d(0.75,0.75,0);     glVertex3d(1.65,0.35,0);
  glNormal3d(0.3,0.1,-0.3);    glVertex3d(1.6, 0.3,-0.14);
  glNormal3d(1,0,0);           glVertex3d(1.7,0.25,0);
  glNormal3d(1,0,-1);          glVertex3d(1.6, 0.25,-0.13);
  glEnd();

  glBegin(GL_POLYGON);//beak bottom
  glNormal3d(0,-1,0);          glVertex3d(0.7,0.3,0.2);
  glNormal3d(0,-1,0);          glVertex3d(0.7,0.3,-0.2);
  glNormal3d(0,-1,0);          glVertex3d(1.2,0.3,-0.2);
  glNormal3d(-0.1,-1,0);       glVertex3d(1.6, 0.25,-0.13);
  glNormal3d(-0.1,-1,0);       glVertex3d(1.7,0.25,0);
  glNormal3d(-0.1,-1,0);       glVertex3d(1.6, 0.25,0.13);
  glNormal3d(0,-1,0);          glVertex3d(1.2,0.3,0.2);
  glEnd();


  glScaled(1.05,1.2,0.8);
  sphere(0.45,0.3,0,0.5,0); //main head shape

  //cones
  glTranslated(0,1,0);
  glRotated(-145,0,0,1);
  headcone(0.04,0,0,0);
  glTranslated(0.2,0.1,0);
  glRotated(15,0,0,1);
  glScaled(0.5,0.8,0.5);
  headcone(0.03,0,0,0);
  glTranslated(-0.75,0.15,0);
  glRotated(-35,0,0,1);
  headcone(0.03,0,0,0);
  glTranslated(0.80,0.5,0);
  glRotated(50,0,0,1);
  headcone(0.02,0,0,0);

  glPopMatrix();
}

void torso(double s, double x, double y, double z){
  glPushMatrix();
  glTranslated(x,y,z);
  glScaled(s,s,s);

  glColor3f(1,1,1);
  glBegin(GL_QUAD_STRIP);
  for(double i = 0; i <= 8; i+= 0.5){//front of torso
    glNormal3d(1,-0.066,0);  glVertex3d(1,i,2+i/15);
    glNormal3d(1,-0.066,0);  glVertex3d(1,i,-2-i/15);
  }
  glEnd();
  glBegin(GL_QUAD_STRIP);
  for(double i = 0; i <= 8; i+= 0.5){//back of torso
    glNormal3d(-1,-0.066,0);  glVertex3d(-1,i,2+i/15);
    glNormal3d(-1,-0.066,0);  glVertex3d(-1,i,-2-i/15);
  }
  glEnd();
  glBegin(GL_QUAD_STRIP);
  for(int j = 0; j <= 180; j+= 30){//top of torso
    glNormal3d(Cos(j),Sin(j),0);  glVertex3d(Cos(j),Sin(j)+8,2.533);
    glNormal3d(Cos(j),Sin(j),0);  glVertex3d(Cos(j),Sin(j)+8,-2.533);
  }
  glEnd();

  for(double i = 0; i < 8; i+= 0.5){//positive z side
    glBegin(GL_QUAD_STRIP);
    for(int j = 0; j<=180; j+=30){
      glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j),i,2+Sin(j)+i/15);
      glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j),i+0.5,2+Sin(j)+i/15);
    }
    glEnd();
  }
  for(double i = 0; i < 8; i+= 0.5){//negative z side
    glBegin(GL_QUAD_STRIP);
    for(int j = 180; j<=360; j+=30){
      glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j),i,-2+Sin(j)-i/15);
      glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j),i+0.5,-2+Sin(j)-i/15);
    }
    glEnd();
  }
  glBegin(GL_POLYGON);//bottom of torso
  for(int j = 0; j<=180; j+=30){
    glNormal3d(0,-1,0);  glVertex3d(Cos(j),0,2+Sin(j));
  }
  for(int j = 180; j<=360; j+=30){
    glNormal3d(0,-1,0);  glVertex3d(Cos(j),0,-2+Sin(j));
  }
  glEnd();

  //neck
  glBegin(GL_QUAD_STRIP);
  for(int j = 0; j<=360; j+=30){
    glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j)+0.1,8,Sin(j));
    glNormal3d(Cos(j),0,Sin(j));  glVertex3d(Cos(j)+0.6,11,Sin(j));
  }
  glEnd();
  //shoulders
  sphere(0,8,2.533,1,0);
  sphere(0,8,-2.533,1,0);

  glPopMatrix();
}

void Falco(double s, double x, double y, double z, double r){
  glPushMatrix();
  glTranslated(x,y,z);
  glScaled(s,s,s);
  glRotated(r,0,1,0);
  head(3,4.5,15.2,0);
  torso(1,5,5,0);
  glPopMatrix();
}
