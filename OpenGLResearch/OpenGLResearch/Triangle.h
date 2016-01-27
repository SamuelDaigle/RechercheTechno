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
	void Initialize(OpenGL* _ptrOpenGL);
	void Destroy();

	void SetVertices(vec3 _position, float _size);
	void SetVertices(vec3 _position, float _width, float _height);
	void SetColors(Color _color);
	void SetColors(Color _color1, Color _color2, Color _color3);
	
	void Render();
	void Translate(float _x, float _y, float _z);
	void Rotate(float _angleX, float _angleY, float _angleZ);
	void Scale(float _scaleX, float _scaleY, float _scaleZ);
private:
	void initializeBuffers();
	void shutdownBuffers();
};

