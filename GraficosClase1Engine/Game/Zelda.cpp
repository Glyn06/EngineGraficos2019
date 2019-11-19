#include "Zelda.h"
//renderer se incluye en: entity.h, engine.cpp (.h comentado), renderer.cpp
Zelda::Zelda()
{
	startGLFW();
}
void Zelda::Init()
{
	int width = 16;
	int height = 16;
	string str = "../Textures/BlueLink.png";
	int nrChannels = 1;
	int last = 0;

	Sprite* Link = new Sprite(str, width, height, nrChannels, last);
	
	
}
void Zelda::Update()
{
	
}
void Zelda::DeInit()
{

}
void Zelda::Spin()
{

}
void Zelda::Movement()
{

}
Zelda::~Zelda()
{

}