#include "OpenGL.h"

void OpenGL::Initialize()
{
	camera = new Camera();
	camera->Initialize();

	ShaderLoader shaderLoader;
	shaderLoader.LoadShader("color.vert", ShaderLoader::VERTEX);
	shaderLoader.LoadShader("color.frag", ShaderLoader::FRAGMENTATION);
	shaderLoader.CompileLoadedShaders(glProgram);
}

void OpenGL::Destroy()
{
	SAFE_DESTROY(camera);
}

void OpenGL::AttachDrawableObject(Triangle* _triangle)
{
	//renderedObjects.push_back(_triangle);
}

void OpenGL::UpdateShaderMatrix()
{
	unsigned int shaderVariableLocation;

	shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(worldMatrix));

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

void OpenGL::LockRenderer()
{
	/*const int NB_BUFFER = 2;
	int nbObject = renderedObjects.size();

	vertexArrayObjID = new unsigned int[nbObject];
	for (int i = 0; i < nbObject; i++)
	{
		vertexBufferObjID[i] = new unsigned int[2];
	}

	glGenVertexArrays(nbObject, vertexArrayObjID);

	for (int i = 0; i < nbObject; i++)
	{
		// Select object array, 
		glBindVertexArray(vertexArrayObjID[i]);
		glGenBuffers(2, vertexBufferObjID[i]);

		// Do not set vertex data nor color data as they will be set during rendering step.
	}*/
}

void OpenGL::BeginScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL::EndScene()
{
	glutSwapBuffers();
}

void OpenGL::Render()
{
	/*unsigned int buffer = 0;

	camera->position.x++;
	camera->Update();

	UpdateShaderMatrix();

	for (int i = 0; i < renderedObjects.size(); i++)
	{
		renderedObjects[0]->Render(i, vertexBufferObjID[i]);
	}
	glBindVertexArray(0);*/
}