#ifndef SPRITE_H
#define SPRITE_H
#include "stb_image.h"
//#include <iostream>
using namespace std;
class Sprite {
private:
	int width, height, nrChannels, last;
	char* name;
	unsigned char* data;

public:
	Sprite(char* n, int w, int h, int channels, int _last);
	void LoadTexture();
	void LoadTextureToShader();
	~Sprite();
};
#endif
