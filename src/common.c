#include "./common.h"

PixelRGB convert_to_rgb(PixelRGB* pixels) {
   PixelRGB color = {
      (unsigned char)(255.0 * CLAMP(pixels->r, 0.0, 1.0)),
      (unsigned char)(255.0 * CLAMP(pixels->g, 0.0, 1.0)),
      (unsigned char)(255.0 * CLAMP(pixels->b, 0.0, 1.0)),
   };
   return color;
}
