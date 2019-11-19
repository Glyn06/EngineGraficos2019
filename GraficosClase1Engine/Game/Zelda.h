#ifndef ZELDA_H
#define ZELDA_H
#include "Engine.h"
#include "Sprite.h"
//#include "Shape.h"


#include <iostream>
using namespace std;
class Zelda : public Engine {
public:
	Zelda();
	void Init();
	void Update();
	void DeInit();
	void Spin();
	void Movement();
	//en window y en renderer estoy usando glfw

	~Zelda();
};
#endif // !ZELDA_H
