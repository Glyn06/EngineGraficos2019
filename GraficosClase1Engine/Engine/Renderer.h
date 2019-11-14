#ifndef RENDERER_H
#define RENDERER_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include "glew.h"
#include "GLFW/glfw3.h"

#include "Window.h"

#include <iostream>


using namespace std;

class EXPORTER Renderer
{
private:
	unsigned int _buffer;
	float x;
	float y;
	float rotat;
	
	//Shape* shape;
public:
	Renderer();
	void Draw(GLFWwindow* windows);
	void movingRotatingAndScale();
	void SpinTriangle(float speed);
	void MovePositionShape(float x, float y);
	void RotatationShape(float rot);

	//void DumbCodeSquareTextured();
	void LoadTexture();
	//void LoadTextureToShader();

	void LoadShaders2(GLfloat _vertex[]);	//shaders without color, it gets loaded in bind
	void Bind(GLfloat _vertex[], GLint _index[], int _vertexSize, int _indexSize);	//for shape also loads into shader
	void Draw(GLfloat _vertex[], int _arraySize);	//no primitive needed to pass
	~Renderer();
};
#endif

