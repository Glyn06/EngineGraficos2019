#include"Renderer.h"
#include"glew.h"
#include"GLFW/glfw3.h"
#include "Engine.h"
#include "Renderer.h"
using namespace std;
Renderer* render;
Input* inp;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
int rotate = 0;
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

	glfwSetKeyCallback(window, keyCallBack);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	render = new Renderer();
	inp = new Input();
	/* Loop until the user closes the window */
	
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		render->SpinTriangle(0.0f);
		render->Draw(window);
		
		
		
		/* Poll for and process events */
		
		glfwPollEvents();

	}

	glfwTerminate();
	
	delete inp, render;
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	float* inputs =	inp->Inputs(key, action);
	render->RotatationShape(inputs[0]);
	render->MovePositionShape(inputs[1], inputs[2]);
}
