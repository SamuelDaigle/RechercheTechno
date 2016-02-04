#include "stdafx.h"
#include "Triangle.h"
#include "OpenGL.h"
#include "Composite.h"
#include "Planet.h"
#include "Skybox.h"
#include "Shader.h"
#include "SkyboxShader.h"
#include "InputHandler.h"
#include "Cube.h"
#include "Light.h"
#include "Text.h"

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

	Text* text;
	OpenGL* ptrOpenGL;
	InputHandler* ptrInputHandler;
	Composite* rootObject;
	Planet* planet;
	IShader* basicShader;
	IShader* skyboxShader;
	Skybox* skybox;
	Light* light;
};

