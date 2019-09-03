#include "Renderer.h"
#include"glew.h"
#include"GLFW/glfw3.h"

#include <iostream>
using namespace std;
float vertices[] = {
	 0.0f,  0.5f, // Vertex 1 (X, Y)
	 0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)
};

Renderer::Renderer()
{
	glewInit();
	
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	GLuint vbo;
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glsl ver
}

void Renderer::Draw() 
{
	//gl clear
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	


	//glfw swapbuffers
}

Renderer::~Renderer()
{
	
}
