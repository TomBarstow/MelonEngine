#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <vector>

class Renderer {
public:
    Renderer() = default; // No need for default VAO/VBO setup in constructor

    // Render function that takes in vertex and index data
    void render(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

    ~Renderer() = default; // No dynamically allocated memory to clean up
};

#endif