#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>

class Renderer {
private:
    GLuint VAO, VBO;
public:
    Renderer();
    void render();
    ~Renderer();
};

#endif
#pragma once
