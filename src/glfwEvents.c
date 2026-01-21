#include <stdio.h>

#include "./glfwEvents.h"

static void cursor_enter_callback(GLFWwindow* window, int entered)
{
   if (entered) printf("entered viewport\n");
}

static void character_callback(GLFWwindow* window, unsigned int codepoint)
{
}

void main_events(GLFWwindow* glfwwindow, GL_window_s gl_window, Camera camera) {
   glfwMakeContextCurrent(glfwwindow);

   //glViewport(1920/2, 1080/2, 800, 600);

   while (!glfwWindowShouldClose(glfwwindow)) {
      glfwSwapBuffers(glfwwindow);

      render_window_pixels(glfwwindow, gl_window, camera);
      glfwPollEvents();

      glfw_poll_events(glfwwindow);
   }

   glfwTerminate();
}

void glfw_poll_events(GLFWwindow* window) {
   glfwSetCharCallback(window, character_callback);
   //glfwSetCursorEnterCallback(window, cursor_enter_callback);
}
