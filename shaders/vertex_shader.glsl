#version 330 core

layout(location = 0) in vec3 aPos;   // Vertex position
layout(location = 1) in vec3 aNormal; // Vertex normal

out vec3 FragPos;   // Pass position to fragment shader
out vec3 Normal;    // Pass normal to fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0)); // Transform position to world space
    Normal = mat3(transpose(inverse(model))) * aNormal; // Transform normal

    gl_Position = projection * view * model * vec4(aPos, 1.0);
}