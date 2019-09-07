#ifndef RENDERER_H
#define RENDERER_H
#include"glew.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <iostream>

/*
float position[6]
{
	-0.5f, -0.5f,
	0.0f, -0.5f,
	0.5f, -0.5f,
};
*/
class Renderer
{
private:
	
public:
	Renderer();
	void DumbCodeTriangle();
	void DumbCodeSquare();
	void LoadShaders();
	void Draw(GLFWwindow* windows);
	~Renderer();
};
#endif

