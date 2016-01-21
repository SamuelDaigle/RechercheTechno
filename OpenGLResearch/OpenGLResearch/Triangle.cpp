#include "Triangle.h"


Triangle::Triangle()
{
	Vector3 position(0,0,0);
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