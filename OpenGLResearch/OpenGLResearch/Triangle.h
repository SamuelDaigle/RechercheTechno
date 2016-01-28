#include "stdafx.h"
#include "IObject.h"
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
	void Translate(float _x, float _y, float _z) override;
	void Rotate(float _angleX, float _angleY, float _angleZ) override;
	void Scale(float _scaleX, float _scaleY, float _scaleZ) override;
private:
	void initializeBuffers();
	void shutdownBuffers();
};

