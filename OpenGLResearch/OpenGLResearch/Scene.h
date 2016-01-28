#include "stdafx.h"
#include "Triangle.h"
#include "OpenGL.h"
#include "Composite.h"
#include "Planet.h"
#include "Shader.h"
#include "InputHandler.h"

#pragma once
class Scene
{
public:
	void Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInput);
	void Destroy();

	void Frame();

private:
	void input();
	void update();
	void render();

	POINT * cursorPosition;
	POINT * lastCursorPosition;

	OpenGL* ptrOpenGL;
	InputHandler* ptrInputHandler;
	Composite* rootObject;
	IShader* basicShader;
};

