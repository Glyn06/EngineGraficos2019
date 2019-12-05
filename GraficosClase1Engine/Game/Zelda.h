#ifndef ZELDA_H
#define ZELDA_H
#include "Engine.h"

//#include "Shape.h"
/*	struct Vertex {
		float x, y;
		float r, g, b, a;
		float u, v;
	};*/
//#include "Input.h"
#include <iostream>
using namespace std;
#define GLFW_PRESS                  1
#define GLFW_REPEAT                 2
#define GLFW_KEY_A                  65
#define GLFW_KEY_D                  68
#define GLFW_KEY_S                  83
#define GLFW_KEY_W                  87
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265
class Zelda : public Engine {
private:
	Sprite* Link;
	Shape* Obstacle;
	bool drawL = false;
	
	int Obstx, Obsty, Zeldx, Zeldy;
public:
	Zelda();
	void Init();
	void Update();
	void DeInit();
	void SpinL();
	void SpinR();
	void LinkMovement();
	void InputE();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	
	//en window y en renderer estoy usando glfw

	~Zelda();
};
#endif // !ZELDA_H
