#include <glad/gl.h>

#include <GLFW/glfw3.h>
#include <iostream>

int main(void) {
  GLFWwindow *window;
  if (!glfwInit())
    return -1;

  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  int version = gladLoadGL(glfwGetProcAddress);
  if (version == 0) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}