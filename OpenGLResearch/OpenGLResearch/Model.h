#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <GL/glew.h>
#include "Dependencies/glm/glm.hpp"
#include "Dependencies/glm/gtc/matrix_transform.hpp"

using namespace glm;

#include "Dependencies/assimp/Importer.hpp"
#include "Dependencies/assimp/scene.h"
#include "Dependencies/assimp/postprocess.h"

using namespace Assimp;

#include "TextureLoader.h"
#include "Mesh.h"

class Model
{
public:
	Model(const char* path, TextureLoader* _textureLoader);
	void Draw(IShader& shader);

private:
	vector<Mesh> meshes;
	string directory;

	void loadModel(string path, TextureLoader* _textureLoader);
	void processNode(aiNode* node, const aiScene* scene, TextureLoader* _textureLoader);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene, TextureLoader* _textureLoader);
	GLuint loadMaterialTextures(aiMaterial* mat, TextureLoader* _textureLoader);
};