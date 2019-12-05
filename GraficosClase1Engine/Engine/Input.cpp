#include "Input.h"
#include "glew.h"
#include "GLFW/glfw3.h"

int keyLength;
KeyState* keys;
Input::Input(const void* _window, int Lenght)
{
	keyLength = Lenght;
	keys = new KeyState[keyLength];
	//window = _window;
	
}


void Input::Inputs()
{
	glfwPollEvents();
}
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	PlayAction(key, action);
}
void Input::NewAction(int _key, FuncPointer _action, int locat)
{
	
	keys[locat].Key = _key;
	keys[locat].Action = _action;
}

int GetLength()
{
	return keyLength; 
}


void Input::CheckActions()
{ 
	glfwPollEvents(); 
}

void PlayAction(int key, int action)
{
	for (int i = 0; i < GetLength(); i++)
	{
		if (keys[i].Key == key && (action == GLFW_REPEAT || action == GLFW_PRESS))
		{
			keys[i].Action();
		}
	}

}
/*
FuncPointer* Input::GetActions()
{
	
	for (int i = 0; i < keyLength; i++)
	{
		if(keys[i].Key == )
	}
	return activeActions;
}*/

