#include "fd.h"
void skybox(double D, double dim, double theta) //skybox function adapted from ex24.
{
   glPushMatrix();
   glRotated(theta,0,1,0);

   glColor3f(1,1,1);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D,tex[0]);
   glBegin(GL_QUADS);
   glTexCoord2f(1,0); glVertex3f(+D,-D,-D); //front quad
   glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
   glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
   glTexCoord2f(1,1); glVertex3f(+D,+D,-D);

   glTexCoord2f(1,0); glVertex3f(-D,-D,+D); //left quad
   glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
   glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
   glTexCoord2f(1,1); glVertex3f(-D,+D,+D);

   glTexCoord2f(0,0); glVertex3f(+D,-D,+D); //right quad
   glTexCoord2f(1,0); glVertex3f(+D,-D,-D);
   glTexCoord2f(1,1); glVertex3f(+D,+D,-D);
   glTexCoord2f(0,1); glVertex3f(+D,+D,+D);

   glTexCoord2f(0,0); glVertex3f(+D,-D,+D); //back quad
   glTexCoord2f(1,0); glVertex3f(-D,-D,+D);
   glTexCoord2f(1,1); glVertex3f(-D,+D,+D);
   glTexCoord2f(0,1); glVertex3f(+D,+D,+D);
   glEnd();

   glColor3f(0,0,0);
   glBegin(GL_QUADS);
   glTexCoord2f(1,0); glVertex3f(+D,+D,-D); //top quad
   glTexCoord2f(0,0); glVertex3f(-D,+D,-D);
   glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
   glTexCoord2f(1,1); glVertex3f(+D,+D,+D);

   glTexCoord2f(1,0); glVertex3f(+D,-D,-D); //bottom quad
   glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
   glTexCoord2f(0,1); glVertex3f(-D,-D,+D);
   glTexCoord2f(1,1); glVertex3f(+D,-D,+D);
   glEnd();

   glDisable(GL_TEXTURE_2D);



   glRotated(theta,0,1,0);

   glColor3f(0.0,0.0,0.0);
   for(int i = 0; i<25; i++){
     glRotated(i*i+10,0,1,0);
     (i%2==0) ? glTranslated(0,i*i,0) : glTranslated(0,-i*i,0);
     glBegin(GL_LINE_STRIP);
     glVertex3f(3*dim,-4*dim,0);
     glVertex3f(3*dim,-4*dim,40);
     glVertex3f(3*dim,-3*dim,40);
     glVertex3f(3*dim,-3*dim,-25);
     glVertex3f(3*dim,-2*dim,-25);
     glVertex3f(3*dim,-2*dim,0);
     glVertex3f(3*dim,-dim,0);
     glVertex3f(3*dim,-dim,50);
     glVertex3f(3*dim,0,50);
     glVertex3f(3*dim,0,-20);
     glVertex3f(3*dim,dim,-20);
     glVertex3f(3*dim,dim,10);
     glVertex3f(3*dim,2*dim,10);
     glVertex3f(3*dim,2*dim,-30);
     glVertex3f(3*dim,3*dim,-30);
     glVertex3f(3*dim,3*dim,30);
     glVertex3f(3*dim,4*dim,30);
     glEnd();
   }


   glPopMatrix();
}
