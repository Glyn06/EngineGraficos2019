#ifndef ENTITY_H
#define ENTITY_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include "stb_image.h"
/*
#include "Sprite.h"
#include "Shape.h"
*/

using namespace std;
struct Vertex
{
	float x, y;
	float r, g, b, a;
	float u, v;
};

class EXPORTER Entity
{
protected:
	Vertex _vertex[4];
	int _index[6];
	int _indexN, _vertexN;
	Vertex* _vertexPointer;
	int* _indexPointer;

	int width, height;
public:

	Entity();
	//unsigned char* GetSprite();
	//void LoadSpriteAtribs(string str, int _width, int _height, int channels, int last);
	Vertex* GetVertexPointer();
	int* GetIndexPointer();
	int GetWidth();
	int GetHeight();
	~Entity();
};



#endif // !ENTITY_H

