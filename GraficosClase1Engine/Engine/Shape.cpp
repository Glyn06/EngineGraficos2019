
#include "Shape.h"
float SquareV[] = {	//vertex buffer
			 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,		// Vertex 1 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 0
			 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 1
			-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,	// Vertex 3 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 2
			-0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 3
};
int squareI[] = {	//index buffer
	0 , 1, 2,		// tirangulo derecho inferior
	2, 3, 0
};
float vertexT[] = {
			 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Vertex 1 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 0
			 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Vertex 2 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 1
			-0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Vertex 3 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 2
};

int triangleI[] = {
	0 , 1, 2,
};
Shape::Shape(int num)
{
	_num = num;
	switch (_num)
	{
	default:
		_vertex = SquareV;
		_index = squareI;
		_vertexN = 32;
		_indexN = 6;
		printf("we gonna draw a Square \n");
		break;
	case 3:
		_vertex = vertexT;
		_index = triangleI;
		_vertexN = 24;
		_indexN = 3;
		break;
	}
}
float* Shape::GetVertex()
{
	return _vertex;
}
int* Shape::GetIndex() 
{ 
	return _index; 
}
int Shape::GetNum()
{
	return _num;
}
int Shape::GetArraySize(int num)
{
	int rta = 0;
	switch (num)
	{
	case 0:
		rta = _vertexN*sizeof(float);
		break;
	
	case 1:
			rta = _indexN*sizeof(int);
			break;
	}
	return rta;
}
Shape::~Shape() 
{
}