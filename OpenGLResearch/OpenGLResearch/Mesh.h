/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/* Tutorial(setupMesh): http://www.learnopengl.com/#!Model-Loading/Mesh */
/************************************************************************/

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

#include <GL/glew.h>
#include "Dependencies/glm/glm.hpp"
#include "Dependencies/glm/gtc/matrix_transform.hpp"
#include "Dependencies/assimp/mesh.h"

#include "IShader.h"

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh {
public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	GLuint texture;

	Mesh(vector<Vertex> _vertices, vector<GLuint> _indices, GLuint _texture);
	void Draw(IShader& shader);

private:
	GLuint VAO, VBO, EBO;
	int NbIndices;

	void setupMesh();
};

