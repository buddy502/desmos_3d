#include <stdlib.h>

#include <math.h>

#include "./window.h"
#include "./common.h"

static Vec3f* initialize_pixels(GL_window_s* window, Vec3f* pixels) {
   for (int i = 0; i < window->win_width * window->win_height; i++) {
      pixels[i].x = 0.0f;
      pixels[i].y = 0.0f;
      pixels[i].z = 0.0f;
   }

   return pixels;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    GL_window_s* size = (GL_window_s*)glfwGetWindowUserPointer(window);
    size->win_width = width;
    size->win_height = height;
}

void render_window_pixels(GL_window_s* gl_window, Camera* camera, PixelRGB* framebuffer) {
   float aspect_ratio = (float)gl_window->win_width / (float)gl_window->win_height;
   float scale = tan((camera->fov/2.0));

   glBegin(GL_POINTS);
   for (int i = 0; i < gl_window->win_height; i++) {
      for (int j = 0; j < gl_window->win_width; j++) {

         float x = -(2.0 * ((float)j + 0.5) / (float)gl_window->win_width - 1.0) * scale * aspect_ratio;
         float y =  (2.0 * ((float)i + 0.5) / (float)gl_window->win_height - 1.0) * scale;

         framebuffer[x + y * gl_window->win_width] = convert_to_rgb(framebuffer);
      }
   }
   glEnd();
}
