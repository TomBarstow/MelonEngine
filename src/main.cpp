#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Shader.h"
#include "Renderer.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Melon Engine v0", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    Shader shader("C:/Users/Disco/source/repos/MelonEngine/shaders/vertex_shader.glsl", "C:/Users/Disco/source/repos/MelonEngine/shaders/fragment_shader.glsl");
    Renderer renderer;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        renderer.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
