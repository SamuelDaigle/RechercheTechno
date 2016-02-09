#pragma once

#include "stdafx.h"
#include "VertexType.h"

class Cube : public IObject
{
public:
	Cube();
	~Cube();

	void Initialize(MeshLoader* _meshLoader) override;
	void Destroy() override;

	void Render(IShader& _shader) override;
	void Translate(float _x, float _y, float _z) override;
	void Rotate(float _angleX, float _angleY, float _angleZ) override;
	void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

private:
	void initializeBuffers();
	void shutdownBuffers();
};

