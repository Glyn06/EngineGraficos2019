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

	Link = new Sprite();
	Link->LoadAtribs(str, width, height, nrChannels);
	//render->Bind(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	BindR(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	LoadTextureR(Link);
}
void Zelda::Update()
{
	//render->Bind(Link->GetVertexPointer(),Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//render->LoadTexture();
	
	//render->LoadTexture(Link);
	
	
	//Link->Draw(*render);

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