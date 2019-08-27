#include "glew.h"
#include"GLFW/glfw3.h"
#include "Engine.h"
#include "Renderer.h"
using namespace std;
void Engine::startGLFW()
{
	if (glewInit() != GLEW_OK)
	{
		cout << "error!" << endl;
	}
	/* Initialize the library */
	if (!glfwInit())
		cout << "Fallo al inicializar la libreria";

	Window* wind = new Window(480, 640, "f");
	Renderer* Drawer= new Renderer();
	GLFWwindow* window = wind->GetWindow();

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		// DRAWING!
		Drawer->Draw();




		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
