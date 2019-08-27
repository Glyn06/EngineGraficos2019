#ifndef RENDERER_H
#define RENDERER_H


float position[6]
{
	-0.5f, -0.5f,
	0.0f, -0.5f,
	0.5f, -0.5f,
};
static const GLfloat g_vertex_buffer_data[] = {
   -0.3f, -0.3f, 0.0f,
   0.3f, -0.3f, 0.0f,
   0.0f,  0.6f, 0.0f,
};

class Renderer
{
private:
	
public:
	Renderer();
	void Draw();
	~Renderer();
};
#endif

