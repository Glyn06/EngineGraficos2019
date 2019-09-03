#include"glew.h"
#include"GLFW/glfw3.h"
#include "Engine.h"
using namespace std;
void Engine::startGLFW()
{
	/* Initialize the library */
	if (!glfwInit())
		cout << "Fallo al inicializar la libreria";

	Window* wind = new Window(640, 480, "faaa");

	GLFWwindow* window = wind->GetWindow();

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	Renderer* render = new Renderer();
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		render->Draw();

		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
