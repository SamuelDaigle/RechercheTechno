#include "stdafx.h"
#include "IObject.h"

#pragma once
class Triangle : public IObject
{
private:
	struct VertexType
	{
		float x, y, z;
		float r, g, b;
	};

public:
	void Initialize();
	void Destroy();

	void SetVertices(vec3 _position, float _size);
	void SetVertices(vec3 _position, float _width, float _height);
	void SetColors(Color _color);
	void SetColors(Color _color1, Color _color2, Color _color3);
	
	void Render();
	void Translate(float _x, float _y, float _z);
	void Rotate(float _angle);
	void Reshape(float _scale);

	vec3 FindCenter();

private:
	void initializeBuffers();
	void shutdownBuffers();
};

