#include <iostream>
#include "Zelda.h"
//#include "Engine.h"

using namespace std;
/*
	game includes Engine.dll from the other proyect
	when declaring functions add that (minus the void, use the return type) _declspec(dllexport) void
	on the solution properties, in the dependences it requires the game depend upon the dll

	now with glfw in our dll do it
*/


/*
we need to make virtual methods start, update and draw that call the respective funcs of renderer and input(?)
textureloader is being done in the master branch
also the entity, shape and sprite classes

each entity should have an start, update and draw override and a shape thats going to draw,
shape will give entity the vertexes and its indexes, thats the only change between our current 2 shapes
sprite has the WHOLE texture and its indexes and it gets loaded into entity
entity should see if it has a texture, otherwise it draws with colors

IMPORTANT: moving rotating and scale should be after calculating everything in the draw but before it draws
so that when we group everything into the updates we dont have to do weird shit

in theory
base game will contain a vector with all the things thats going to update, including the entities
this should be done with a vector of class pointers of virtual_class_type and iterate each start, update and draw




issues/ questions
in order to move things into entity, we need virtual working
if we touch something with input how does entity know how to move, via renderer? seems sketchy
(we could pass it whith some kind of message to all things in the vector and each acts acordingly?)
(how the f* will it work when we pass everything to game?)
*/
void main() 
{
	//prueba del dll que hice!
	Zelda* z = new Zelda();
	//z->startGLFW();



	
	cin.get();

}
