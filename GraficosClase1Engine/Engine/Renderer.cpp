#include "Renderer.h"
#include"GLFW/glfw3.h"
//#include"glew..."
#include <iostream>
using namespace std;


Renderer::Renderer()
{

	unsinged int buffer;
	glGenBuffers(1, buffer);
	glbindbuffer(GL_ARRAY_BUFFER, buffer);	//solo se crea y binde el buffer hasta aca
	glbuffer(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);			// le especifico el tamaño de lo que va a recibir
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
	
}
