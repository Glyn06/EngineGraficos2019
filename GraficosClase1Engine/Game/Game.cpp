#include <iostream>
#include "Engine.h"

using namespace std;
/*
	game includes Engine.dll from the other proyect
	when declaring functions add that (minus the void, use the return type) _declspec(dllexport) void
	on the solution properties, in the dependences it requires the game depend upon the dll

	now with glfw in our dll do it
*/


/*
	added the include stb_image in engine(base game) since in renderer it gets redifinined and barfs an error
	this is not the best but otherwise we cannot progress
*/
void main() 
{
	//prueba del dll que hice!
	Engine e;
	e.startGLFW();



	
	cin.get();

}
