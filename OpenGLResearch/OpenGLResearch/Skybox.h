#pragma once

#include "stdafx.h"

class Skybox
{
public:
	void Initialize(vector<const GLchar*> _filePaths);
	void Destroy();

private:
	GLuint cubemapID;
};

