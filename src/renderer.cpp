#include "Renderer.h"

// Define cube vertices (Position, Texture Coords)
float vertices[] = {
    // Positions           // Texture Coords // Normals
    // Back face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f,  0.0f, -1.0f, // 0
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f, // 1
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f, // 2
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f,  0.0f, -1.0f, // 3

    // Front face
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f, // 4
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f,  0.0f,  1.0f, // 5
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f, // 6
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,  0.0f,  1.0f, // 7

    // Left face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f, // 8
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f, // 9
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f, // 10
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f, // 11

    // Right face
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  1.0f,  0.0f,  0.0f, // 12
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f, // 13
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  1.0f,  0.0f,  0.0f, // 14
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f, // 15

     // Bottom face
     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, -1.0f,  0.0f, // 16
      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f, // 17
      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  0.0f, -1.0f,  0.0f, // 18
     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  0.0f, -1.0f,  0.0f, // 19

     // Top face
     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,  0.0f,  1.0f,  0.0f, // 20
      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,  0.0f,  1.0f,  0.0f, // 21
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f,  1.0f,  0.0f, // 22
     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,  1.0f,  0.0f  // 23
};

// Define cube indices (2 triangles per face, 6 faces)
unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,   // Back face
    4, 5, 6, 6, 7, 4,   // Front face
    8, 9, 10, 10, 11, 8, // Left face
    12, 13, 14, 14, 15, 12, // Right face
    16, 17, 18, 18, 19, 16, // Bottom face
    20, 21, 22, 22, 23, 20  // Top face
};

// VAO, VBO, EBO
unsigned int VAO, VBO, EBO;

Renderer::Renderer() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // Bind and fill VBO (Vertex Data)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind and fill EBO (Element Buffer)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position Attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture Coordinate Attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

// Render the cube
void Renderer::render() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

// Cleanup
Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}