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
	
	//inp->NewAction(GLFW_KEY_W, void(*MoveUp)());

	Obstacle = new Shape();
	Obstacle->LoadAtribs(str2, width2, height2, nrChannels);
	Obstacle->SetMove(false);
	Obstacle->SetX(0.7f);
	Obstacle->SetY(0.5f);

	//render->Bind(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//BindR(Link->GetVertexPointerF(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());
	//BindR2(Link->GetVertexPointer(), Link->GetIndexPointer(), Link->GetVertexSize(), Link->GetIndexSize());

	BindR3();
	//LoadTextureR(Link);
	inp = new Input(window, 6);
	//inp->NewAction(GLFW_KEY_W, &MoveUp, 0);
	//inp->NewAction(GLFW_KEY_S, &MoveDown, 1);
	//inp->NewAction(GLFW_KEY_A, &MoveLeft, 2);
	//inp->NewAction(GLFW_KEY_D, &MoveRight, 3);
	//inp->NewAction(GLFW_KEY_LEFT, &SpinL, 4);
	//inp->NewAction(GLFW_KEY_RIGHT, &SpinR, 5);
	
}
void Zelda::Update()
{
	
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
	

	LoadTextureOrigin(Obstacle);
	Movement(Obstacle);
	DrawEntityR(Obstacle);
	
}
void Zelda::DeInit()
{
	
}
void Zelda::SpinL()
{
	Link->SetRotation(Link->GetRotation()+1.0f);
}
void Zelda::SpinR()
{
	Link->SetRotation(Link->GetRotation()-1.0f);
}
void Zelda::LinkMovement()
{
	Movement(Link);
}
void Zelda::MoveUp()
{
	Link->SetY(Link->GetY() + 1.0f);
}
void Zelda::MoveDown()
{
	Link->SetY(Link->GetY() - 1.0f);
}
void Zelda::MoveLeft()
{
	Link->SetX(Link->GetX()+ 1.0f);
}
void Zelda::MoveRight()
{
	Link->SetX(Link->GetX() - 1.0f);
}
void Zelda::InputE()
{
	
}
Zelda::~Zelda()
{

}