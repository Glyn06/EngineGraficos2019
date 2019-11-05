#ifndef ENTITY_H
#define ENTITY_H

#include "Sprite.h"
#include "Shape.h"


using namespace std;
class Entity
{
private:
	


	Sprite* sprite;
	Shape* shape;
	int width, height;
public:
	Entity(int num);
	unsigned char* GetSprite();
	void LoadSpriteAtribs(string str, int _width, int _height, int channels, int last);
	float* GetVertex();
	int* GetIndex();
	int GetWidth();
	int GetHeight();
	int GetVertexNum(int n);
	
	~Entity();
};



#endif // !ENTITY_H

