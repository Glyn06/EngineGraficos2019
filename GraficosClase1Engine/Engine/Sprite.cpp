#include "Sprite.h"
unsigned char* data;

//MAKE A FUNC THAT BINDS TEXTURE AND ANOTHER TO APPLY IT TO THE SHADER
//when we load these, we need to add extra atribs
/*


*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//asigns the parameters for the load of textures, currently using x and y

float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);	//this binds the colors from the vertexes, functions like the colors we use before

---
*Texture Filtering:

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//we also asign more parameters that we will use near and far i believe. thus we use mipmap


*Mipmap: we need to make the texture with mipmap (256*256) OR WE USE GENERATE MIPMAP(?)
happens between loading everything and unloading it (?)

Loading and creating textures:
this and the unload happen last
included, and basically loaded, dont know how it actually loads data without referencing it or binding it or anything (!!!)

Generating Textures:
here we bind the texture, happens first


glBindTexture(GL_TEXTURE_2D, texture);
glBindVertexArray(VAO);

*/
float textureCoords[] = {
	1.0f, 1.0f,  // top-right corner  
	1.0f, 0.0f,  // lower-right corner
	0.0f, 0.0f,   // lower-left corner
	0.0f, 1.0f		//top-left corner
};
/*
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
glEnableVertexAttribArray(2);

*/
Sprite::Sprite(char* _name, int _width, int _height, int _nrChannels, int _last)
{



	width = _width;
	height = _height;
	nrChannels = _nrChannels;
	name = _name;
	last = _last;
	data = stbi_load(name, &width, &height, &nrChannels, last);
	if (data == nullptr)
	{
		printf("failed to load texture \n");
	}
	else
	{
		printf("loaded \n");
	}

	//stbi_image_free(data);
}
void Sprite::LoadTexture()
{


}
void Sprite::LoadTextureToShader()
{

	
}
unsigned char* Sprite::GetTexture()
{
	return data;
}
Sprite::~Sprite()
{
	stbi_image_free(data);
}