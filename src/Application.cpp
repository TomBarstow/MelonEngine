#include <iostream>

#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Melon Engine Demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES); //top
        glVertex2f(-0.3f, 0.0f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(0.0f, 0.5f);
        glBegin(GL_TRIANGLES);  //left
        glVertex2f(-0.6f, -0.5f);
        glVertex2f(0.0f, -0.5f);
        glVertex2f(-0.3f, 0.0f);
        glBegin(GL_TRIANGLES);  //right
        glVertex2f(0.0f, -0.5f);
        glVertex2f(0.6f, -0.5f);
        glVertex2f(0.3f, 0.0f);

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}