#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
using namespace std;

/*
static const GLfloat g_vertex_buffer_data[] = {
   -0.3f, -0.3f, 0.0f,
   0.3f, -0.3f, 0.0f,
   0.0f,  0.6f, 0.0f,
};
*/


class Renderer
{
private:
	unsigned int _buffer;
public:
	Renderer();
	void Draw();
	~Renderer();
};
#endif

