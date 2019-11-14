#include "Entity.h"
//float SquareV[] =


Entity::Entity()
{
	//vertex 1
	_vertex[0].x = 0.5f;		
	_vertex[0].y = 0.5f;		//x,y
	_vertex[0].r = 0.0f;
	_vertex[0].g = 1.0f;
	_vertex[0].b = 0.0f;
	_vertex[0].a = 1.0f;		//r,g,b,a
	_vertex[0].u = 1.0f;
	_vertex[0].v = 1.0f;		//u,v
	//vertex 2
	_vertex[1].x = 0.5f;
	_vertex[1].y = -0.5f;
	_vertex[1].r = 1.0f;
	_vertex[1].g = 1.0f;
	_vertex[1].b = 1.0f;
	_vertex[1].a = 1.0f;
	_vertex[1].u = 1.0f;
	_vertex[1].v = 0.0f;
	//vertex 3
	_vertex[2].x = -0.5f;
	_vertex[2].y = -0.5f;
	_vertex[2].r = 0.0f;
	_vertex[2].g = 0.0f;
	_vertex[2].b = 1.0f;
	_vertex[2].a = 1.0f;
	_vertex[2].u = 0.0f;
	_vertex[2].v = 0.0f;
	//vertex 4
	_vertex[2].x = -0.5f;
	_vertex[2].y = 0.5f;
	_vertex[2].r = 1.0f;
	_vertex[2].g = 0.0f;
	_vertex[2].b = 1.0f;
	_vertex[2].a = 1.0f;
	_vertex[2].u = 0.0f;
	_vertex[2].v = 1.0f;

	//Index Buffer
	_index[0] = 0;
	_index[1] = 1;
	_index[2] = 2;
	_index[3] = 2;
	_index[4] = 3;
	_index[5] = 0;

	_vertexPointer = _vertex;
	_indexPointer = _index;
}

/*
void Entity::LoadSpriteAtribs(string str, int _width, int _height, int channels, int last)
{
	width = _width;
	height = _height;
	int len = str.length() + 1;
	char *texture = new char[len];
	strcpy_s(texture, len, str.c_str());
	printf("texture name = %s \n", texture);

	sprite = new Sprite(texture, _width, _height, channels, last);

	delete[] texture;
}
*/
Vertex* Entity::GetVertexPointer()
{
	return _vertexPointer;
}
int* Entity::GetIndexPointer()
{
	return _indexPointer;
}

int Entity::GetWidth()
{
	return width;
}
int Entity::GetHeight()
{
	return height;
}
Entity::~Entity()
{
}