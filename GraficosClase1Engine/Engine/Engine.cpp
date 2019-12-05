

//#include "Utilis.h"

	#include "glew.h"
	#include "GLFW/glfw3.h"


#include "Engine.h"

using namespace std;
//class Render;
Renderer* render;

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
int rotate = 0;

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
	
	Loop();
}

void Engine::Loop()
{
	Init();
	//printf("          \n          ");
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose((GLFWwindow*)window->GetWindow()))
	{
		
		/* Render here */
		render->SpinTriangle(0.0f);
		//printf("frame: %i \n", n);
		n++;
		//printf("\r frame:%i         ", n);
		
		
		//render->Draw();
		//render->OriginDraw();
		Update();
		//render->movingRotatingAndScale();
		glfwSwapBuffers((GLFWwindow*)window->GetWindow());

		inp->CheckActions();
		/* Poll for and process events */
		
		
		
		

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
void Engine::BindR2(Vertex* vertexBuffer, int _index[], int _vertexSize, int _indexSize)
{
	render->Bind(vertexBuffer, _index, _vertexSize, _indexSize);
}
void Engine::BindR3()
{
	render->OriginBind();
}
void Engine::LoadTextureR(Entity* ente)
{
	render->LoadTexture(ente);
}
void Engine::LoadTextureOrigin(Entity* ente)
{
	render->OriginLoadTexture(ente);
}

/*void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	
	float* inputs =	inp->Inputs(key, action);
	render->RotatationShape(inputs[0]);
	render->MovePositionShape(inputs[1], inputs[2]);
}*/
void Engine::Movement(Entity* ent)
{
	if (ent->GetMove()) {
		render->movingRotatingAndScale();
		printf("drawing movable");
	}
	else{
		render->movingRotatingAndScaleUnMoving(ent->GetX(), ent->GetY());
		printf(" drawing OBST \n");
	}
}
void Engine::HalfDrawR()
{
	render->HalfDraw();
}
void Engine::DrawEntityR(Entity* ent)
{
	render->DrawEntity(ent);
}