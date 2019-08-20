#ifndef WINDOW_H
#define WINDOW_H
#include "Engine.h"
#include "GLFW/glfw3.h"
#include <iostream>
using namespace std;
class Window
{
private:
	GLFWwindow* window;

public:
	Window(int sWidth, int sHeight, const char* name);
	void WindowOpen();
	void WindowClose();
	GLFWwindow* GetWindow();
	~Window();
};
#endif
/*


*/