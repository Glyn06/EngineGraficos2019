#include "Entity.h"
//float SquareV[] =


Entity::Entity()
{
	printf("Entity created! const default\n");
}
void Entity::LoadAtribs(string _path, int _width, int _height, int _nrChannels)
{
	printf("Loading Atribs_custom.. \n");
	//vertex 1
	_vertex[0].x = 0.5f;
	_vertex[0].y = 0.5f;		//x,y
	_vertex[0].r = 0.0f;
	_vertex[0].g = 1.0f;
	_vertex[0].b = 0.0f;
	_vertex[0].a = 1.0f;		//r,g,b,a
	_vertex[0].u = 1.0f;
	_vertex[0].v = 1.0f;		//u,v
	//vertex 2
	_vertex[1].x = 0.5f;
	_vertex[1].y = -0.5f;
	_vertex[1].r = 1.0f;
	_vertex[1].g = 1.0f;
	_vertex[1].b = 1.0f;
	_vertex[1].a = 1.0f;
	_vertex[1].u = 1.0f;
	_vertex[1].v = 0.0f;
	//vertex 3
	_vertex[2].x = -0.5f;
	_vertex[2].y = -0.5f;
	_vertex[2].r = 0.0f;
	_vertex[2].g = 0.0f;
	_vertex[2].b = 1.0f;
	_vertex[2].a = 1.0f;
	_vertex[2].u = 0.0f;
	_vertex[2].v = 0.0f;
	//vertex 4
	_vertex[3].x = -0.5f;
	_vertex[3].y = 0.5f;
	_vertex[3].r = 1.0f;
	_vertex[3].g = 0.0f;
	_vertex[3].b = 1.0f;
	_vertex[3].a = 0.5f;
	_vertex[3].u = 0.0f;
	_vertex[3].v = 1.0f;

	//Index Buffer
	_index[0] = 0;
	_index[1] = 1;
	_index[2] = 2;
	_index[3] = 2;
	_index[4] = 3;
	_index[5] = 0;

	_vertexPointer = _vertex;
	_indexPointer = _index;
	LoadFloatVertex(_vertex);
	//printf("first value of vertex: %f \n", _vertex[0].x);

	_last = 0;
	width = _width;
	height = _height;
	nrChannels = _nrChannels;
	
	int size = _path.length();
	name = new char[size];
	
	strcpy_s(name, sizeof(name)+size, _path.c_str()); //<--- tamanio de buffer es muy chico? 0x0ce4b108 "" en donde "" tiene basura!
	data = stbi_load(name, &width, &height, &nrChannels, STBI_rgb_alpha);
	if (data == nullptr)
	{
		printf("failed to load texture in load atribs \n");
	}
	else
	{
		printf("loaded atribs\n");
	}

}
Entity::Entity(string _path, int _width, int _height, int _nrChannels)
{
	printf("entity created? \n");
	//vertex 1
	_vertex[0].x = 0.5f;		
	_vertex[0].y = 0.5f;		//x,y
	_vertex[0].r = 0.0f;
	_vertex[0].g = 1.0f;
	_vertex[0].b = 0.0f;
	_vertex[0].a = 1.0f;		//r,g,b,a
	_vertex[0].u = 1.0f;
	_vertex[0].v = 1.0f;		//u,v
	//vertex 2
	_vertex[1].x = 0.5f;
	_vertex[1].y = -0.5f;
	_vertex[1].r = 1.0f;
	_vertex[1].g = 1.0f;
	_vertex[1].b = 1.0f;
	_vertex[1].a = 1.0f;
	_vertex[1].u = 1.0f;
	_vertex[1].v = 0.0f;
	//vertex 3
	_vertex[2].x = -0.5f;
	_vertex[2].y = -0.5f;
	_vertex[2].r = 0.0f;
	_vertex[2].g = 0.0f;
	_vertex[2].b = 1.0f;
	_vertex[2].a = 1.0f;
	_vertex[2].u = 0.0f;
	_vertex[2].v = 0.0f;
	//vertex 4
	_vertex[3].x = -0.5f;
	_vertex[3].y = 0.5f;
	_vertex[3].r = 1.0f;
	_vertex[3].g = 0.0f;
	_vertex[3].b = 1.0f;
	_vertex[3].a = 1.0f;
	_vertex[3].u = 0.0f;
	_vertex[3].v = 1.0f;

	//Index Buffer
	_index[0] = 0;
	_index[1] = 1;
	_index[2] = 2;
	_index[3] = 2;
	_index[4] = 3;
	_index[5] = 0;

	_vertexPointer = _vertex;
	

	_indexPointer = _index;
	//printf("first value of vertex: %f \n",_vertex[0].x);

	LoadFloatVertex(_vertex);

	width = _width;
	height = _height;
	nrChannels = _nrChannels;
	_last = 0;
	int size = _path.length();
	name = new char[size];
	strcpy_s(name, size, _path.c_str());
	data = stbi_load(name, &width, &height, &nrChannels, STBI_rgb_alpha);
	if (data == nullptr)
	{
		printf("failed to load texture in constructor \n");
	}
	else
	{
		printf("loaded entity constr\n");
	}
}
/*
void Entity::Draw(Renderer& rend)
{
	//rend.LoadTexture(this);
	//rend.Bind(_vertexPointer, _indexPointer, _vertexN, _indexN);
}*/
/*
void Entity::LoadSpriteAtribs(string str, int _width, int _height, int channels, int last)
{
	width = _width;
	height = _height;
	int len = str.length() + 1;
	char *texture = new char[len];
	strcpy_s(texture, len, str.c_str());
	printf("texture name = %s \n", texture);

	sprite = new Sprite(texture, _width, _height, channels, last);

	delete[] texture;
}
*/
void Entity::LoadFloatVertex(Vertex* vert)
{

	for (int i = 0; i < 4; i++)
	{
			_vertexF[i*8] = vert[i].x;
			_vertexF[i*8+1] = vert[i].y;
			_vertexF[i*8+2] = vert[i].r;
			_vertexF[i*8+3] = vert[i].g;
			_vertexF[i*8+4] = vert[i].b;
			_vertexF[i*8+5] = vert[i].a;
			_vertexF[i*8+6] = vert[i].u;
			_vertexF[i*8+7] = vert[i].v;
			//printf("vertex %i atribs   x: %f , y: %f \n",i,_vertexF[i*8],_vertexF[i*8+1]);
	}
	_vertexPointetrF = _vertexF;
}
Vertex* Entity::GetVertexPointer()
{
	//printf("pointer to first: %f", _vertexPointer);
	return _vertexPointer;
}
float* Entity::GetVertexPointerF()
{
	//printf("pointer to first Float: %f", *_vertexPointetrF);
	return _vertexPointetrF;
}
int* Entity::GetIndexPointer()
{
	return _indexPointer;
}

int Entity::GetWidth()
{
	return width;
}
int Entity::GetHeight()
{
	return height;
}
int Entity::GetVertexSize() { return 4; }
int Entity::GetIndexSize() { return 6; }
unsigned char* Entity::GetData()
{
	return data;
}
void Entity::SetMove(bool b) { Moved = b; }
bool Entity::GetMove() { return Moved; }
void Entity::SetX(float nx) { posX = nx; }
void Entity::SetY(float ny) { posY = ny; }
float Entity::GetX() { return posX; }
float Entity::GetY() { return posY; }
Entity::~Entity()
{
}