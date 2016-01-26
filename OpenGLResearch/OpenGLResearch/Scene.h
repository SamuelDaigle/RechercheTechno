#include "stdafx.h"
#include "Triangle.h"

#pragma once
class Scene
{
public:
	void Initialize();
	void Destroy();

	void Frame();

private:
	void input();
	void update();
	void render();

	vector<IObject*> renderedObjects;
};

