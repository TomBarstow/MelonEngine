#include "Renderer.h"

// Define cube vertices (Position, Texture Coords)
float vertices[] = {
    // Positions         // Texture Coords
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  // 0
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  // 1
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  // 2
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  // 3

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  // 4
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  // 5
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  // 6
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f   // 7
};

// Define cube indices (2 triangles per face, 6 faces)
unsigned int indices[] = {
    0, 1, 2, 2, 3, 0,  // Back face
    4, 5, 6, 6, 7, 4,  // Front face
    0, 4, 7, 7, 3, 0,  // Left face
    1, 5, 6, 6, 2, 1,  // Right face
    3, 2, 6, 6, 7, 3,  // Top face
    0, 1, 5, 5, 4, 0   // Bottom face
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture Coordinate Attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
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