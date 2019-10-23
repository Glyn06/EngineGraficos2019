#ifndef ENGINE_H
#define ENGINE_H
#define EXPORTER _declspec(dllexport)
#include <iostream>

#include "Input.h"
#include "Window.h"
//#include "Renderer.h";

//class Renderer;
class EXPORTER Engine{
private:
	
public:
	Engine();
	void startGLFW();
};
#endif // !ENGINE_H