#ifndef RENDERER_H
#define RENDERER_H
#include"glew.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <iostream>

#include <iostream>
using namespace std;

class Renderer
{
private:
	unsigned int _buffer;
public:
	Renderer();
	void DumbCodeTriangle();
	void DumbCodeSquare();
	void LoadShaders();
	void Draw(GLFWwindow* windows);

	void SpinTriangle(int speed);
	~Renderer();
};
#endif

