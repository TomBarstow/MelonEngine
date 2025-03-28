#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Shader.h"
#include "Renderer.h"
#include "camera.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Melon Engine v0", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();

    Camera camera(glm::vec3(0.0f, 0.0f, 0.0f)); // Initialize Camera at position (0,0,0)

    glm::vec3 lightPos = glm::vec3(2.0f, 3.0f, 5.0f); // Fixed light in world space

    Shader shader("C:/Users/Disco/source/repos/MelonEngine/shaders/vertex_shader.glsl", "C:/Users/Disco/source/repos/MelonEngine/shaders/fragment_shader.glsl");
    Renderer renderer;

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        //Change cube color with time
        float time = glfwGetTime();
        glm::vec3 objectColor;
        objectColor.x = sin(time * 2.0f) * 0.5f + 0.5f;  // Red oscillates between 0 and 1
        objectColor.y = sin(time * 0.7f) * 0.5f + 0.5f;  // Green oscillates
        objectColor.z = sin(time * 1.3f) * 0.5f + 0.5f;  // Blue oscillates

        shader.setVec3("lightPos", lightPos); // Light position
        shader.setVec3("viewPos", camera.Position); // Camera position
        shader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f)); // White light
        shader.setVec3("objectColor", objectColor); // Cube color

        //Rotate the cube
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.5f, 1.0f)); // Rotate over time

        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)); // Move cube
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        shader.setMat4("model", model);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);


        renderer.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
