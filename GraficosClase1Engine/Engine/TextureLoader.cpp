#include "TextureLoader.h"

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
*/
float texCoords[] = {
	1.0f, 1.0f,  // top-right corner  
	1.0f, 0.0f,  // lower-right corner
	0.0f, 0.0f,   // lower-left corner
	0.0f, 1.0f		//top-left corner
};

TextureLoader::TextureLoader(char* n, int w, int h, int channels)
{
	width = w;
	height = h;
	nrChannels = channels;
	name = n;

	data = stbi_load(name, &width, &height, &nrChannels, 0);
}
char* TextureLoader::GetTexture() 
{

	return false;
}
TextureLoader::~TextureLoader()
{

}