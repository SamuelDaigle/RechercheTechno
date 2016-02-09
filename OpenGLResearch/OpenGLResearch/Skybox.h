#pragma once

#include "stdafx.h"
#include "Dependencies/soil/SOIL.h"

class Skybox
{
public:
	void Initialize(vector<const GLchar*> _filePaths, TextureLoader* _textureLoader);
	void Initialize(const GLchar* _filename, TextureLoader* _textureLoader);
	void Destroy();

	void Render(IShader& _shader);

private:
	void loadMesh();

	GLuint cubemapID;
	GLuint skyboxVAO;
};

