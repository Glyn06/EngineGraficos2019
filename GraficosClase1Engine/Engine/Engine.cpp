#include"Renderer.h"
#include"glew.h"
#include"GLFW/glfw3.h"
#include "Engine.h"
#include "Renderer.h"
using namespace std;
void Engine::startGLFW()
{
	if (glewInit() != GLEW_OK)
	{
		//cout << "error!" << endl;
	}
	/* Initialize the library */
	if (!glfwInit())
		cout << "Fallo al inicializar la libreria";

	Window* wind = new Window(640, 640, "Triangle  Engine");

	GLFWwindow* window = wind->GetWindow();

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	Renderer* render = new Renderer();
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		render->Draw(window);
		
		
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
