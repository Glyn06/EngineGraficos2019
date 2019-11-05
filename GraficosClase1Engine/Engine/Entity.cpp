#include "Entity.h"


Entity::Entity(int num)
{

	shape = new Shape(num);




}

unsigned char* Entity::GetSprite() {
	return sprite->GetTexture();
}
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

float* Entity::GetVertex()
{
	return shape->GetVertex();
}
int* Entity::GetIndex()
{
	return shape->GetIndex();
}

int Entity::GetWidth()
{
	return width;
}
int Entity::GetHeight()
{
	return height;
}
int Entity::GetVertexNum(int num)
{
	return shape->GetArraySize(num);
}

Entity::~Entity()
{
}