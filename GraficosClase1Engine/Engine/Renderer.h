#ifndef RENDERER_H
#define RENDERER_H
#include"glew.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <iostream>


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

