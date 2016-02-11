/************************************************************************/
/* Author: Samuel Daigle                                                */
/* Tutorial: http://www.learnopengl.com/#!Model-Loading/Model           */
/************************************************************************/

#pragma once

#include "MeshBank.h"
#include "TextureLoader.h"
#include "Mesh.h"
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

class MeshLoader
{
public:
	void Initialize(TextureLoader* _textureLoader);
	void ReleaseMeshes();

	vector<Mesh*> LoadMeshes(const char* _filepath);

private:
	void processNode(aiNode* node, const aiScene* scene);
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
	GLuint loadMaterialTextures(aiMaterial* mat);

	vector<Mesh*> meshes;
	string directory;

	MeshBank* meshBank;
	TextureLoader* textureLoader;
};

