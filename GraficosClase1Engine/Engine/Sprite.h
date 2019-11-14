#ifndef SPRITE_H
#define SPRITE_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER

#include "Entity.h"
#include <iostream>
using namespace std;

class EXPORTER Sprite:Entity {
private:


	int nrChannels, last;
	char* name;
	unsigned char* data;
	//va a tener animaciones
public:
	Sprite(string n, int w, int h, int channels, int _last);
	unsigned char* GetTexture();
	~Sprite();
};
#endif
