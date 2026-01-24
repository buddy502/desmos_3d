#ifndef COMMON_H
#define COMMON_H

#include "./cube.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;

typedef struct {
   unsigned char r;
   unsigned char g;
   unsigned char b;
} Color;

typedef struct {
   f32 x;
   f32 y;
   f32 z;
} Vec3f;

// TODO: zoom does not affect zoom in on cube just
//       the zoom on the actual graph in the cube
typedef struct {
   f32 fov;
   Vec3f origin;
   Vec3f direction;
} Camera;

//Vec3f trace_ray(Camera* camera, cube_s* cube);
Color convert_to_rgb(Vec3f pixels);

#define CLAMP(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

#define ALLOC_ZEROED(ptr, type)          \
   do {                                \
      ptr = calloc(1, sizeof(type));   \
      if (!(ptr)) {                    \
         fprintf(stderr, #ptr " allocation failed: %s\n", strerror(errno)); \
      }                                                                     \
   } while(0)

#endif
