#include "stdafx.h"

#pragma once
class Triangle : public IManipulated
{
public:
	Triangle();

	void SetVertices(vec3 _position, float _size);
	void SetVertices(vec3 _position, float _width, float _height);
	void SetColors(Color _color);
	void SetColors(Color _color1, Color _color2, Color _color3);
	
	//IManipulated methods
	void Translate(float _x, float _y, float _z);
	void Rotate(float _angle);
	void Reshape(float _scale);

	vec3 FindCenter();

	GLfloat vertices[9];
	GLfloat colours[9];
};

