#include "Sun.h"

void Sun::Initialize(MeshLoader* _meshLoader)
{
	model = new Model("../Content/planet/sun.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Sun::Destroy()
{
}

void Sun::Render(IShader& _shader)
{
	// Color
	glUniform4f(glGetUniformLocation(_shader.glProgram, "Color"), r, g, b, 1.0f);
	model->Draw(_shader);
}
