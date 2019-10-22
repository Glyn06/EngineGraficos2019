#ifndef RENDERER_H
#define RENDERER_H
#include"glew.h"
#include "GLFW/glfw3.h"

#include "../stb_image.h"
//#include "TextureLoader.h"
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

	void DumbCodeSquareTextured();
	void LoadTexture();
	//void LoadTextureToShader();

	void LoadShaders2(GLfloat _vertex[]);	//shaders without color, it gets loaded in bind
	void Bind(GLfloat _vertex[], int _arraySize);	//for shape also loads into shader
	void Draw(GLfloat _vertex[], int _arraySize);	//no primitive needed to pass
	~Renderer();
};
#endif

