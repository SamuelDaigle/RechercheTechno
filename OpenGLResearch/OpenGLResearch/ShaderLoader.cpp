#include "ShaderLoader.h"


ShaderLoader::ShaderLoader()
{
}


ShaderLoader::~ShaderLoader()
{
}

void ShaderLoader::LoadShader(char* _filepath, ShaderType _shaderType)
{
	GLuint shader;

	const char* shaderFile;

	if (_shaderType == VERTEX)
	{
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (_shaderType == FRAGMENTATION)
	{
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	}

	// load shaders & get length of each
	GLint shaderLength;

	ShaderLoader shaderLoader;
	shaderFile = shaderLoader.loadShaderFile(_filepath, shaderLength);

	glShaderSource(shader, 1, &shaderFile, &shaderLength);

	if (_shaderType == VERTEX)
	{
		vertexShader = shader;
	}
	else if (_shaderType == FRAGMENTATION)
	{
		fragShader = shader;
	}

	delete[] shaderFile; // dont forget to free allocated memory
}

void ShaderLoader::CompileLoadedShaders()
{
	GLuint glProgram;

	compileShader(vertexShader);
	compileShader(fragShader);

	glProgram = glCreateProgram();

	glBindAttribLocation(glProgram, 0, "in_Position");
	glBindAttribLocation(glProgram, 1, "in_Color");

	glAttachShader(glProgram, vertexShader);
	glAttachShader(glProgram, fragShader);

	glLinkProgram(glProgram);
	glUseProgram(glProgram);
}

void ShaderLoader::compileShader(GLuint& _shader)
{
	GLint compiled;

	glCompileShader(_shader);
	glGetShaderiv(_shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		cout << "Vertex shader not compiled." << endl;
		printShaderInfoLog(_shader);
	}
}

char* ShaderLoader::loadShaderFile(char* _filepath, GLint& _shaderLength)
{
	ifstream::pos_type size;
	char * memblock;
	string text;

	// file read based on example in cplusplus.com tutorial
	ifstream file(_filepath, ios::in | ios::binary | ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		_shaderLength = (GLuint)size;
		memblock = new char[size];
		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();
		cout << "file " << _filepath << " loaded" << endl;
		text.assign(memblock);
	}
	else
	{
		cout << "Unable to open file " << _filepath << endl;
		exit(1);
	}
	return memblock;
}

void ShaderLoader::printShaderInfoLog(GLuint& shader)
{
	int infoLogLen = 0;
	int charsWritten = 0;
	GLchar *infoLog;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

	// should additionally check for OpenGL errors here

	if (infoLogLen > 0)
	{
		infoLog = new GLchar[infoLogLen];
		// error check for fail to allocate memory omitted
		glGetShaderInfoLog(shader, infoLogLen, &charsWritten, infoLog);
		cout << "InfoLog:" << endl << infoLog << endl;
		delete[] infoLog;
	}

	// should additionally check for OpenGL errors here
}