#ifndef RENDERER_H
#define RENDERER_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER


#include "Shape.h"
#include "Sprite.h"
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
	//Window* window;
	//Shape* shape;
	
public:


	Renderer();
	void Draw();
	void movingRotatingAndScale();
	void movingRotatingAndScaleUnMoving(float unmx, float unmy);
	void SpinTriangle(float speed);
	void MovePositionShape(float x, float y);
	void RotatationShape(float rot);

	//void DumbCodeSquareTextured();
	void LoadTexture(Entity* ent);
	
	//void LoadTextureToShader();

	void LoadShaders2(float _vertex[]);	//shaders without color, it gets loaded in bind
	void Bind(Vertex* vertexBuffer, int _index[], int _vertexSize, int _indexSize);	//for shape also loads into shader
	void Bind(float* vertexBuffer, int _index[], int _vertexSize, int _indexSize);	//for shape also loads into shader

																					//void BindEntityData(Vertex* vertexBuffer, int* indexBuffer, int verN, int indN);	//interfaz para que pueda pasarle a bind el vertex* como glufloat
	void OriginDraw();
	void OriginBind();
	void OriginShaders();
	void OriginLoadTexture(Entity* ent);
	void HalfDraw();
	void DrawEntity(Entity* ent);
	
	~Renderer();
};
#endif

