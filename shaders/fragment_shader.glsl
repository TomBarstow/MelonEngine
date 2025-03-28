#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoords;
in vec3 Normal;

uniform sampler2D texture_diffuse;
uniform vec3 lightColor;

void main() {
    vec3 color = texture(texture_diffuse, TexCoords).rgb;
    FragColor = vec4(color * lightColor, 1.0);
}
