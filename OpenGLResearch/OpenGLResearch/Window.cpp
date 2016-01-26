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
	scene->Initialize(openGL);
}

void Window::Start()
{
	while (!hasExited())
	{
		openGL->BeginScene();
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

bool Window::hasExited()
{
	return inputhandler->IsKeyDown('e');
}