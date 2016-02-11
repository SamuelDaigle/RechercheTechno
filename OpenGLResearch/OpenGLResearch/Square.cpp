#include "Square.h"


Square::Square()
{
	scaling.x = 1.0f;
	scaling.y = 1.0f;
	scaling.z = 1.0f;
}


Square::~Square()
{
}

void Square::Initialize(MeshLoader* _meshLoader)
{
	initializeBuffers();
}

void Square::Destroy()
{
	shutdownBuffers();
}

void Square::Render(IShader& _shader)
{

	glBindVertexArray(vertexArrayId);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

void Square::Translate(float _x, float _y, float _z)
{
}

void Square::Rotate(float _angleX, float _angleY, float _angleZ)
{
}

void Square::Scale(float _scaleX, float _scaleY, float _scaleZ)
{
}

void Square::initializeBuffers()
{
	VertexType* vertices;
	unsigned int* indices;

	vertexCount = 6;
	indexCount = 6;

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
	vertices[1].x = -0.75f;  // Position.
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

	/////////////////////////////////////////
	// Bottom left.
	vertices[3].x = -0.75f;  // Position.
	vertices[3].y = -0.75f;
	vertices[3].z = -0.0f;

	vertices[3].r = 0.0f;  // Color.
	vertices[3].g = 1.0f;
	vertices[3].b = 0.0f;

	// Top middle.
	vertices[4].x = 0.75f;  // Position.
	vertices[4].y = 0.75f;
	vertices[4].z = 0.0f;

	vertices[4].r = 0.0f;  // Color.
	vertices[4].g = 1.0f;
	vertices[4].b = 0.0f;

	// Bottom right.
	vertices[5].x = 0.75f;  // Position.
	vertices[5].y = -0.75f;
	vertices[5].z = 0.0f;

	vertices[5].r = 0.0f;  // Color.
	vertices[5].g = 0.0f;
	vertices[5].b = 1.0f;

	// Load the index array with data.
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top middle.
	indices[2] = 2;  // Bottom right.

	indices[3] = 0;  // Bottom left.
	indices[4] = 3;  // Top middle.
	indices[5] = 2;  // Bottom right.

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

void Square::shutdownBuffers()
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