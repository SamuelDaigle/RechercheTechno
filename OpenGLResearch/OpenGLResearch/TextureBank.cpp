#include "TextureBank.h"

void TextureBank::Initialize()
{

}

void TextureBank::Destroy()
{
	
}

bool TextureBank::HasTexture(const char* _path)
{
	return textureLocations.find(_path) != textureLocations.end();
}

void TextureBank::AddTexture(const char* _path, GLuint _texture)
{
	textureLocations[_path] = _texture;
}

GLuint TextureBank::GetTexture(const char* _path)
{
	return textureLocations[_path];
}