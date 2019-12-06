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
	
	
	
	int width2 = 840;
	int height2 = 680;
	string str2 = "../Textures/test.png";
	

	int nrChannels = 1;
	
	Link = new Sprite();
	Link->LoadAtribs(str, width, height, nrChannels);
	Link->SetMove(true);
	Link->SetScale(0.5f);
	Link->SetRotation(0.0f);

	Obstacle = new Shape();
	Obstacle->LoadAtribs(str2, width2, height2, nrChannels);
	Obstacle->SetMove(false);
	Obstacle->SetX(0.7f);
	Obstacle->SetY(0.5f);
	Obstacle->SetScale(1.0f);
	
	//render->Bind(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//BindR(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//BindR2(Link->GetVertexPointer(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());

	BindR3();
	//LoadTextureR(Link);

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
	n++;
	printf("\r frame: %i and should draw ",n);
	
	
	if (n == 30)
	{
		n = 0;
		if(drawL)
		drawL= false;
		else drawL = true;
	}

	HalfDrawR();
	/*
	if (!drawL) {
		LoadTextureOrigin(Obstacle);
		DrawEntityR(Obstacle);
		printf("obstacle");
	}
	else {
		printf(" link");
		LoadTextureOrigin(Link);
		DrawEntityR(Link);
	}*/
	printf("BOTH");

	LoadTextureOrigin(Link);
	Movement(Link);
	DrawEntityR(Link);
	//unbind

	LoadTextureOrigin(Obstacle);
	Movement(Obstacle);
	DrawEntityR(Obstacle);
	
}
void Zelda::DeInit()
{
	
}
void Zelda::Spin()
{

}
/*
void Zelda::Movement()
{

}*/
void Zelda::InputE()
{

}
Zelda::~Zelda()
{

}