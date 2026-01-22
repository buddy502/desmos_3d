#ifndef WINDOW_H
#define WINDOW_H

#include "./common.h"

#include <GLFW/glfw3.h>

#define MAX_VIEWPORTS 25

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct {
   int win_width;
   int win_height;

   GLint viewports[MAX_VIEWPORTS];
} GL_window_s;

// TODO: zoom does not affect zoom in on cube just
//       the zoom on the actual graph in the cube
typedef struct {
   float fov;
   Vec3f origin;
   Vec3f direction;
} Camera;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void render_window_pixels(GL_window_s gl_window, Camera camera);

#endif
