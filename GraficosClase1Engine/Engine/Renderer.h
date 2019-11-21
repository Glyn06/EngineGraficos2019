#ifndef RENDERER_H
#define RENDERER_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER



#include "Window.h"
#include <iostream>

struct Vertex {
	float x, y;
	float r, g, b, a;
	float u, v;
};

using namespace std;
class EXPORTER Renderer
{
private:
	unsigned int _buffer;
	float x;
	float y;
	float rotat;
	Window* window;
	//Shape* shape;
public:
	Renderer();
	void Draw();
	void movingRotatingAndScale();
	void SpinTriangle(float speed);
	void MovePositionShape(float x, float y);
	void RotatationShape(float rot);

	//void DumbCodeSquareTextured();
	void LoadTexture(unsigned char* data, int width, int height);
	//void LoadTextureToShader();

	void LoadShaders2(float _vertex[]);	//shaders without color, it gets loaded in bind
	void Bind(Vertex* vertexBuffer, int _index[], int _vertexSize, int _indexSize);	//for shape also loads into shader
	//void BindEntityData(Vertex* vertexBuffer, int* indexBuffer, int verN, int indN);	//interfaz para que pueda pasarle a bind el vertex* como glufloat
	~Renderer();
};
#endif

