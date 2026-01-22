#include <stdio.h>

#include "./glfwEvents.h"

static void cursor_enter_callback(GLFWwindow* window, int entered)
{
   if (entered) printf("entered viewport\n");
}

static void character_callback(GLFWwindow* window, unsigned int codepoint)
{
}

void main_events(GLFWwindow* glfwwindow, GL_window_s* gl_window, Camera* camera) {
   glfwMakeContextCurrent(glfwwindow);

   glClear(GL_COLOR_BUFFER_BIT);

   glViewport(0, 0, 800, 600);

   while (!glfwWindowShouldClose(glfwwindow)) {

      render_window_pixels(gl_window, camera);

      glfwSwapBuffers(glfwwindow);
      glfwPollEvents();
      glfw_poll_events(glfwwindow);
   }

   glfwTerminate();
}

void glfw_poll_events(GLFWwindow* window) {
   glfwSetCharCallback(window, character_callback);
   //glfwSetCursorEnterCallback(window, cursor_enter_callback);
}
