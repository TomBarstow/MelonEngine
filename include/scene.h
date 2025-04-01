#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Renderer.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Define a simple cube model
struct Cube {
    std::vector<float> vertices = {
        // Positions          // Texture Coords  // Normals
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, 0.0f, -1.0f, // Back face
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f, 0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f, 0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f, // Front face
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2, 2, 3, 0,  // Back face
        4, 5, 6, 6, 7, 4,  // Front face
        0, 4, 7, 7, 3, 0,  // Left face
        1, 5, 6, 6, 2, 1,  // Right face
        3, 2, 6, 6, 7, 3,  // Top face
        0, 1, 5, 5, 4, 0   // Bottom face
    };

    void Draw(Renderer& renderer) {
        renderer.render(vertices, indices);
    }
};

// Scene class to manage multiple objects
class Scene {
public:
    std::vector<Cube> cubes;
    std::vector<glm::mat4> transforms;

    Scene() {
        addCube(glm::vec3(0.0f, 0.0f, -2.0f));  // Main cube
        addCube(glm::vec3(1.0f, 0.0f, -3.0f));  // Another cube
    }

    void addCube(glm::vec3 position) {
        cubes.push_back(Cube());
        transforms.push_back(glm::translate(glm::mat4(1.0f), position));
    }

    void render(Renderer& renderer, Shader& shader) {
        for (size_t i = 0; i < cubes.size(); i++) {
            shader.setMat4("model", transforms[i]);
            cubes[i].Draw(renderer);
        }
    }
};

#endif
#pragma once
