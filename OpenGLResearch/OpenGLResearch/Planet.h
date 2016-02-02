#pragma once

#include "Model.h"
#include "IObject.h"

class Planet : public IObject
{
public:
	void Initialize(TextureLoader* _textureLoader) override;

	void Destroy() override;

	void Render(IShader& _shader) override;

private:
	Model* model;
};

