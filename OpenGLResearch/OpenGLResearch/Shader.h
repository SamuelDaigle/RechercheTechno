#pragma once

#include "stdafx.h"

class Shader : public IShader
{
public:
	Shader(unsigned int _program);
	~Shader();

	void SetWorldMatrix(mat4 _worldMatrix) override;
	void SetViewMatrix(mat4 _viewMatrix) override;
	void SetProjectionMatrix(mat4 _projMatrix) override;

private:
	GLfloat* MatrixToFloatArray(mat4 _matrix);


};

