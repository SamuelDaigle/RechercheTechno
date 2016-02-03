#pragma once

#include "stdafx.h"
#include "ShaderLoader.h"

class Shader : public IShader
{
public:
	Shader();
	~Shader();

	void SetWorldMatrix(mat4 _worldMatrix) override;
	void SetViewMatrix(mat4 _viewMatrix) override;
	void SetProjectionMatrix(mat4 _projMatrix) override;

private:
	GLfloat* MatrixToFloatArray(mat4 _matrix);
};

