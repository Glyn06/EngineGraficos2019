#include "TextureLoader.h"

TextureLoader::TextureLoader(const std::string& n): width(0),height(0),nrChannels(0),_renderID(0)
{
	stbi_set_flip_vertically_on_load(1);
	data = stbi_load(n.c_str(), &width, &height, &nrChannels, 4); //El cuatro es por la cantidad de canales que queremos R G B y A

	glGenTextures(1, &_renderID);
	glBindTexture(GL_TEXTURE_2D, _renderID);

	//Estos cuatro parametros hay que especificarlos si o si porque sino nos sale una textura negra
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//Le pasamos la textura a OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); //Asignamos la cantidad de memoria que va a ocupar nuestra textura y le pasamos nuestra data
	Unbind();

	if (data)
		stbi_image_free(data);
}

TextureLoader::~TextureLoader()
{
	glDeleteTextures(1, &_renderID);
}

void TextureLoader::TextureBind(unsigned int slot) {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _renderID);
}

void TextureLoader::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}