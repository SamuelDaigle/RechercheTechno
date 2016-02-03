#include "Skybox.h"

void Skybox::Initialize(vector<const GLchar*> _filePaths)
{
	TextureLoader textureLoader;
	textureLoader.Initialize();

	glGenTextures(1, &cubemapID);
	glActiveTexture(GL_TEXTURE0);

	GLuint* image = new GLuint[_filePaths.size()];

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	for (GLuint i = 0; i < _filePaths.size(); i++)
	{
		image[i] = textureLoader.GetTexture(_filePaths[i]);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, 1000, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void Skybox::Destroy()
{

}