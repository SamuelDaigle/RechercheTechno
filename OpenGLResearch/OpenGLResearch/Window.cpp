#include "Window.h"
#include "stdafx.h"


void Window::Initialize()
{
	Triangle triangle;
	triangle.SetColors(RED, GREEN, BLUE);

	// Allocate Vertex Array Objects
	glGenVertexArrays(2, &vertexArrayObjID[0]);
	// Setup first Vertex Array Object
	glBindVertexArray(vertexArrayObjID[0]);
	glGenBuffers(2, vertexBufferObjID);

	// VBO for vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[0]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle.vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	// VBO for colour data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[1]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle.colours, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Window::Update()
{
	manageInput();
}

void Window::Display()
{
	// clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexArrayObjID[0]);	// First VAO
	glDrawArrays(GL_TRIANGLES, 0, 3);	// draw first object

	glBindVertexArray(vertexArrayObjID[1]);		// select second VAO
	glVertexAttrib3f((GLuint)1, 1.0, 0.0, 0.0); // set constant color attribute
	glDrawArrays(GL_TRIANGLES, 0, 3);	// draw second object

	glBindVertexArray(0);

	glutSwapBuffers();
}

void Window::Reshape(int _screenWidth, int _screenHeight)
{
	glViewport(0, 0, (GLsizei)_screenWidth, (GLsizei)_screenHeight);
}

void Window::manageInput()
{

}