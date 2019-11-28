#include "Window.h"
#include "GLFW/glfw3.h"	


Window::Window(int sWidth, int sHeight, const char* name)
{
	window = glfwCreateWindow(sWidth, sHeight, name, NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		cout << "Fallo creacion de la window";
	}
	printf("window created \n");
}
void Window::WindowOpen() 
{

}

void Window::WindowClose() {


}
/*
GLFWwindow* Window::GetWindow() {
	return window;
}*/

Window::~Window()
{
}
