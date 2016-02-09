#pragma once

#include "Model.h"
#include "IObject.h"

class Planet : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;

	void Destroy() override;

	void Render(IShader& _shader) override;

private:
	Model* model;
};

