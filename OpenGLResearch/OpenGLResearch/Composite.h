#include "stdafx.h"

using namespace std;

#pragma once
class Composite : public IObject
{
public:
	virtual void Initialize(OpenGL* _ptrOpenGL) override;

	virtual void Destroy() override;

	virtual void Render() override;

	virtual void Translate(float _x, float _y, float _z) override;

	virtual void Rotate(float _angleX, float _angleY, float _angleZ) override;

	virtual void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

	void Add(IObject* _object);

private:
	vector<IObject*> childObjects;
};
