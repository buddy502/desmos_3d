#include "./common.h"
#include <math.h>

Color convert_to_rgb(Vec3f pixels) {
   Color color = {
      (unsigned char)(255.0 * CLAMP(pixels.x, 0.0, 1.0)),
      (unsigned char)(255.0 * CLAMP(pixels.y, 0.0, 1.0)),
      (unsigned char)(255.0 * CLAMP(pixels.z, 0.0, 1.0)),
   };
   return color;
}

//Vec3f trace_ray(Camera* camera, cube_s* cube) {
//   f32 closest_dist = INFINITY;
//   Vec3f hit_color = {0, 0, 0};
//
//   return hit_color;
//}
