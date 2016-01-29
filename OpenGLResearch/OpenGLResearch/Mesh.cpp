#include "Mesh.h"

Mesh::Mesh(Vertex* _vertices, GLuint* _indices, vector<GLuint> _diffuseLocations, vector<GLuint> _specularLocations)
{
	vertices = _vertices;
	indices = _indices;
	diffuseLocations = _diffuseLocations;
	specularLocations = _specularLocations;

	setupMesh();
}

void Mesh::Draw(IShader& shader)
{
	/*GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	for (GLuint i = 0; i < diffuseLocations.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glUniform1i(glGetUniformLocation(shader.glProgram, "material.diffuse1"), i);
		glBindTexture(GL_TEXTURE_2D, diffuseLocations[i]);
	}

	for (GLuint i = diffuseLocations.size(); i < diffuseLocations.size() + specularLocations.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glUniform1i(glGetUniformLocation(shader.glProgram, "material.specular1"),i);
		glBindTexture(GL_TEXTURE_2D, specularLocations[i - diffuseLocations.size()]);
	}

	glUniform1f(glGetUniformLocation(shader.glProgram, "material.shininess"), 16.0f);*/

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(GLuint), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

	glBindVertexArray(0);
}
