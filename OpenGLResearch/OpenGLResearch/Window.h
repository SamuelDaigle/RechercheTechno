#include "stdafx.h"
#include "OpenGL.h"
#include "InputHandler.h"
#include "Scene.h"

#pragma once
class Window
{
public:
	void Initialize();
	void Destroy();

	void Frame();
	void OnKeyPress(unsigned char _key, int _x, int _y);
	void OnKeyRelease(unsigned char _key, int _x, int _y);
	void Update();

private:
	void initializeWindow();
	void manageInput();
	bool hasExited();

	OpenGL* openGL;
	InputHandler* inputhandler;
	Scene* scene;

	int screenWidth;
	int screenHeight;
};

