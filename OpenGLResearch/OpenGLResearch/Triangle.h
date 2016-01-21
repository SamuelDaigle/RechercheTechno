#include "stdafx.h"

#pragma once
class Triangle
{
public:
	Triangle();

	void SetVertices(Vector3 _position, float _size);
	void SetVertices(Vector3 _position, float _width, float _height);
	void SetColors(Color _color);
	void SetColors(Color _color1, Color _color2, Color _color3);

	GLfloat vertices[9];
	GLfloat colours[9];
};

