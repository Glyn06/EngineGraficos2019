#ifndef ZELDA_H
#define ZELDA_H
#include "Engine.h"

//#include "Shape.h"
/*	struct Vertex {
		float x, y;
		float r, g, b, a;
		float u, v;
	};*/

#include <iostream>
using namespace std;
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
	void Spin();
	//void Movement();
	void InputE();
	//en window y en renderer estoy usando glfw

	~Zelda();
};
#endif // !ZELDA_H
