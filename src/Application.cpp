
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#include <iostream>

#include <Console.h>
#include <InputManager.h>


int main(void)
{
    //GLFW Library Initialization
    if (!glfwInit())
        return -1;
    Console("GLFW Initialized");

    //OpenGL Version and Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //Create window (window mode) in OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 800, "Melon Engine Demo", NULL, NULL);
    if (!window)
    {
        Console("Error creating GLFW window! \_(-_-)_/");
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //VSYNC
    glfwSwapInterval(1);

    // GLEW Initialization
    glewInit();

    if (glewInit() != GLEW_OK) {
        Console("Error initializing GLEW!");
        glfwTerminate();
        return -1;
    }

    //Initialize Input Manager
    InputManager input;
    input.initialize(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //Testing input manager to console
        input.update();

        if (input.keyPressed(GLFW_KEY_W)) {
            Console("W key");
        }
        
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

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}