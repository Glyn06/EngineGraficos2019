#ifndef ENGINE_H
#define ENGINE_H
#ifndef EXPORTER
#define EXPORTER _declspec(dllexport)
#endif // !EXPORTER
#include <iostream>

#include "Input.h"
#include "Window.h"
#include "Renderer.h"
#include "Sprite.h"
//class Renderer;
class EXPORTER Engine{
protected:
	Window* window;
	int n = 0;
	Input* inp;

public:
	Engine(); 
	Window* GetWindow();
	virtual void Init()=0;
	void LoadTextureR(Entity* ente);
	void BindR(float* vertexBuffer, int _index[], int _vertexSize, int _indexSize);
	void BindR2(Vertex* vertexBuffer, int _index[], int _vertexSize, int _indexSize);
	void BindR3();
	void LoadTextureOrigin(Entity* ente);
	void HalfDrawR();
	void DrawEntityR(Entity* ent);
	void Loop();
	virtual void Update()=0;
	virtual void InputE() =0;
	virtual void DeInit()=0;
	void Movement(Entity* ent);
	
	void startGLFW();
	~Engine(); 
};
#endif // !ENGINE_H