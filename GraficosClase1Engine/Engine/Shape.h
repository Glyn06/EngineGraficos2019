#ifndef SHAPE_H
#define SHAPE_H


#include<iostream>
using namespace std;
//class Sprite;
#define	TRIANGLE_SHAPE	3
#define	SQUARE_SHAPE		4



class Shape
{
private:
	



	int* _index;
	float* _vertex;
	int _indexN, _vertexN;
	int _num;
	//fooat con vertices, como tiene que leerlos (stride y ofset)
public:
	Shape(int num);
	float* GetVertex();
	int* GetIndex();
	int GetNum();
	int GetArraySize(int num);
	~Shape();
};
#endif 
