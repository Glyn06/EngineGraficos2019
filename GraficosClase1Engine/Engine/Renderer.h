#ifndef RENDERER_H
#define RENDERER_H
#include"glew.h"
#include "GLFW/glfw3.h"



#include "Window.h"
#include <iostream>


using namespace std;

class Renderer
{
private:
	unsigned int _buffer;
	float x;
	float y;
	float rotat;
public:
	Renderer();
	void DumbCodeTriangle();
	void DumbCodeSquare();
	void LoadShaders();
	void Draw(GLFWwindow* windows);
	void movingRotatingAndScale();
	void SpinTriangle(int speed);
	void MovePositionShape(float x, float y);
	void RotatationShape(float rot);
	~Renderer();
};
#endif

