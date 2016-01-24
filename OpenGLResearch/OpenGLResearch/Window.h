#include "stdafx.h"
#include "Triangle.h"
#include "Renderer.h"

#pragma once
class Window
{
public:
	void Initialize();
	void Start();

	void Update();
	void Display();
	void Reshape(int _screenWidth, int _screenHeight);

private:
	void manageInput();

	Renderer* renderer;
};

