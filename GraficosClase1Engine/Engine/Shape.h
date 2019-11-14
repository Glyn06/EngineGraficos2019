#ifndef SHAPE_H
#define SHAPE_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include "Entity.h"
#include<iostream>
using namespace std;
//class Sprite;
#define	TRIANGLE_SHAPE	3
#define	SQUARE_SHAPE	4



class EXPORTER Shape:Entity
{
private:
	//textura por defecto blanco para shape que luego se colorea



	
	
	//fooat con vertices, como tiene que leerlos (stride y ofset)
public:
	Shape();
	float* GetVertex();
	int* GetIndex();
	~Shape();
};
#endif 
