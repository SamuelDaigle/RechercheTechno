/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#pragma once

#include "Model.h"
#include "IObject.h"

class Sun : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;
	void SetShader(IShader* _shader);

	void Destroy() override;

	void Render(IShader& _shader) override;

private:
	Model* model;
	IShader* shader;
};

