#include "AdvancedShader.h"


AdvancedShader::AdvancedShader()
{
	glProgram = glCreateProgram();

	ShaderLoader shaderLoader;

	GLuint vertShaderID = shaderLoader.LoadShader("advanced.vert", ShaderLoader::VERTEX);
	GLuint fragShaderID = shaderLoader.LoadShader("advanced.frag", ShaderLoader::FRAGMENTATION);

	shaderLoader.CompileShader(vertShaderID);
	shaderLoader.CompileShader(fragShaderID);

	glBindAttribLocation(glProgram, 0, "Position");
	glBindAttribLocation(glProgram, 1, "Normal");
	glBindAttribLocation(glProgram, 2, "TexCoords");

	glAttachShader(glProgram, vertShaderID);
	glAttachShader(glProgram, fragShaderID);

	glLinkProgram(glProgram);
}


AdvancedShader::~AdvancedShader()
{
}

void AdvancedShader::SetWorldMatrix(mat4 _worldMatrix)
{
	unsigned int shaderVariableLocation;
	shaderVariableLocation = glGetUniformLocation(glProgram, "worldMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_worldMatrix));
}

void AdvancedShader::SetViewMatrix(mat4 _viewMatrix)
{
	unsigned int shaderVariableLocation;
	shaderVariableLocation = glGetUniformLocation(glProgram, "viewMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_viewMatrix));
}

void AdvancedShader::SetProjectionMatrix(mat4 _projMatrix)
{
	unsigned int shaderVariableLocation;
	shaderVariableLocation = glGetUniformLocation(glProgram, "projectionMatrix");
	glUniformMatrix4fv(shaderVariableLocation, 1, false, MatrixToFloatArray(_projMatrix));
}

GLfloat* AdvancedShader::MatrixToFloatArray(mat4 _matrix)
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

