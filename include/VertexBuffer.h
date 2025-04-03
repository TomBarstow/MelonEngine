#pragma once

#include <GL/glew.h>

struct VBO {
	GLuint id;
};

struct VAO {
	GLuint id;
};

//Create a VBO and store in VBO struct
VBO createVBO(const GLfloat* data, GLsizeiptr size);

//Create a VAO and store in VAO struct
VAO createVAO();

//Bind a VBO
void bindVBO(const VBO& vbo);

//Bind a VAO
void bindVAO(const VAO& vao);

//Unbind a VBO
void unbindVBO();

//Unbind a VAO
void unbindVAO();

//Delete a VBO
void deleteVBO(const VBO& vbo);

//Delete a VAO
void deleteVAO(const VAO& vao);