#include "stdafx.h"
#include "Planet.h"

using namespace std;

#pragma once
class Composite : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;

	void Initialize(IObject* _object);

	void Destroy() override;

	void Update() override;

	void SetColor(float _r, float _g, float _b) override;

	void Render(IShader& _shader) override;

	void Translate(float _x, float _y, float _z) override;

	void Rotate(float _angleX, float _angleY, float _angleZ) override;

	void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

	void Add(IObject* _object);

private:
	vector<IObject*> childObjects;
	IObject * planet;
};

