#ifndef GLFW_EVENTS_H
#define GLFW_EVENTS_H

#include <GLFW/glfw3.h>

#include "./window.h"

void main_events(GLFWwindow* glfwwindow, GL_window_s* gl_window, Camera* camera);
void glfw_poll_events(GLFWwindow* window);

#endif
