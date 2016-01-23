#include "Window.h"
#include "stdafx.h"


void Window::Initialize()
{
	renderer = new Renderer();
	renderer->Initialize();

	Triangle* triangle = new Triangle();
	triangle->SetVertices(Vector3(0.5f, 0.5f, 0.0f), 0.25f);
	triangle->SetColors(RED, GREEN, BLUE);

	Triangle* triangle2 = new Triangle();
	triangle2->SetVertices(Vector3(-0.5f, -0.5f, 0.0f), 0.25f);
	triangle2->SetColors(RED, TRANSPARENT, BLUE);

	Triangle* triangle3 = new Triangle();
	triangle3->SetVertices(Vector3(-0.5f, 0.75f, 0.0f), 0.5f, 0.1f);
	triangle3->SetColors(BLUE, BLUE, BLUE);

	Triangle* triangle4 = new Triangle();
	triangle4->SetVertices(Vector3(-0.5f, 0.35f, 0.0f), 0.5f, 0.1f);
	triangle4->SetColors(BLUE, GREEN, BLUE);

	Triangle* triangle5 = new Triangle();
	triangle5->SetVertices(Vector3(0.5f, 0.25f, 0.0f), 0.5f, 0.1f);
	triangle5->SetColors(BLUE, BLUE, BLUE);

	renderer->AttachDrawableObject(triangle);
	renderer->AttachDrawableObject(triangle2);
	renderer->AttachDrawableObject(triangle3);
	renderer->AttachDrawableObject(triangle4);
	renderer->AttachDrawableObject(triangle5);

	renderer->LockRenderer();
	
}

void Window::Update()
{
	manageInput();

	renderer->renderedObjects[0]->vertices[0] -= 0.0000001f;
}

void Window::Display()
{
	// clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	renderer->Render();

	glutSwapBuffers();
}

void Window::Reshape(int _screenWidth, int _screenHeight)
{
	glViewport(0, 0, (GLsizei)_screenWidth, (GLsizei)_screenHeight);
}

void Window::manageInput()
{

}