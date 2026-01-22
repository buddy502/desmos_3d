#ifndef COMMON_H
#define COMMON_H

#include <GLFW/glfw3.h>

#define CLAMP(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

typedef struct {
   unsigned char r;
   unsigned char g;
   unsigned char b;
} PixelRGB;

typedef struct {
   float x;
   float y;
   float z;
} Vec3f;

PixelRGB convert_to_rgb(PixelRGB* pixels);

#endif
