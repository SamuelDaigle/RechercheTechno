#include "Skybox.h"

void Skybox::Initialize(vector<const GLchar*> _filePaths, TextureLoader* _textureLoader)
{
	int width, height;
	unsigned char* image;

	glGenTextures(1, &cubemapID);

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	for (GLuint i = 0; i < _filePaths.size(); i++)
	{
		image = SOIL_load_image(_filePaths[i], &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	loadMesh();
}

void Skybox::Initialize(const GLchar* _filename, TextureLoader* _textureLoader)
{
	int width, height;
	unsigned char* image;

	glGenTextures(1, &cubemapID);

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapID);
	image = SOIL_load_image(_filename, &width, &height, 0, SOIL_LOAD_RGB);
	for (GLuint i = 0; i < 6; i++)
	{
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	}
	SOIL_free_image_data(image);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	loadMesh();
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

void Skybox::loadMesh()
{
	const GLfloat VERTEX_DISTANCE = 1.0f;

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