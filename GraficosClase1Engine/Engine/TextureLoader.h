#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include <iostream>
using namespace std;
class TextureLoader {
private:
	int width, height, nrChannels;
	char* name;
	unsigned char* data;
public:
	TextureLoader(char* n, int w, int h, int channels);
	char* GetTexture();
	~TextureLoader();
};
#endif
