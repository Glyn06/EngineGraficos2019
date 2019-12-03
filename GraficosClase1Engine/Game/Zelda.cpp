#include "Zelda.h"
//renderer se incluye en: entity.h, engine.cpp (.h comentado), renderer.cpp
Zelda::Zelda()
{
	startGLFW();
}
void Zelda::Init()
{
	/*
	int width = 16;
	int height = 16;
	string str = "../Textures/BlueLink.png";
	*/
	
	
	int width = 2;
	int height = 2;
	string str = "../Textures/Default.png";
	int nrChannels = 1;

	Link = new Sprite();
	Link->LoadAtribs(str, width, height, nrChannels);
	//render->Bind(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	

	//BindR(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//BindR2(Link->GetVertexPointer(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());

	BindR3();
	LoadTextureR(Link);
	
}
void Zelda::Update()
{
	//we **Should** use animation to change the texture but its unimplemented as we cannot load the damn texture yet
	//the parameters are loaded correctly,its accessing the corect functions, it translates scales etc yet it doesnt work.
	//IM NOT SURE THE ATRIBS ARE LOADED CORRECTLY
	//NEITHER TEXTURE NOR PURE COLORS WORK, SO NONE OF THE BLEND FUNC ARE TO FAULT (yet), COULD BE A RGBA/RGB ERROR AS WE CHANGED THEM A BIT (?)

	//ALTERNATIVELY, GLEW AND GLFW ARE ACTING UP AGAIN BECAUSE IT WAS MADE BY MORONS WHOSE MOTHERS SMELL OF ELDERBERRIES




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