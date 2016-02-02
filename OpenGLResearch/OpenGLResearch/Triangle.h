#include "stdafx.h"
#include "VertexType.h"

#pragma once
class Triangle : public IObject
{
public:
	void Initialize(TextureLoader* _textureLoader) override;
	void Destroy() override;

	void SetVertices(vec3 _position, float _size);
	void SetVertices(vec3 _position, float _width, float _height);
	void SetColors(Color _color);
	void SetColors(Color _color1, Color _color2, Color _color3);
	
	void Render(IShader& _shader) override;
private:
	void initializeBuffers();
	void shutdownBuffers();
};

