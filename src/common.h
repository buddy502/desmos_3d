#ifndef COMMON_H
#define COMMON_H

#include <GLFW/glfw3.h>

#define CLAMP(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

typedef struct {
   GLuint red;
   GLuint green;
   GLuint blue;
} GL_color3f_s;

typedef struct {
   float x;
   float y;
   float z;
} Vec3f;

GL_color3f_s convert_to_rgb(float r, float g, float b);

#endif
