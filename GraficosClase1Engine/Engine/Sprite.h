#ifndef SPRITE_H
#define SPRITE_H
#include "stb_image.h"
//#include <iostream>
using namespace std;

class Sprite {
private:
	int width, height, nrChannels, last;
	char* name;
	
	//va a tener animaciones
public:
	Sprite(char* n, int w, int h, int channels, int _last);
	void LoadTexture();
	void LoadTextureToShader();
	unsigned char* GetTexture();
	~Sprite();
};
#endif
