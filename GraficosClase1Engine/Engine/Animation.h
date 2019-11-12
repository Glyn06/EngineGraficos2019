#ifndef  ANIMATION_H
#define ANIMATION_H

#include <iostream>
using namespace std;
class Animation {
private:
	struct Frame
	{
		float uvcoords1[8];	//u y v de cada esquina
	};
	Frame* vectorFrames = new Frame[];			// atlas pointing to the last frame for use in collisions	4u y 4v
	int length;					// 4 frames for link
	float /*(casteado a integer desp)*/ currentFrame;


	//CUANDO TOCO UNA TECLA CAMBIO LAS COORDENADAS DE TEXTURAS
	//no frame anterior se encarga colision 
	//SPRITE TIENE UN SETANIMATION
	//
public:
	Animation();
	~Animation();
	void Update();	//solo cambia el frame
	void setAnimation(Animation a);
	void draw(/*Renderer &renderer*/);		//
	void AddFrame(float x, float y, float frameWidth, float frameHeight, float textureWidth,float textureHeight , float durationinsecs, int CantFrames);
	//para cortar la textura
	void GetFrameS();	//DEVUELVE TODO EL VECTOR DE FRAMES?
	void CurrentFrame();//devuelve current frame
};
#endif // ! ANIMATION_H

/*
COLISIONES
CHEQUEAR AUNQUESEA CON LOS BORDES DE LA PANTALLA
void AddFrame(uvx, uvy,  go here );	//6 vals



*/
/*en game.exe	//todo esto se lo pasamos a entity que se encarga
new sprite
init
set texture
set pos
new Animation
cual anim empieza
update:
	inputs here
	check collision
	update(timer);
	draw()
	
deinit:
	animaciones
	todo

*/