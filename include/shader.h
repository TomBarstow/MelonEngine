#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    GLuint ID;

    // Constructor: loads & compiles shaders
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    // Activate the shader
    void use();

    // Utility function to set uniform variables
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

    // Destructor
    ~Shader();
};

#endif
#pragma once
