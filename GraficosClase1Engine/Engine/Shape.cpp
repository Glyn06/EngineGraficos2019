
#include "Shape.h"

Shape::Shape()
{
	string str;
	int i = 3;
	switch(i)
	{
	case 1:
		width = 840;
		height = 680;
		str = "../Textures/linkA.png";
		break;

	case 2:
		width = 840;
			height = 680;
		str = "../Textures/test.png";


		break;
	case 3:
		width = 16;
		height = 16;
		str = "../Textures/BlueLink.png";

		break;
	}





	nrChannels = 1;
	int last = 0;
	//
	//string str = "../Textures/BlueLink.png";
	//string 
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