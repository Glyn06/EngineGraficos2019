#include "Input.h"

float* Input::Inputs(int key, int action)
{
	float* posChange = new float[3];
	//rot, x, y
	float rot=0.0f,	x = 0.0f, y = 0.0f;

	if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		rot = 1.0f;
	}
	else
	if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		rot = -1.0f;
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

	posChange[0] = rot;
	posChange[1] = x;
	posChange[2] = y;
	return posChange;
}