#ifndef INPUT_H
#define INPUT_H
//#include "Engine.h"
#include<iostream>

using namespace std;

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

class Input {

public:
	float* Inputs(int key, int action);
};
#endif // !INPUT_H
