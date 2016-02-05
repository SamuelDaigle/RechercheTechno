#include "OpenGL.h"

void OpenGL::Initialize()
{
	camera = new Camera();
	camera->Initialize();

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_ALWAYS);
	glDepthFunc(GL_LESS);
	glEnable(GL_STENCIL_TEST);

	projectionMatrix = perspective<float>(radians(45.0f), (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 1000.0f);
}

void OpenGL::Destroy()
{
	if (camera)
	{
		camera->Destroy();
		delete camera;
		camera = NULL;
	}
}

mat4& OpenGL::GetViewMatrix()
{
	return camera->GetViewMatrix();
}

mat4& OpenGL::GetProjMatrix()
{
	return projectionMatrix;
}

Camera* OpenGL::GetCamera()
{
	return camera;
}

void OpenGL::BeginScene()
{
	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Update();
}

void OpenGL::EndScene()
{
	glutSwapBuffers();
}