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
	scene->Initialize(openGL, inputhandler);
}

void Window::Destroy()
{
	SAFE_DESTROY(openGL);
	SAFE_DESTROY(inputhandler);
	SAFE_DESTROY(scene);
}

void Window::Frame()
{
		openGL->BeginScene();
		scene->Frame();
		openGL->EndScene();
		inputhandler->LateUpdate();

		if (hasExited())
		{
			glutLeaveMainLoop();
		}
}

void Window::OnKeyPress(unsigned char _key, int _x, int _y)
{
	inputhandler->OnKeyDown(_key);
}

void Window::OnKeyRelease(unsigned char _key, int _x, int _y)
{
	inputhandler->OnKeyUp(_key);
}

void Window::OnMouseMove(int _x, int _y)
{
	inputhandler->OnMouseMove(_x, _y);
}

void Window::initializeWindow()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
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
	return inputhandler->IsKeyDown(VK_ESCAPE);
}