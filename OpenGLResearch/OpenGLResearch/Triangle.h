/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "stdafx.h"
#include "VertexType.h"

#pragma once
class Triangle : public IObject
{
public:
	void Initialize(MeshLoader* _meshLoader) override;
	void Destroy() override;
	
	void Render(IShader& _shader) override;
private:
	void initializeBuffers();
	void shutdownBuffers();
};

