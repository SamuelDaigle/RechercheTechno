#include "Sun.h"

void Sun::Initialize(MeshLoader* _meshLoader)
{
	model = new Model("../Content/planet/sun.obj", _meshLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Sun::SetShader(IShader* _shader)
{
	shader = _shader;
}

void Sun::Destroy()
{
}

void Sun::Render(IShader& _shader)
{
	if (shader == NULL)
	{
		shader = &_shader;
	}
	model->Draw(*shader);
}
