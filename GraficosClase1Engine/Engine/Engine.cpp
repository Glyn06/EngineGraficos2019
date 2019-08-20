#include "Engine.h"
#include <iostream>
#include "GLFW/glfw3.h"
//linker error with glfw not being linked
//solution needed to link opengl32.lib
using namespace std;
void Engine::startGLFW()
{
	


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		cout << "boom";

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		cout << "boom";
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
