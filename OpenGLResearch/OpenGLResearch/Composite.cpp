#include "Composite.h"


void Composite::Initialize(MeshLoader* _meshLoader)
{
	planet = new Planet();
	planet->Initialize(_meshLoader);
}

void Composite::SetSelfObject(IObject* _object)
{
	planet = _object;
}

void Composite::Destroy()
{
	SAFE_DESTROY(planet);
	for each (IObject* childObject in childObjects)
	{
		SAFE_DESTROY(childObject);
	}
}

void Composite::Update()
{
	if (planet != NULL)
	{
		planet->Update();
	}
	for each (IObject* childObject in childObjects)
	{
		childObject->Update();
	}
}

void Composite::SetColor(float _r, float _g, float _b)
{
	if (planet != NULL)
	{
		planet->SetColor(_r, _g, _b);
	}
}

void Composite::Render(IShader& _shader)
{
	if (planet != NULL)
	{
		_shader.SetWorldMatrix(planet->GetWorldMatrix());
		planet->Render(_shader);
	}
	for each (IObject* childObject in childObjects)
	{
		mat4 parentWorldMatrix;
		if (planet != NULL)
		{
			parentWorldMatrix = planet->GetWorldMatrix();
		}
		_shader.SetWorldMatrix(parentWorldMatrix * childObject->GetWorldMatrix());
		childObject->Render(_shader);
	}
}

void Composite::Translate(float _x, float _y, float _z)
{
	if (planet != NULL)
	{
		planet->Translate(_x, _y, _z);
	}
	for each (IObject* childObject in childObjects)
	{
		childObject->Translate(_x, _y, _z);
	}
}

void Composite::Rotate(float _angleX, float _angleY, float _angleZ)
{
	if (planet != NULL)
	{
		planet->Rotate(_angleX, _angleY, _angleZ);
	}
	for each (IObject* childObject in childObjects)
	{
		childObject->Rotate(_angleX, _angleY, _angleZ);
	}
}

void Composite::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
	if (planet != NULL)
	{
		planet->Scale(_scaleX, _scaleY, _scaleZ);
	}
}

void Composite::Add(IObject* _object)
{
	childObjects.push_back(_object);
}
