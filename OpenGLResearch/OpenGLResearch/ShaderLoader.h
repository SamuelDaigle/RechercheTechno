#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include <iostream>
#include <fstream>

using namespace std;

#pragma once
class ShaderLoader
{
public:
	enum ShaderType
	{
		VERTEX,
		FRAGMENTATION
	};

	ShaderLoader();
	~ShaderLoader();

	GLuint LoadShader(char* _filepath, ShaderType _shaderType);
	void CompileLoadedShaders(GLuint& _glProgram);
	void CompileShader(GLuint& _shader);

private:
	char* loadShaderFile(char* _filepath, GLint& _shaderLength);
	void printShaderInfoLog(GLuint& _shaderInfo);

	GLuint vertexShader;
	GLuint fragShader;
};

