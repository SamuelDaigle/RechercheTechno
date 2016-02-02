#include "Composite.h"


void Composite::Initialize(TextureLoader* _textureLoader)
{
	planet = new Planet();
	planet->Initialize(_textureLoader);
}

void Composite::Destroy()
{
	SAFE_DESTROY(planet);
	for each (IObject* childObject in childObjects)
	{
		SAFE_DESTROY(childObject);
	}
}

void Composite::Render(IShader& _shader)
{
	_shader.SetWorldMatrix(planet->GetWorldMatrix());
	planet->Render(_shader);
	for each (IObject* childObject in childObjects)
	{
		_shader.SetWorldMatrix(childObject->GetWorldMatrix());
		childObject->Render(_shader);
	}
}

void Composite::Translate(float _x, float _y, float _z)
{
	planet->Translate(_x, _y, _z);
	for each (IObject* childObject in childObjects)
	{
		childObject->Translate(_x, _y, _z);
	}
}

void Composite::Rotate(float _angleX, float _angleY, float _angleZ)
{
	planet->Rotate(_angleX, _angleY, _angleZ);
	for each (IObject* childObject in childObjects)
	{
		childObject->Rotate(_angleX, _angleY, _angleZ);
	}
}

void Composite::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
	planet->Scale(_scaleX, _scaleY, _scaleZ);
	for each (IObject* childObject in childObjects)
	{
		childObject->Scale(_scaleX, _scaleY, _scaleZ);
	}
}

void Composite::Add(IObject* _object)
{
	childObjects.push_back(_object);
}
