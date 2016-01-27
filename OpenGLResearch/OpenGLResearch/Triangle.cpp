#include "Triangle.h"

void Triangle::Initialize()
{
	/*vec3 position(0, 0, 0);
	SetVertices(position, 0.5f);
	SetColors(RED);*/
	scaling.x = 1;
	scaling.y = 1;
	scaling.z = 1;
	initializeBuffers();
}

void Triangle::Destroy()
{
	shutdownBuffers();
}

void Triangle::SetVertices(vec3 _position, float _size)
{
	SetVertices(_position, _size, _size);
}

void Triangle::SetVertices(vec3 _position, float _width, float _height)
{
	/*vertices[0] = _position.x; vertices[1] = _position.y; vertices[2] = _position.z;
	vertices[3] = _position.x + _width; vertices[4] = _position.y; vertices[5] = _position.z;
	vertices[6] = _position.x + _width / 2; vertices[7] = _position.y + _height; vertices[8] = _position.z;*/
}

void Triangle::SetColors(Color _color)
{
	SetColors(_color, _color, _color);
}

void Triangle::SetColors(Color _color1, Color _color2, Color _color3)
{
	/*colours[0] = _color1.r; colours[1] = _color1.g; colours[2] = _color1.b;
	colours[3] = _color2.r; colours[4] = _color2.g; colours[5] = _color2.b;
	colours[6] = _color3.r; colours[7] = _color3.g; colours[8] = _color3.b;*/
}

void Triangle::Render()
{
	glBindVertexArray(vertexArrayId);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

void Triangle::Translate(float _x, float _y, float _z)
{
	translation.x += _x;
	translation.y += _y;
	translation.z += _z;
}

void Triangle::Rotate(float _angleX, float _angleY, float _angleZ)
{
	rotation.x += _angleX;
	rotation.y += _angleZ;
	rotation.z += _angleY;
}

void Triangle::Reshape(float _scaleX, float _scaleY, float _scaleZ)
{
	scaling.x += _scaleX;
	scaling.y += _scaleY;
	scaling.z += _scaleZ;
}

void Triangle::initializeBuffers()
{
	VertexType* vertices;
	unsigned int* indices;

	vertexCount = 3;
	indexCount = 3;

	vertices = new VertexType[vertexCount];
	indices = new unsigned int[indexCount];

	// Bottom left.
	vertices[0].x = -0.75f;  // Position.
	vertices[0].y = -0.75f;
	vertices[0].z = -0.0f;

	vertices[0].r = 0.0f;  // Color.
	vertices[0].g = 1.0f;
	vertices[0].b = 0.0f;

	// Top middle.
	vertices[1].x = 0.0f;  // Position.
	vertices[1].y = 0.75f;
	vertices[1].z = 0.0f;

	vertices[1].r = 0.0f;  // Color.
	vertices[1].g = 1.0f;
	vertices[1].b = 0.0f;

	// Bottom right.
	vertices[2].x = 0.75f;  // Position.
	vertices[2].y = -0.75f;
	vertices[2].z = 0.0f;

	vertices[2].r = 0.0f;  // Color.
	vertices[2].g = 0.0f;
	vertices[2].b = 1.0f;

	// Load the index array with data.
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top middle.
	indices[2] = 2;  // Bottom right.

	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	// Make two buffers, one for the vertex position and one for the color.
	glGenBuffers(2, &vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(VertexType), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// vertex position.
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(VertexType), 0);

	// vertex color.
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(VertexType), (unsigned char*)NULL + (3 * sizeof(float)));

	glGenBuffers(1, &indexBufferId);

	// Bind the index buffer and load the index data into it.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount* sizeof(unsigned int), indices, GL_STATIC_DRAW);


	// delete vertices as they are stored in OpenGL's buffers.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;
}

void Triangle::shutdownBuffers()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vertexBufferId);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &indexBufferId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vertexArrayId);
}