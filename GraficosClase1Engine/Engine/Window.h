#ifndef WINDOW_H
#define WINDOW_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
//#include "glew.h"
//#include "GLFW/glfw3.h"	

#include <iostream>
using namespace std;
class EXPORTER Window
{
private:
	//GLFWwindow* window;
	void* window;
public:
	Window(int sWidth, int sHeight, const char* name);
	void WindowOpen();
	void WindowClose();
	//GLFWwindow* GetWindow();
	const void* GetWindow() { return (const void*)window; }
	~Window();
};
#endif
/*


*/