#include "Planet.h"

void Planet::Initialize(TextureLoader* _textureLoader)
{
	model = new Model("../Content/planet/planet.obj", _textureLoader);
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}

void Planet::Destroy()
{
}

void Planet::Render(IShader& _shader)
{
	model->Draw(_shader);
}
