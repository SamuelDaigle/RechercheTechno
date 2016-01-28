#pragma once

#include "Model.h"
#include "IObject.h"

class Planet : public IObject
{
public:
	void Initialize(TextureLoader* _textureLoader) override;

	void Destroy() override;

	void Render(IShader& _shader) override;

	void Translate(float _x, float _y, float _z) override;

	void Rotate(float _angleX, float _angleY, float _angleZ) override;

	void Scale(float _scaleX, float _scaleY, float _scaleZ) override;

private:
	Model* model;
};

