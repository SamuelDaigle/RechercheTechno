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

	void SetShaderParameters(mat4 _worldMatrix);

	void BeginScene();
	void EndScene();

private:
	void setBuffer(int _objectID, int _bufferID, GLfloat* _bufferData);
	GLfloat* MatrixToFloatArray(mat4 _matrix);

	unsigned int* vertexArrayObjID;
	unsigned int* vertexBufferObjID[2];

	GLuint glProgram;

	Camera* camera;
	mat4 projectionMatrix;
};