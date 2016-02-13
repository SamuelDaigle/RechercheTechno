/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "stdafx.h"
#include "Triangle.h"
#include "OpenGL.h"
#include "Composite.h"
#include "Planet.h"
#include "Skybox.h"
#include "BasicShader.h"
#include "AdvancedShader.h"
#include "SkyboxShader.h"
#include "InputHandler.h"
#include "Square.h"
#include "Light.h"
#include "Text.h"
#include "Sun.h"

#include "Dependencies/glm/common.hpp"

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

	OpenGL* ptrOpenGL;
	InputHandler* ptrInputHandler;
	Composite* rootObject;
	Planet* planet;
	IShader* basicShader;
	IShader* advancedShader;
	IShader* skyboxShader;
	Skybox* skybox;
	Light* light;
	IObject* sun;
};

