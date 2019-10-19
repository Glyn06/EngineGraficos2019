#ifndef ENGINE_H
#define ENGINE_H
#define EXPORTER _declspec(dllexport)
#include <iostream>
#include "Input.h"
#include "Window.h"
class EXPORTER Engine{
private:
public:
	void startGLFW();
};
#endif // !ENGINE_H