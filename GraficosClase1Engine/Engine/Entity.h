#ifndef ENTITY_H
#define ENTITY_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include "stb_image.h"
#include "Renderer.h"
#include <iostream>
#include <string.h>
using namespace std;

class EXPORTER Entity
{
protected:
	Vertex _vertex[4];
	int _index[6];
	int _indexN, _vertexN;
	Vertex* _vertexPointer;
	int* _indexPointer;

	int width, height;
	int nrChannels, last;
	char* name;
	unsigned char* data;
public:
	Entity();
	Entity(string _name, int _width, int _height, int _nrChannels, int _last);
	void Draw(Renderer& rend);
	//unsigned char* GetSprite();
	//void LoadSpriteAtribs(string str, int _width, int _height, int channels, int last);
	Vertex* GetVertexPointer();
	int* GetIndexPointer();
	int GetWidth();
	int GetHeight();
	unsigned char* GetTexture();
	~Entity();

};



#endif // !ENTITY_H

