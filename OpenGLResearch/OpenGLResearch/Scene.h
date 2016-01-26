#include "stdafx.h"
#include "Triangle.h"
#include "OpenGL.h"

#pragma once
class Scene
{
public:
	void Initialize(OpenGL* _ptrOpenGL);
	void Destroy();

	void Frame();

private:
	void input();
	void update();
	void render();

	OpenGL* ptrOpenGL;
	vector<IObject*> renderedObjects;
};

