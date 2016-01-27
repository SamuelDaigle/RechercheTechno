#include "Composite.h"


void Composite::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;
}

void Composite::Destroy()
{
	for each (IObject* childObject in childObjects)
	{
		SAFE_DESTROY(childObject);
	}
}

void Composite::Render()
{
	for each (IObject* childObject in childObjects)
	{
		ptrOpenGL->SetShaderParameters(childObject->GetWorldMatrix());
		childObject->Render();
	}
}

void Composite::Translate(float _x, float _y, float _z)
{
	for each (IObject* childObject in childObjects)
	{
		childObject->Translate(_x, _y, _z);
	}
}

void Composite::Rotate(float _angleX, float _angleY, float _angleZ)
{
	for each (IObject* childObject in childObjects)
	{
		childObject->Rotate(_angleX, _angleY, _angleZ);
	}
}

void Composite::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
	for each (IObject* childObject in childObjects)
	{
		childObject->Scale(_scaleX, _scaleY, _scaleZ);
	}
}

void Composite::Add(IObject* _object)
{
	childObjects.push_back(_object);
}
