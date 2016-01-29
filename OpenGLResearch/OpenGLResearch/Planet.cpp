#include "Planet.h"

void Planet::Initialize(TextureLoader* _textureLoader)
{
	model = new Model("../Content/cube.obj", _textureLoader);
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

void Planet::Translate(float _x, float _y, float _z)
{
}

void Planet::Rotate(float _angleX, float _angleY, float _angleZ)
{
}

void Planet::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
}
