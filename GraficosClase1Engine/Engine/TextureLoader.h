#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include"glew.h"
#include "GLFW/glfw3.h"
#include "../stb_image.h"

#include <iostream>
using namespace std;
class TextureLoader {
private:
	int width, height, nrChannels;
	const char* name;
	unsigned char* data;
	GLuint _renderID;
public:
	TextureLoader(const std::string &n);
	~TextureLoader();
	void TextureBind(unsigned int slot = 0);
	void Unbind();
};
#endif
