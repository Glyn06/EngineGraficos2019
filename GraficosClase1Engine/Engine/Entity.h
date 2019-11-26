#ifndef ENTITY_H
#define ENTITY_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include "stb_image.h"
#include <iostream>
#include <string.h>
//#include "Renderer.h"

using namespace std;
struct Vertex {
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
	int nrChannels, last;
	char* name;
	unsigned char* data;
	
public:

	Entity();
	void LoadAtribs(string _path, int _width, int _height, int _nrChannels, int _last);
	Entity(string _name, int _width, int _height, int _nrChannels, int _last);
	//void Draw(Renderer& rend);
	//unsigned char* GetSprite();
	//void LoadSpriteAtribs(string str, int _width, int _height, int channels, int last);
	Vertex* GetVertexPointer();
	int* GetIndexPointer();
	int GetWidth();
	int GetHeight();
	int GetVertexSize();
	int GetIndexSize();
	unsigned char* GetData();
	~Entity();

};



#endif // !ENTITY_H

