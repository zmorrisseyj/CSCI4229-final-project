#include "fd.h"

void sphere(double x,double y,double z,
                   double r,int mtex) //FROM ex8
{
   const int d=15;
   int th,ph;
   //  Save transformation
   glPushMatrix();
   //  Offset and scale
   glTranslated(x,y,z);
   glScaled(r,r,r);

   if(mtex){
     glEnable(GL_TEXTURE_2D);
     glBindTexture(GL_TEXTURE_2D,tex[1]);
   }

   //  Latitude bands
   glColor3f(1,1,1);
   for (ph=-90;ph<90;ph+=d)
   {
      glBegin(GL_QUAD_STRIP);
      for (th=0;th<=360;th+=d)
      {
         glNormal3d(Sin(th)*Cos(ph) , Sin(ph) , Cos(th)*Cos(ph));
         glTexCoord2f(Sin(th)*Cos(ph) , Sin(ph)); glVertex3d(Sin(th)*Cos(ph) , Sin(ph) , Cos(th)*Cos(ph));
         glNormal3d(Sin(th)*Cos(ph+d) , Sin(ph+d) , Cos(th)*Cos(ph+d));
         glTexCoord2f(Sin(th)*Cos(ph+d) , Sin(ph+d)); glVertex3d(Sin(th)*Cos(ph+d) , Sin(ph+d) , Cos(th)*Cos(ph+d));
      }
      glEnd();
   }

   //  Undo transformations
   glPopMatrix();
   if (mtex) glDisable(GL_TEXTURE_2D);
}

void stagePoly(double x, double y, double z,
               double dx, double dy, double dz,
               double th, double s){
  glPushMatrix();
  glTranslated(x,y,z);
  glRotated(th*s,0,1,0);
  glScaled(dx,dy,dz);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, tex[2]);

  glColor3f(0.1,0.075,0.1);
  glBegin(GL_QUAD_STRIP);

  glNormal3d(0,0,1); //front surface, same normal throughout
  glTexCoord2f(1,1);           glVertex3d(30,-1,3);
  glTexCoord2f(0.9167,1);      glVertex3d(25,-1,3);

  glTexCoord2f(1,0.5);         glVertex3d(30,-15,3);
  glTexCoord2f(0.9167,0.5);    glVertex3d(25,-15,3);

  glTexCoord2f(0.8333,0.1667); glVertex3d(20,-25,3);
  glTexCoord2f(0.75,0.1667);   glVertex3d(15,-25,3);

  glTexCoord2f(0.5,0);         glVertex3d(0,-30,3);
  glTexCoord2f(0.5,0.1);       glVertex3d(0,-27,3);

  glTexCoord2f(0.25,0.1667);   glVertex3d(-15,-25,3);
  glTexCoord2f(0.1667,0.1667); glVertex3d(-20,-25,3);

  glTexCoord2f(0.0833,0.5);    glVertex3d(-25,-15,3);
  glTexCoord2f(0,0.5);         glVertex3d(-30,-15,3);

  glTexCoord2f(0.0833,1);      glVertex3d(-25,-1,3);
  glTexCoord2f(0,1);           glVertex3d(-30,-1,3);

  glNormal3d(0,0,-1);//back surface, same normal throughout
  glTexCoord2f(1,1);           glVertex3d(-30,-1,-3);
  glTexCoord2f(0.9167,1);      glVertex3d(-25,-1,-3);

  glTexCoord2f(1,0.5);         glVertex3d(-30,-15,-3);
  glTexCoord2f(0.9167,0.5);    glVertex3d(-25,-15,-3);

  glTexCoord2f(0.8333,0.1667); glVertex3d(-20,-25,-3);
  glTexCoord2f(0.75,0.1667);   glVertex3d(-15,-25,-3);

  glTexCoord2f(0.5,0);         glVertex3d(0,-30,-3);
  glTexCoord2f(0.5,0.1);       glVertex3d(0,-27,-3);

  glTexCoord2f(0.25,0.1667);   glVertex3d(15,-25,-3);
  glTexCoord2f(0.1667,0.1667); glVertex3d(20,-25,-3);

  glTexCoord2f(0.0833,0.5);    glVertex3d(25,-15,-3);
  glTexCoord2f(0,0.5);         glVertex3d(30,-15,-3);

  glTexCoord2f(0.0833,1);      glVertex3d(25,-1,-3);
  glTexCoord2f(0,1);           glVertex3d(30,-1,-3);

  glEnd();

  glColor3f(0.2,0.1,0.2);
  glBegin(GL_QUADS);

  glNormal3d(1,0,0); //Outer surface, needs several normals
  glTexCoord2f(1,1); glVertex3d(30,-1,-3);
  glTexCoord2f(0,1); glVertex3d(30,-1,3);
  glTexCoord2f(0,0); glVertex3d(30,-15,3);
  glTexCoord2f(1,0); glVertex3d(30,-15,-3);

  glNormal3d(1,-1,0);
  glTexCoord2f(1,1); glVertex3d(30,-15,-3);
  glTexCoord2f(0,1); glVertex3d(30,-15,3);
  glTexCoord2f(0,0); glVertex3d(20,-25,3);
  glTexCoord2f(1,0); glVertex3d(20,-25,-3);

  glNormal3d(1,-4,0);
  glTexCoord2f(1,1); glVertex3d(20,-25,-3);
  glTexCoord2f(0,1); glVertex3d(20,-25,3);
  glTexCoord2f(0,0); glVertex3d(0,-30,3);
  glTexCoord2f(1,0); glVertex3d(0,-30,-3);

  glNormal3d(-1,-4,0);
  glTexCoord2f(0,0); glVertex3d(0,-30,-3);
  glTexCoord2f(1,0); glVertex3d(0,-30,3);
  glTexCoord2f(1,1); glVertex3d(-20,-25,3);
  glTexCoord2f(0,1); glVertex3d(-20,-25,-3);

  glNormal3d(-1,-1,0);
  glTexCoord2f(0,0); glVertex3d(-20,-25,-3);
  glTexCoord2f(1,0); glVertex3d(-20,-25,3);
  glTexCoord2f(1,1); glVertex3d(-30,-15,3);
  glTexCoord2f(0,1); glVertex3d(-30,-15,-3);

  glNormal3d(-1,0,0);
  glTexCoord2f(0,0); glVertex3d(-30,-15,-3);
  glTexCoord2f(1,0); glVertex3d(-30,-15,3);
  glTexCoord2f(1,1); glVertex3d(-30,-1,3);
  glTexCoord2f(0,1); glVertex3d(-30,-1,-3);

  glColor3f(0.1,0.075,0.1);
  glNormal3d(1,0,0); //inner surface, needs several normals
  glTexCoord2f(1,1); glVertex3d(-25,-1,-3);
  glTexCoord2f(0,1); glVertex3d(-25,-1,3);
  glTexCoord2f(0,0); glVertex3d(-25,-15,3);
  glTexCoord2f(1,0); glVertex3d(-25,-15,-3);

  glNormal3d(1,1,0);
  glTexCoord2f(1,1); glVertex3d(-25,-15,-3);
  glTexCoord2f(0,1); glVertex3d(-25,-15,3);
  glTexCoord2f(0,0); glVertex3d(-15,-25,3);
  glTexCoord2f(1,0); glVertex3d(-15,-25,-3);

  glNormal3d(2,15,0);
  glTexCoord2f(1,1); glVertex3d(-15,-25,-3);
  glTexCoord2f(0,1); glVertex3d(-15,-25,3);
  glTexCoord2f(0,0); glVertex3d(0,-27,3);
  glTexCoord2f(1,0); glVertex3d(0,-27,-3);

  glNormal3d(-2,15,0);
  glTexCoord2f(0,0); glVertex3d(0,-27,-3);
  glTexCoord2f(1,0); glVertex3d(0,-27,3);
  glTexCoord2f(1,1); glVertex3d(15,-25,3);
  glTexCoord2f(0,1); glVertex3d(15,-25,-3);

  glNormal3d(-1,1,0);
  glTexCoord2f(0,0); glVertex3d(15,-25,-3);
  glTexCoord2f(1,0); glVertex3d(15,-25,3);
  glTexCoord2f(1,1); glVertex3d(25,-15,3);
  glTexCoord2f(0,1); glVertex3d(25,-15,-3);

  glNormal3d(-1,0,0);
  glTexCoord2f(0,0); glVertex3d(25,-15,-3);
  glTexCoord2f(1,0); glVertex3d(25,-15,3);
  glTexCoord2f(1,1); glVertex3d(25,-1,3);
  glTexCoord2f(0,1); glVertex3d(25,-1,-3);
  glEnd();
  glDisable(GL_TEXTURE_2D);



  glBegin(GL_LINE_STRIP);
  glColor3f(1,0,1); //Outer surface highlight
  glVertex3d(30,-1,-3);

  glVertex3d(30,-15,-3);
  glVertex3d(30,-15,3);

  glVertex3d(20,-25,3);
  glVertex3d(20,-25,-3);

  glVertex3d(0,-30,-3);
  glVertex3d(0,-30,3);

  glVertex3d(-20,-25,3);
  glVertex3d(-20,-25,-3);

  glVertex3d(-30,-15,-3);
  glVertex3d(-30,-15,3);

  glVertex3d(-30,-1,3);
  glEnd();

  glRotated(45,0,1,0);
  glBegin(GL_LINE_STRIP);
  glColor3f(1,0.5,0); //Outer wire highlight
  glVertex3d(30,-1,-3);

  glVertex3d(30,-15,-3);
  glVertex3d(30,-15,3);

  glVertex3d(20,-25,3);
  glVertex3d(20,-25,-3);

  glVertex3d(0,-30,-3);
  glVertex3d(0,-30,3);

  glVertex3d(-20,-25,3);
  glVertex3d(-20,-25,-3);

  glVertex3d(-30,-15,-3);
  glVertex3d(-30,-15,3);

  glVertex3d(-30,-1,3);
  glEnd();

  glPopMatrix();

}

void stage(double x,double y, double z,
           double dx, double dy, double dz,
           double th)
{
  glPushMatrix();
  glTranslated(x,y,z);
  glScaled(dx,dy,dz);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex[0]);
  glColor3f(0.2,0.2,0.2);
  glBegin(GL_POLYGON); //Top octagon
  glNormal3d(0,1,0);
  glTexCoord2f(1,0.333); glVertex3d(50,0,10);
  glTexCoord2f(1,0.667); glVertex3d(50,0,-10);
  glTexCoord2f(0.8,1);   glVertex3d(30,0,-30);
  glTexCoord2f(0.2,1);   glVertex3d(-30,0,-30);
  glTexCoord2f(0,0.667); glVertex3d(-50,0,-10);
  glTexCoord2f(0,0.333); glVertex3d(-50,0,10);
  glTexCoord2f(0.2,0);   glVertex3d(-30,0,30);
  glTexCoord2f(0.8,0);   glVertex3d(30,0,30);
  glTexCoord2f(1,0.333); glVertex3d(50,0,10);
  glEnd();


  glBegin(GL_POLYGON); //bottom octagon
  glNormal3d(0,-1,0);
  glTexCoord2f(1,0.333); glVertex3d(50,-1,10);
  glTexCoord2f(1,0.667); glVertex3d(50,-1,-10);
  glTexCoord2f(0.8,1);   glVertex3d(30,-1,-30);
  glTexCoord2f(0.2,1);   glVertex3d(-30,-1,-30);
  glTexCoord2f(0,0.667); glVertex3d(-50,-1,-10);
  glTexCoord2f(0,0.333); glVertex3d(-50,-1,10);
  glTexCoord2f(0.2,0);   glVertex3d(-30,-1,30);
  glTexCoord2f(0.8,0);   glVertex3d(30,-1,30);
  glTexCoord2f(1,0.333); glVertex3d(50,-1,10);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,tex[2]);
  glBegin(GL_QUADS); //border quads to complete octagonal disk
  glNormal3d(1,0,0);
  glTexCoord2f(0,1); glVertex3d(50,0,10);
  glTexCoord2f(0,0); glVertex3d(50,-1,10);
  glTexCoord2f(1,0); glVertex3d(50,-1,-10);
  glTexCoord2f(1,1); glVertex3d(50,0,-10);

  glNormal3d(1,0,-1);
  glTexCoord2f(0,0); glVertex3d(50,-1,-10);
  glTexCoord2f(0,1); glVertex3d(50,0,-10);
  glTexCoord2f(1,1); glVertex3d(30,0,-30);
  glTexCoord2f(1,0); glVertex3d(30,-1,-30);

  glNormal3d(0,0,-1);
  glTexCoord2f(0,1); glVertex3d(30,0,-30);
  glTexCoord2f(0,0); glVertex3d(30,-1,-30);
  glTexCoord2f(1,0); glVertex3d(-30,-1,-30);
  glTexCoord2f(1,1); glVertex3d(-30,0,-30);

  glNormal3d(-1,0,-1);
  glTexCoord2f(1,0); glVertex3d(-50,-1,-10);
  glTexCoord2f(1,1); glVertex3d(-50,0,-10);
  glTexCoord2f(0,1); glVertex3d(-30,0,-30);
  glTexCoord2f(0,0); glVertex3d(-30,-1,-30);

  glNormal3d(-1,0,0);
  glTexCoord2f(1,1); glVertex3d(-50,0,10);
  glTexCoord2f(1,0); glVertex3d(-50,-1,10);
  glTexCoord2f(0,0); glVertex3d(-50,-1,-10);
  glTexCoord2f(0,1); glVertex3d(-50,0,-10);

  glNormal3d(-1,0,1);
  glTexCoord2f(0,0); glVertex3d(-50,-1,10);
  glTexCoord2f(0,1); glVertex3d(-50,0,10);
  glTexCoord2f(1,1); glVertex3d(-30,0,30);
  glTexCoord2f(1,0); glVertex3d(-30,-1,30);

  glNormal3d(0,0,1);
  glTexCoord2f(1,1); glVertex3d(30,0,30);
  glTexCoord2f(1,0); glVertex3d(30,-1,30);
  glTexCoord2f(0,0); glVertex3d(-30,-1,30);
  glTexCoord2f(0,1); glVertex3d(-30,0,30);

  glNormal3d(1,0,1);
  glTexCoord2f(0,0); glVertex3d(50,-1,10);
  glTexCoord2f(0,1); glVertex3d(50,0,10);
  glTexCoord2f(1,1); glVertex3d(30,0,30);
  glTexCoord2f(1,0); glVertex3d(30,-1,30);

  glColor3f(0.1,0.1,0.1); //Sloped quads under stage
  glBindTexture(GL_TEXTURE_2D,tex[2]);
  glNormal3d(1,-1,0);
  glTexCoord2f(0,1); glVertex3d(40,0,10);
  glTexCoord2f(1,1); glVertex3d(40,0,-10);
  glTexCoord2f(1,0); glVertex3d(30,-10,-10);
  glTexCoord2f(0,0); glVertex3d(30,-10,10);

  glNormal3d(-1,-1,0);
  glTexCoord2f(1,1); glVertex3d(-40,0,10);
  glTexCoord2f(0,1); glVertex3d(-40,0,-10);
  glTexCoord2f(0,0); glVertex3d(-30,-10,-10);
  glTexCoord2f(1,0); glVertex3d(-30,-10,10);

  glNormal3d(0,-1,1);
  glTexCoord2f(1,1); glVertex3d(30,0,20);
  glTexCoord2f(0,1); glVertex3d(-30,0,20);
  glTexCoord2f(0,0); glVertex3d(-30,-10,10);
  glTexCoord2f(1,0); glVertex3d(30,-10,10);

  glNormal3d(0,-1,-1);
  glTexCoord2f(0,1); glVertex3d(30,0,-20);
  glTexCoord2f(1,1); glVertex3d(-30,0,-20);
  glTexCoord2f(1,0); glVertex3d(-30,-10,-10);
  glTexCoord2f(0,0); glVertex3d(30,-10,-10);

  glNormal3d(0,-1,0);
  glTexCoord2f(1,1); glVertex3d(30,-10,10);
  glTexCoord2f(1,0); glVertex3d(30,-10,-10);
  glTexCoord2f(0,0); glVertex3d(-30,-10,-10);
  glTexCoord2f(0,1); glVertex3d(-30,-10,10);

  glEnd();


  glBegin(GL_TRIANGLES);//corner tri's for sloped quads
  glNormal3d(1,-1,1);
  glTexCoord2f(0,1);   glVertex3d(40,0,10);
  glTexCoord2f(0.5,0); glVertex3d(30,-10,10);
  glTexCoord2f(1,1);   glVertex3d(30,0,20);

  glNormal3d(-1,-1,1);
  glTexCoord2f(0,1);   glVertex3d(-40,0,10);
  glTexCoord2f(0.5,0); glVertex3d(-30,-10,10);
  glTexCoord2f(1,1);   glVertex3d(-30,0,20);

  glNormal3d(1,-1,-1);
  glTexCoord2f(0,1);   glVertex3d(40,0,-10);
  glTexCoord2f(0.5,0); glVertex3d(30,-10,-10);
  glTexCoord2f(1,1);   glVertex3d(30,0,-20);

  glNormal3d(-1,-1,-1);
  glTexCoord2f(0,1);   glVertex3d(-40,0,-10);
  glTexCoord2f(0.5,0); glVertex3d(-30,-10,-10);
  glTexCoord2f(1,1);   glVertex3d(-30,0,-20);
  glEnd();




  //Under Stage Rotating Polyons with Highlights
  stagePoly(0,0,0,0.99,1,1,th,1);
  stagePoly(0,0,0,0.99,1,1,th+90,1);
  stagePoly(0,0,0,0.95,0.95,0.95,th,-0.5);
  stagePoly(0,0,0,0.95,0.95,0.95,th+90,-0.5);


  glColor3f(0.1,0.075,0.5);
  sphere(0, -15, 0, 12,1);



  glDisable(GL_TEXTURE_2D); //only highlight lines from here, no lighting or textures


  glColor3f(1,0,1);
  glLineWidth(2);
  glBegin(GL_LINE_STRIP); //Top stage outline
  glVertex3d(50.1,0,10.1);
  glVertex3d(50.1,0,-10.1);
  glVertex3d(30.1,0,-30.1);
  glVertex3d(-30.1,0,-30.1);
  glVertex3d(-50.1,0,-10.1);
  glVertex3d(-50.1,0,10.1);
  glVertex3d(-30.1,0,30.1);
  glVertex3d(30.1,0,30.1);
  glVertex3d(50.1,0,10.1);
  glEnd();

  glBegin(GL_LINE_STRIP); //Middle stage outline
  glVertex3d(50.1,-1,10.1);
  glVertex3d(50.1,-1,-10.1);
  glVertex3d(30.1,-1,-30.1);
  glVertex3d(-30.1,-1,-30.1);
  glVertex3d(-50.1,-1,-10.1);
  glVertex3d(-50.1,-1,10.1);
  glVertex3d(-30.1,-1,30.1);
  glVertex3d(30.1,-1,30.1);
  glVertex3d(50.1,-1,10.1);
  glEnd();

  glBegin(GL_LINE_STRIP); //Lower stage outline
  glVertex3d(50.1,-2,10.1);
  glVertex3d(50.1,-2,-10.1);
  glVertex3d(30.1,-2,-30.1);
  glVertex3d(-30.1,-2,-30.1);
  glVertex3d(-50.1,-2,-10.1);
  glVertex3d(-50.1,-2,10.1);
  glVertex3d(-30.1,-2,30.1);
  glVertex3d(30.1,-2,30.1);
  glVertex3d(50.1,-2,10.1);
  glEnd();


  glBindTexture(GL_TEXTURE_2D,tex[4]);
  for (int i = 0; i<360; i+=45)
  {
    glEnable(GL_TEXTURE_2D);
    glRotated(i,0,1,0);
    glColor3f(0.2,0,1);
    glBegin(GL_QUADS);
    glNormal3d(3,-2,0);
    glTexCoord2f(0,0); glVertex3d(25,-25,-3);
    glTexCoord2f(1,0); glVertex3d(25,-25,3);
    glTexCoord2f(1,1); glVertex3d(35,-10,3);
    glTexCoord2f(0,1); glVertex3d(35,-10,-3);
    glNormal3d(7,-2,0);
    glTexCoord2f(0,0); glVertex3d(33,-10,5);
    glTexCoord2f(1,0); glVertex3d(33,-10,7);
    glTexCoord2f(1,1); glVertex3d(35,-3,7);
    glTexCoord2f(0,1); glVertex3d(35,-3,5);
    glNormal3d(7,-2,0);
    glTexCoord2f(0,0); glVertex3d(33,-10,-5);
    glTexCoord2f(1,0); glVertex3d(33,-10,-7);
    glTexCoord2f(1,1); glVertex3d(35,-3,-7);
    glTexCoord2f(0,1); glVertex3d(35,-3,-5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(25,-25,-3);
    glVertex3d(25,-25,3);
    glVertex3d(35,-10,3);
    glVertex3d(35,-10,-3);
    glEnd();
    glColor3f(1,0.5,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(33,-10,5);
    glVertex3d(33,-10,7);
    glVertex3d(35,-3,7);
    glVertex3d(35,-3,5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(33,-10,-5);
    glVertex3d(33,-10,-7);
    glVertex3d(35,-3,-7);
    glVertex3d(35,-3,-5);
    glEnd();
  }
  glTranslated(0,-10,0);
  glRotated(th,0,1,0);
  glScaled(0.83,0.83,0.83);
  for (int i = 0; i<360; i+=45)
  {
    glEnable(GL_TEXTURE_2D);
    glRotated(i,0,1,0);
    glColor3f(0.2,0,1);
    glBegin(GL_QUADS);
    glNormal3d(3,-2,0);
    glTexCoord2f(0,0); glVertex3d(25,-25,-3);
    glTexCoord2f(1,0); glVertex3d(25,-25,3);
    glTexCoord2f(1,1); glVertex3d(35,-10,3);
    glTexCoord2f(0,1); glVertex3d(35,-10,-3);
    glNormal3d(7,-2,0);
    glTexCoord2f(0,0); glVertex3d(33,-10,5);
    glTexCoord2f(1,0); glVertex3d(33,-10,7);
    glTexCoord2f(1,1); glVertex3d(35,-3,7);
    glTexCoord2f(0,1); glVertex3d(35,-3,5);
    glNormal3d(7,-2,0);
    glTexCoord2f(0,0); glVertex3d(33,-10,-5);
    glTexCoord2f(1,0); glVertex3d(33,-10,-7);
    glTexCoord2f(1,1); glVertex3d(35,-3,-7);
    glTexCoord2f(0,1); glVertex3d(35,-3,-5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(25,-25,-3);
    glVertex3d(25,-25,3);
    glVertex3d(35,-10,3);
    glVertex3d(35,-10,-3);
    glEnd();
    glColor3f(1,0.5,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(33,-10,5);
    glVertex3d(33,-10,7);
    glVertex3d(35,-3,7);
    glVertex3d(35,-3,5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(33,-10,-5);
    glVertex3d(33,-10,-7);
    glVertex3d(35,-3,-7);
    glVertex3d(35,-3,-5);
    glEnd();
  }



  glBegin(GL_QUAD_STRIP);
  for(int i = 0; i<=360; i++)
  {
    glNormal3d(Sin(i),0,Cos(i));
    glColor4f(0.8,0.8,0.8,0.4);
    glVertex3f(2*Sin(i),-1,2*Cos(i));
    glColor4f(0,0,0,0.3);
    glVertex3f(2*Sin(i),-100,2*Cos(i));
  }
  glEnd();


  glTranslated(0,-30,0);
  glRotated(th,0,1,0);
  glRotated(90,0,0,1);
  glScaled(30,30,30);
  //crazy curved surface I generated paritally by accident
  glColor3f(0.5,0,0.5);
  for(double i = -0.4; i<=0.45; i+=0.05){
    if(i<0){
      glBegin(GL_QUAD_STRIP);
      for(int j = 0; j<=360; j++){
        glNormal3d(Sin(j),-1*i,Cos(j));        glVertex3d(Sin(j)*i*i,i,Cos(j)*i*i);
        glNormal3d(Sin(j),-1*i+0.05,Cos(j));   glVertex3d(Sin(j)*(-1*i+0.05)*(-1*i+0.05),i+0.05,Cos(j)*(-1*i+0.05)*(-1*i+0.05));
      }
      glEnd();
    }
    else{
      glBegin(GL_QUAD_STRIP);
      for(int j = 0; j<=360; j++){
        glNormal3d(Sin(j),-1*i,Cos(j));     glVertex3d(Sin(j)*i*i,                     i,      Cos(j)*i*i);
        glNormal3d(Sin(j),i+0.05,Cos(j));   glVertex3d(Sin(j)*(-1*i+0.05)*(-1*i+0.05), i+0.05, Cos(j)*(-1*i+0.05)*(-1*i+0.05));
      }
      glEnd();
    }
  }



  glPopMatrix();
}
