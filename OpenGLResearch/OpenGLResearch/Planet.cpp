#include "Planet.h"

void Planet::Initialize(TextureLoader* _textureLoader)
{
	model = new Model("../Content//house/house.obj", _textureLoader);
}

void Planet::Destroy()
{
}

void Planet::Render()
{
	model->Draw();
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
