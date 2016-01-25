#include "Triangle.h"


Triangle::Triangle()
{
	Vector3 position(0, 0, 0);
	SetVertices(position, 0.5f);
	SetColors(RED);
}

void Triangle::SetVertices(Vector3 _position, float _size)
{
	SetVertices(_position, _size, _size);
}

void Triangle::SetVertices(Vector3 _position, float _width, float _height)
{
	vertices[0] = _position.x; vertices[1] = _position.y; vertices[2] = _position.z;
	vertices[3] = _position.x + _width; vertices[4] = _position.y; vertices[5] = _position.z;
	vertices[6] = _position.x + _width / 2; vertices[7] = _position.y + _height; vertices[8] = _position.z;
}

void Triangle::SetColors(Color _color)
{
	SetColors(_color, _color, _color);
}

void Triangle::SetColors(Color _color1, Color _color2, Color _color3)
{
	colours[0] = _color1.r; colours[1] = _color1.g; colours[2] = _color1.b;
	colours[3] = _color2.r; colours[4] = _color2.g; colours[5] = _color2.b;
	colours[6] = _color3.r; colours[7] = _color3.g; colours[8] = _color3.b;
}

void Triangle::Translate(float _x, float _y, float _z)
{
	vertices[0] += _x; vertices[1] += _y; vertices[2] = _z;
	vertices[3] += _x; vertices[4] += _y; vertices[5] = _z;
	vertices[6] += _x; vertices[7] += _y; vertices[8] = _z;
}

void Triangle::Rotate(float _angle)
{
	

	/*GLfloat resultMatrix[9];
	resultMatrix[0] = vertices[0] * cosf(_angle) - vertices[1] * sinf(_angle);
	resultMatrix[1] = vertices[0] * sinf(_angle) + vertices[1] * cosf(_angle);
	resultMatrix[2] = 0;
	resultMatrix[3] = vertices[3] * cosf(_angle) - vertices[4] * sinf(_angle);
	resultMatrix[4] = vertices[3] * sinf(_angle) + vertices[4] * cosf(_angle);
	resultMatrix[5] = 0;
	resultMatrix[6] = vertices[6] * cosf(_angle) - vertices[7] * sinf(_angle);
	resultMatrix[7] = vertices[6] * sinf(_angle) + vertices[7] * cosf(_angle);
	resultMatrix[8] = 0;

	for (int i = 0; i < 9; i++)
	{
		vertices[i] = resultMatrix[i];
	}*/
}

void Triangle::Reshape(float _scale)
{
	for (int i = 0; i < 9; i++)
	{
		vertices[i] *= _scale;
	}
}

Vector3 Triangle::FindCenter()
{
	float centerX = (vertices[0] + vertices[3] + vertices[6]) / 3;
	float centerY = (vertices[1] + vertices[4] + vertices[7]) / 3;
	float centerZ = (vertices[2] + vertices[5] + vertices[8]) / 3;

	Vector3 center(centerX, centerY, centerZ);
	return center;
}