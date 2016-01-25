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
	GLfloat resultMatrix[9];
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
	}
}

void Triangle::Reshape(float _scale)
{
	for (int i = 0; i < 9; i++)
	{
		vertices[i] *= _scale;
	}
}

void Triangle::FindCenter()
{
	//Trouver le point milieu entre chaque point       x2 + x1 / 2 , y2 + y1 / 2


	float m[9];

	m[0] = (vertices[0] + vertices[3]) / 2;
	m[1] = (vertices[1] + vertices[4]) / 2;		//Point 1
	m[2] = (vertices[2] + vertices[5]) / 2;

	m[3] = (vertices[3] + vertices[6]) / 2;
	m[4] = (vertices[4] + vertices[7]) / 2;		//Point 2
	m[5] = (vertices[5] + vertices[8]) / 2;

	m[6] = (vertices[6] + vertices[0]) / 2;
	m[7] = (vertices[7] + vertices[1]) / 2;		//Point 3
	m[8] = (vertices[8] + vertices[2]) / 2;

	//Trouver la pente de chaque fonction linéaire       y2 - y1
													   //x2 - x1

	float p[3];
	p[0] = m[4] - vertices[1] / m[3] - vertices[0];	// Pente du point 1 au 2
	p[1] = m[7] - vertices[4] / m[6] - vertices[3];	// Pente du point 2 au 3
	p[2] = 0; //m[1] - vertices[7] / m[0] - vertices[6];	// Pente du point 3 au 1

	// Trouver l'origine de chaque équation		y = ax + b  ->   b = y - ax

	float b[3];
	b[0] = m[1] - (p[0] * m[0]);
	b[1] = m[4] - (p[1] * m[3]);
	b[2] = m[7] - (p[2] * m[6]);

	// Établissement du système d'équation
	float seq[3][3];
	seq[0][0] = p[0];
	seq[0][1] = p[1];
	seq[0][2] = p[2];

	seq[1][0] = -1;
	seq[1][1] = -1;
	seq[1][2] = -1;

	seq[2][0] = 1;
	seq[2][1] = 1;
	seq[2][2] = 1;

	// Calcul du déterminant du système

	float d = seq[0][0] * (seq[1][1] * seq[2][2] - (seq[2][1] * seq[1][2]));
	d -= seq[1][0] * (seq[0][1] * seq[2][2] - (seq[2][1] * seq[0][2]));
	d += seq[2][0] * (seq[0][1] * seq[1][2] - (seq[1][1] * seq[0][2]));

	// Résolution du système par la solution de Cramer

	// Trouver le x

	float x;
	float xseq[3][3];

	xseq[0][0] = b[0];
	xseq[0][1] = b[1];
	xseq[0][2] = b[2];
	xseq[1][0] = seq[1][0];
	xseq[1][1] = seq[1][1];
	xseq[1][2] = seq[1][2];
	xseq[2][0] = seq[2][0];
	xseq[2][1] = seq[2][1];
	xseq[2][2] = seq[2][2];

	float dx = seq[0][0] * (seq[1][1] * seq[2][2] - (seq[2][1] * seq[1][2]));
	dx -= seq[1][0] * (seq[0][1] * seq[2][2] - (seq[2][1] * seq[0][2]));
	dx += seq[2][0] * (seq[0][1] * seq[1][2] - (seq[1][1] * seq[0][2]));

	x = dx / d;

	// Trouver le y

	float y;
	float yseq[3][3];

	yseq[0][0] = seq[0][0];
	yseq[0][1] = seq[0][1];
	yseq[0][2] = seq[0][2];
	yseq[1][0] = b[0];
	yseq[1][1] = b[1];
	yseq[1][2] = b[2];
	yseq[2][0] = seq[2][0];
	yseq[2][1] = seq[2][1];
	yseq[2][2] = seq[2][2];

	float dy = seq[0][0] * (seq[1][1] * seq[2][2] - (seq[2][1] * seq[1][2]));
	dy -= seq[1][0] * (seq[0][1] * seq[2][2] - (seq[2][1] * seq[0][2]));
	dy += seq[2][0] * (seq[0][1] * seq[1][2] - (seq[1][1] * seq[0][2]));

	y = dy / d;

	//Trouver le z
	float z = 0; //Pour linstant
}