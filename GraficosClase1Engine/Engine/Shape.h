#ifndef SHAPE_H
#define SHAPE_H

#include "Sprite.h"
#include<iostream>
using namespace std;
//class Sprite;
class Shape
{
private:
	Sprite* sprite;
	int algo;
	//fooat con vertices, como tiene que leerlos (stride y ofset)
public:
	Shape(int _algo);
	~Shape();
};
#endif 
