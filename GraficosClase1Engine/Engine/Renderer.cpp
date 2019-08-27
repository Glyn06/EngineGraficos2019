#include "Renderer.h"

#include "glew.h"
#include"GLFW/glfw3.h"
float position[6]
{
	-0.5f, -0.5f,
	0.0f, -0.5f,
	0.5f, -0.5f,
};
Renderer::Renderer()
{

	
	glGenBuffers(1, &_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, _buffer);	//solo se crea y binde el buffer hasta aca
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), position, GL_STATIC_DRAW);			// le especifico el tamaño de lo que va a recibir
	//aca iria el index buffer
	//falta indicarle como interpreta los datos, orden, tipos de los atrib, tamano de cada atrib, hasta donde llega

}

void Renderer::Draw() 
{
	//gl clear

	glDrawArrays(GL_TRIANGLES, 0, 3);	//primitiva,de donde empieza, cuantos lee; usamos glelements cuando usemos indexes
	


	//glfw swapbuffers
}

Renderer::~Renderer()
{
	glfwTerminate();
}
