#include"Renderer.h"
#include"glew.h"
#include"GLFW/glfw3.h"
#include "Engine.h"
#include "Renderer.h"
using namespace std;
Renderer* render;

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
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	
	float x = 0.0f;
	float y = 0.0f;
	if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{

		render->RotatationShape(1.0f);
	}else
	if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{

		render->RotatationShape(-1.0f);
	}

	if (key == GLFW_KEY_D && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		x -= 0.01f;
	}
	if (key == GLFW_KEY_A && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		x += 0.01f;
	}
	if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		y -= 0.01f;
	}
	if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		y += 0.01f;
	}

	render->MovePositionShape(x, y);
	
}
