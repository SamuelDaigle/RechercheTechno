#pragma once
#include "Dependencies/glew/glew.h"
#include "Dependencies/cimg/CImg.h"
#include <map>

using namespace std;
using namespace cimg_library;

class TextureBank
{
public:
	void Initialize();
	void Destroy();

	bool HasTexture(const char* _path);
	void AddTexture(const char* _path, GLuint _texture);
	GLuint GetTexture(const char* _path);

private:
	map<const char*, GLuint> textureLocations;
};

