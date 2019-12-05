#ifndef INPUT_H
#define INPUT_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
//#include "Engine.h"
#include<iostream>
#include "Utilis.h"
using namespace std;

/*
#define GLFW_PRESS                  1
#define GLFW_REPEAT                 2
#define GLFW_KEY_A                  65
#define GLFW_KEY_D                  68
#define GLFW_KEY_S                  83
#define GLFW_KEY_W                  87
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265
*/


struct KeyState
{
	int Key;
	//int Press;
	//bool Hold;
	FuncPointer Action;
};
class EXPORTER Input {
private:

	
	FuncPointer* actions;
	//const void* window;
	
public:
	Input(const void* _window, int Length);
	//float* Inputs(int key, int action);
	void Inputs();
	void NewAction(int _key, FuncPointer _action, int locat);
	void CheckActions();

};
#endif // !INPUT_H
