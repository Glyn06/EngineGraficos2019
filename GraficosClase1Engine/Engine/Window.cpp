#include "Window.h"



Window::Window(int sWidth, int sHeight, const char* name)
{
	// aca estamos creando el window y si no se hace, tira un mensaje
	window = glfwCreateWindow(sWidth, sHeight, name, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		cout << "Fallo creacion de la window";
	}
}
void Window::WindowOpen() 
{

}

void Window::WindowClose() {


}

GLFWwindow* Window::GetWindow() {
	return window;
}

Window::~Window()
{
}
