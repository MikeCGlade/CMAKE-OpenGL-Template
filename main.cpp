//GLFW Template for CMake Projects
//Make sure to reload project after implementing the libraries or CLION will false positive

/**
 * I spent too much time trying to figure out CMAKE so here is a template I made for reference because
 * I know I will forget the material again when I have classes.
 *
 * Furthermore, this is a great starting point for beginners in graphics programming. OpenGL is comparably more simple
 * out of the three main graphics libraries however the same principles are applied in different context.
 * Once a proficient level has been met mathematically then moving on to the newer more
 * modern libraries will be more applicable.
 *
 * Below is a simple window rendered to the screen for testing purposes.
 *
 * Also don't forget about this resource: https://learnopengl.com/Introduction
 */

#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "GLFW Test", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}