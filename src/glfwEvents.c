#include <stdio.h>

#include "../include/glfwEvents.h"

static void character_callback(GLFWwindow* window, unsigned int codepoint)
{
}

void main_events(GLFWwindow* glfwwindow) {
   glfwMakeContextCurrent(glfwwindow);

   while (!glfwWindowShouldClose(glfwwindow)) {
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(glfwwindow);

      glfwPollEvents();

      glfw_poll_events(glfwwindow);
   }

   glfwTerminate();
}

void glfw_poll_events(GLFWwindow* window) {
   glfwSetCharCallback(window, character_callback);
}
