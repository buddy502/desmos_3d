#include "./common.h"

GL_color3f_s convert_to_rgb(float r, float g, float b) {
   GL_color3f_s color = {
      CLAMP(r, 0.0, 1.0),
      CLAMP(g, 0.0, 1.0),
      CLAMP(b, 0.0, 1.0),
   };
   return color;
}
