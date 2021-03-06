/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "Camera.h"
#include "ShaderLoader.h"

#include <iostream>
#include <vector>

using namespace std;

#pragma once

class OpenGL
{
public:
	void Initialize();
	void Destroy();

	mat4& GetViewMatrix();
	mat4& GetProjMatrix();
	Camera* GetCamera();

	void BeginScene();
	void EndScene();

private:
	void setBuffer(int _objectID, int _bufferID, GLfloat* _bufferData);

	unsigned int* vertexArrayObjID;
	unsigned int* vertexBufferObjID[2];

	Camera* camera;
	mat4 projectionMatrix;
};