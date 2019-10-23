
#include "Shape.h"

Shape::Shape()
{
	

	
	width = 16;
	height = 16;
	nrChannels = 1;
	int last = 0;
	string str = "../Textures/BlueLink.png";
	int len = str.length() + 1;
	char *texture = new char[len];
	strcpy_s(texture, len, str.c_str());
	printf("texture name = %s \n", texture);
	sprite = new Sprite(texture, width, height, nrChannels, last);

	delete[] texture;
}
unsigned char* Shape::GetSprite()
{

	return sprite->GetTexture();
}
int Shape::GetWidth()
{
	return width;
}
int Shape::GetHeight()
{
	return height;
}
Shape::~Shape() 
{
}