#ifndef fd
#define fd

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))

#ifdef __cplusplus
extern "C" {
#endif

void stage(double x,double y, double z, double dx, double dy, double dz, double th);
void stagePoly(double x, double y, double z, double dx, double dy, double dz, double th, double s);
void sphere(double x,double y,double z, double r, int tex);
void Fatal(const char* format , ...);
unsigned int LoadTexBMP(const char* file);
void ErrCheck(const char* where);

#ifdef __cplusplus
}
#endif

#endif
