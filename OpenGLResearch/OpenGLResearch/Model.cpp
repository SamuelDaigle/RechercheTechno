#include "Model.h"

Model::Model(const char* path, MeshLoader* _meshLoader)
{
	meshes = _meshLoader->LoadMeshes(path);
}

void Model::Draw(IShader& shader)
{
	for (GLuint i = 0; i < meshes.size(); i++)
		meshes[i]->Draw(shader);
}


