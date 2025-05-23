#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPos;   // Light source position
uniform vec3 viewPos;    // Camera position
uniform vec3 lightColor; // Light color
uniform vec3 objectColor; // Cube color

void main() {
    // Normalize inputs
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    // 1. Ambient lighting (small constant light everywhere)
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // 2. Diffuse lighting (depends on angle)
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // 3. Specular lighting (shiny reflections)
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Final color calculation
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
    }