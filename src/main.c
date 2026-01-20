#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <GLFW/glfw3.h>

#include "../include/glfwEvents.h"

#define fprinterr fprintf(stderr, "error: %s\n", strerror(errno))

int main() {
   if (!glfwInit()) {
      fprinterr;
      return 1;
   }

   GLFWwindow* glfwwindow = glfwCreateWindow(800, 600, "desmos", NULL, NULL);
   if (!glfwwindow) {
      glfwTerminate();
      return 1;
   }

   main_events(glfwwindow);

   return 0;
}
