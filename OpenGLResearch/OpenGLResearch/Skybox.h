#pragma once

#include "stdafx.h"
#include "Dependencies/cimg/CImg.h"

using namespace cimg_library;

class Skybox
{
public:
	void Initialize(vector<const GLchar*> _filePaths, TextureLoader* _textureLoader);
	void Destroy();

	void Render(IShader& _shader);

private:
	GLuint cubemapID;
	GLuint skyboxVAO;
};

