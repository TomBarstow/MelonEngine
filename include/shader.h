#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
public:
    GLuint ID;

    // Constructor: loads & compiles shaders
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    // Activate the shader
    void use();

    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

    // Destructor
    ~Shader();
};

#endif
