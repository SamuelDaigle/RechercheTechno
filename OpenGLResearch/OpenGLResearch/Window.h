#include "stdafx.h"
#include "Triangle.h"

#pragma once
class Window
{
public:
	void Initialize();
	void Update();
	void Display();
	void Reshape(int _screenWidth, int _screenHeight);

private:
	void manageInput();

	// two vertex array objects, one for each object drawn
	unsigned int vertexArrayObjID[2];
	// three vertex buffer objects in this example
	unsigned int vertexBufferObjID[3];
};

