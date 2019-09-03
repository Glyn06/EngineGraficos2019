#include <iostream>
#include "Engine.h"
using namespace std;
/*
	game includes Engine.dll from the other proyect
	when declaring functions add that (minus the void, use the return type) _declspec(dllexport) void
	on the solution properties, in the dependences it requires the game depend upon the dll

	now with glfw in our dll do it
*/
void main() 
{
	//prueba del dll que hice!
	Engine e;
	e.startGLFW();



	
	cin.get();

}
