#include "stdafx.h"
#include "Triangle.h"
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

	void AttachDrawableObject(Triangle* _triangle);
	void SetShaderParameters(mat4 _transformationMatrix);
	void LockRenderer();

	void BeginScene();
	void EndScene();
	void Render();

private:
	void setBuffer(int _objectID, int _bufferID, GLfloat* _bufferData);
	GLfloat* MatrixToFloatArray(mat4 _matrix);

	unsigned int* vertexArrayObjID;
	unsigned int* vertexBufferObjID[2];

	GLuint glProgram;

	Camera* camera;
	mat4 worldMatrix;
	mat4 projectionMatrix;
};