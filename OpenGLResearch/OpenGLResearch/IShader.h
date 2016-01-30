#pragma  once

#include "Dependencies/glm/glm.hpp"

using namespace glm;

class IShader
{
public:
	virtual void SetWorldMatrix(mat4 _worldMatrix) = 0;
	virtual void SetViewMatrix(mat4 _viewMatrix) = 0;
	virtual void SetProjectionMatrix(mat4 _projMatrix) = 0;

	virtual void Use()
	{
		glUseProgram(glProgram);
	}
	
	unsigned int glProgram;

private:
	virtual GLfloat* MatrixToFloatArray(mat4 _matrix) = 0;
};