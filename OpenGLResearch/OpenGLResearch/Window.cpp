#include "Window.h"
#include "stdafx.h"


void Window::Initialize()
{
	initializeWindow();

	openGL = new OpenGL();
	openGL->Initialize();

	inputhandler = new InputHandler();
	inputhandler->Initialize();

	scene = new Scene();
	scene->Initialize();
}

void Window::Start()
{
	while (!hasExited())
	{
		openGL->BeginScene();
		openGL->UpdateShaderMatrix();
		scene->Frame();
		openGL->EndScene();
	}
}

void Window::Destroy()
{
	SAFE_DESTROY(openGL);
	SAFE_DESTROY(inputhandler);
	SAFE_DESTROY(scene);
}

void Window::initializeWindow()
{
	screenWidth = 1000;
	screenHeight = 800;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("OpenGL research");
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "OpenGL version " << glGetString(GL_VERSION) << " supported" << endl;
}

void Window::Display()
{
	openGL->BeginScene();
	openGL->Render();
	openGL->EndScene();	
}

void Window::Reshape(int _screenWidth, int _screenHeight)
{
	glViewport(0, 0, (GLsizei)_screenWidth, (GLsizei)_screenHeight);
}

bool Window::hasExited()
{
	return inputhandler->IsKeyDown('e');
}