

//#include "Utilis.h"

	#include "glew.h"
	#include "GLFW/glfw3.h"


#include "Engine.h"

using namespace std;
//class Render;
Renderer* render;
Input* inp;
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
int rotate = 0;
int n = 0;
Engine::Engine()
{
	//render = new Renderer();
}
Window* Engine::GetWindow() { return window; }
void Engine::startGLFW()
{
	if (!glfwInit())
		printf("Fallo al inicializar la libreria");

	window = new Window(640, 640, "Triangle  Engine");
	//(GLFWwindow*)
//	GLFWwindow* Glwindow = (GLFWwindow*)window->GetWindow();

	glfwSetKeyCallback((GLFWwindow*)window->GetWindow(), keyCallBack);

	/* Make the window's context current */
	glfwMakeContextCurrent((GLFWwindow*)window->GetWindow());
	if (!glfwGetCurrentContext())printf("context is the window \n");

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		cout << "error!" << endl;	//<---
	}
	/* Initialize the library */
	
	render = new Renderer();
	inp = new Input();
	Loop();
}

void Engine::Loop()
{
	Init();
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose((GLFWwindow*)window->GetWindow()))
	{
		
		/* Render here */
		render->SpinTriangle(0.0f);
		//printf("frame: %i \n", n);
		n++;
		
		Update();
		
		render->Draw();
		
		glfwSwapBuffers((GLFWwindow*)window->GetWindow());


		/* Poll for and process events */
		glfwPollEvents();
		

	}

	glfwTerminate();
}
Engine::~Engine()
{
	delete inp, render;
}
void Engine::BindR(float* vertexBuffer, int _index[], int _vertexSize, int _indexSize)
{
	render->Bind(vertexBuffer, _index, _vertexSize, _indexSize);
}
void Engine::LoadTextureR(Entity* ente)
{
	render->LoadTexture(ente);
}
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {

	printf(" moving frame:%i \n",n);
	float* inputs =	inp->Inputs(key, action);
	render->RotatationShape(inputs[0]);
	render->MovePositionShape(inputs[1], inputs[2]);

}
