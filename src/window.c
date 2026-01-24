#include <stdio.h>
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

void render_window_pixels(GL_window_s* gl_window, Camera* camera) {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, gl_window->win_width, 0, gl_window->win_height, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   float aspect_ratio = (float)gl_window->win_width / (float)gl_window->win_height;
   float scale = tan(camera->fov * 0.5f * (M_PI / 180.0f));

   glBegin(GL_POINTS);
   for (u32 i = 0; i < gl_window->win_height; i++) {
      for (u32 j = 0; j < gl_window->win_width; j++) {

         // make coordinates normalized to: (-1, 1)
         f32 x = -(2.0f * ((float)j + 0.5f) / (float)gl_window->win_width - 1.0f) * scale * aspect_ratio;
         f32 y =  (2.0f * ((float)i + 0.5f) / (float)gl_window->win_height - 1.0f) * scale;

         camera->direction = (Vec3f){x, y, -1.0f};

         Vec3f color = { j / (float)gl_window->win_width, i / (float)gl_window->win_height, 0.0f };
         Color pixel = convert_to_rgb(color);

         glColor3ub(pixel.r, pixel.g, pixel.b);
         glVertex2i(j, gl_window->win_height - 1 - i);
      }
   }
   glEnd();
}
