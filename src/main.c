#include <stdio.h>
#include <stdbool.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "./glfwEvents.h"
#include "./window.h"

/*
#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
   x;\
   ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError() {
   while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line) {
   // convert to words
   GLenum error = glGetError();
   while (error) {
      const GLubyte* errString = gluErrorString(error);
      printf("OpenGL Error (%p): %p %p: %d", errString, function, file, line);

      return false;
   }
   return true;
}
*/

int main() {
   if (!glfwInit()) {
      return 1;
   }

   GL_window_s* gl_window = NULL;
   ALLOC_ZEROED(gl_window, GL_window_s);

   gl_window->win_width = 800;
   gl_window->win_height = 600;

   Camera* camera = NULL;
   ALLOC_ZEROED(camera, Camera);
   camera->fov = 90;
   camera->direction = (Vec3f){0, 0, 0};
   camera->origin = (Vec3f){0, 0, -1};

   GLFWwindow* glfwwindow = glfwCreateWindow(gl_window->win_width, gl_window->win_height,
         "desmos", NULL, NULL);
   if (!glfwwindow) {
      glfwTerminate();
      return 1;
   }

   glfwGetWindowSize(glfwwindow, &gl_window->win_width, &gl_window->win_height);

   glfwSetWindowUserPointer(glfwwindow, &gl_window);
   glfwSetFramebufferSizeCallback(glfwwindow, framebuffer_size_callback);

   main_events(glfwwindow, gl_window, camera);

   return 0;
}
