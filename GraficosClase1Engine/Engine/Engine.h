#ifndef ENGINE_H
#define ENGINE_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include <iostream>

#include "Input.h"
#include "Window.h"

//class Renderer;
class EXPORTER Engine{
private:
	
public:
	Engine(); 
	virtual void Init()=0;
	void Loop(GLFWwindow* window);
	virtual void Update()=0;
	virtual void DeInit()=0;
	void startGLFW();
	~Engine(); 
};
#endif // !ENGINE_H