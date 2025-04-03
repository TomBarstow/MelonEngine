
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#include <iostream>

#include <Console.h>
#include <InputManager.h>
#include <VertexBuffer.h>


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
    //InputManager input;
    InputManager::initialize(window);

    //Test Triforce Render
    GLfloat triforce[] = {
        // Top triangle
    -0.3f,  0.0f,  0.0f,  // Vertex 1
     0.3f,  0.0f,  0.0f,  // Vertex 2
     0.0f,  0.5f,  0.0f,  // Vertex 3

        // Left triangle
    -0.6f, -0.5f,  0.0f,  // Vertex 4
    0.0f, -0.5f,  0.0f,  // Vertex 5
    -0.3f,  0.0f,  0.0f,  // Vertex 6

        // Right triangle
    0.0f, -0.5f,  0.0f,  // Vertex 7
    0.6f, -0.5f,  0.0f,  // Vertex 8
    0.3f,  0.0f,  0.0f   // Vertex 9
    };

    VBO vbo = createVBO(triforce, sizeof(triforce));
    VAO vao = createVAO();
    bindVBO(vbo);
    bindVAO(vao);

    // Define the vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VBO and VAO
    unbindVBO();
    unbindVAO();



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //Testing input manager to console
        InputManager::update();

        if (InputManager::actionPressed("Forward")) {
            Console("W key - Forward");
        }
        else if (InputManager::actionPressed("Backward")) {
            Console("S key - Backward");
        }
        else if (InputManager::actionPressed("Left")) {
            Console("A key - Left");
        }
        else if (InputManager::actionPressed("Right")) {
            Console("D key - Right");
        }
        
        /* Render here */
        bindVAO(vao);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 9);
        unbindVAO();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    // Cleanup
    deleteVBO(vbo);
    deleteVAO(vao);

    //Terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}