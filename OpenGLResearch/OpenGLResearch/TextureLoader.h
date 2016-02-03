#pragma once

#include "Dependencies/cimg/CImg.h"
#include "TextureBank.h"


using namespace cimg_library;

class TextureLoader
{
public:
	void Initialize();
	void ReleaseTextures();

	GLuint GetTexture(const char* _texturePath);
	GLuint LoadTextureFromFile(const char* path);

	CImg<unsigned char> GetUnloadedTexture(const char* _path);

private:
	TextureBank* textureBank;
};

