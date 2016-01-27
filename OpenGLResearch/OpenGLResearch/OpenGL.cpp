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

void OpenGL::SetShaderParameters(mat4 _worldMatrix)
{
	unsigned int shaderVariableLocation;

	shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));

	shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(camera->view));

	shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(projectionMatrix));
}

GLfloat* OpenGL::MatrixToFloatArray(mat4 _matrix)
{
	GLfloat* floatArray = new GLfloat[16];
	const int MATRIX_SIZE = 4;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			floatArray[j + i * MATRIX_SIZE] = _matrix[j][i];
		}
	}
	return floatArray;
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