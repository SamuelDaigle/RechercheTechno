#include "Skybox.h"

void Skybox::Initialize(vector<const GLchar*> _filePaths, TextureLoader* _textureLoader)
{

	glGenTextures(1, &cubemapID);
	glActiveTexture(GL_TEXTURE0);
	CImg<unsigned char> image;

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	for (GLuint i = 0; i < _filePaths.size(); i++)
	{
		image = _textureLoader->GetUnloadedTexture(_filePaths[i]);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.data());
	}
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	const GLfloat VERTEX_DISTANCE = 1;

	// Load vertices.
	GLfloat skyboxVertices[] = {
		// Positions          
		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,

		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,

		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,

		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,

		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, VERTEX_DISTANCE,
		-VERTEX_DISTANCE, VERTEX_DISTANCE, -VERTEX_DISTANCE,

		-VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, -VERTEX_DISTANCE,
		-VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE,
		VERTEX_DISTANCE, -VERTEX_DISTANCE, VERTEX_DISTANCE
	};

	// Setup skybox VAO
	GLuint skyboxVBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);
}

void Skybox::Destroy()
{

}

void  Skybox::Render(IShader& _shader)
{
	// skybox cube
	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(_shader.glProgram, "skybox"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}