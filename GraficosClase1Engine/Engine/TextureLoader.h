#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#define STB_IMAGE_IMPLEMENTATION

#include "../stb_image.h"
/*
#include"glew.h"
#include "GLFW/glfw3.h"
*/
#include <iostream>
using namespace std;
class TextureLoader {
private:
	int width, height, nrChannels;
	char* name;
	unsigned char* data;
public:
	TextureLoader(char* n, int w, int h, int channels);
	void LoadTexture();
	void LoadTextureToShader();
	~TextureLoader();
};
#endif
