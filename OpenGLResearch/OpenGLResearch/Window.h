#include "stdafx.h"
#include "OpenGL.h"
#include "InputHandler.h"
#include "Scene.h"

#pragma once
class Window
{
public:
	void Initialize();
	void Start();
	void Destroy();

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

