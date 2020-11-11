#include "fd.h"

void sphere(double x,double y,double z,
                   double r, int tex) //FROM ex8
{
   const int d=15;
   int th,ph;
   if (tex<0 || tex>7){
     printf("texture does not exist");
     exit(0);
   }

   //  Save transformation
   glPushMatrix();
   //  Offset and scale
   glTranslated(x,y,z);
   glScaled(r,r,r);

   glEnable(GL_TEXTURE_2D);


   //  Latitude bands
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
   glDisable(GL_TEXTURE_2D);
}

void stagePoly(double x, double y, double z,
               double dx, double dy, double dz,
               double th, double s){
  glPushMatrix();
  glTranslated(x,y,z);
  glRotated(th*s,0,1,0);
  glScaled(dx,dy,dz);

  glEnable(GL_TEXTURE_2D);

  glColor3f(0.1,0.075,0.1);
  glBegin(GL_QUAD_STRIP);

  glNormal3d(0,0,1); //front surface, same normal throughout
  glTexCoord2f(1,1);           glVertex3d(30,0,3);
  glTexCoord2f(0.9167,1);      glVertex3d(25,0,3);

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

  glTexCoord2f(0.0833,1);      glVertex3d(-25,0,3);
  glTexCoord2f(0,1);           glVertex3d(-30,0,3);

  glEnd();


  glBegin(GL_QUAD_STRIP);

  glNormal3d(0,0,-1);//back surface, same normal throughout
  glTexCoord2f(1,1);           glVertex3d(-30,0,-3);
  glTexCoord2f(0.9167,1);      glVertex3d(-25,0,-3);

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

  glTexCoord2f(0.0833,1);      glVertex3d(25,0,-3);
  glTexCoord2f(0,1);           glVertex3d(30,0,-3);

  glEnd();

  glColor3f(0.2,0.1,0.2);
  glBegin(GL_QUADS);

  glNormal3d(1,0,0); //Outer surface, needs several normals
  glTexCoord2f(1,1); glVertex3d(30,0,-3);
  glTexCoord2f(0,1); glVertex3d(30,0,3);
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
  glTexCoord2f(1,1); glVertex3d(-30,0,3);
  glTexCoord2f(0,1); glVertex3d(-30,0,-3);

  glEnd();



  glBegin(GL_QUADS);

  glColor3f(0.1,0.075,0.1);
  glNormal3d(1,0,0); //inner surface, needs several normals
  glTexCoord2f(1,1); glVertex3d(-25,0,-3);
  glTexCoord2f(0,1); glVertex3d(-25,0,3);
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
  glTexCoord2f(1,1); glVertex3d(25,0,3);
  glTexCoord2f(0,1); glVertex3d(25,0,-3);

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
  //glRotated(th,0,1,0);
  glScaled(dx,dy,dz);

  glEnable(GL_TEXTURE_2D);
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
  sphere(0, -15, 0, 10,2);


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

  glPopMatrix();
}
