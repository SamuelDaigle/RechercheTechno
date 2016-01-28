#include "OpenGL.h"

void OpenGL::Initialize()
{
	camera = new Camera();
	camera->Initialize();

	glEnable(GL_DEPTH_TEST);
	projectionMatrix = perspective<float>(radians(45.0f), (float)1000 / (float)800, 0.1f, 100.0f);;

	ShaderLoader shaderLoader;
	shaderLoader.LoadShader("color.vert", ShaderLoader::VERTEX);
	shaderLoader.LoadShader("color.frag", ShaderLoader::FRAGMENTATION);
	shaderLoader.CompileLoadedShaders(glProgram);
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

GLuint OpenGL::GetProgram()
{
	return glProgram;
}

mat4& OpenGL::GetViewMatrix()
{
	return camera->view;
}

mat4& OpenGL::GetProjMatrix()
{
	return projectionMatrix;
}

void OpenGL::BeginScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Update();
}

void OpenGL::EndScene()
{
	glutSwapBuffers();
}