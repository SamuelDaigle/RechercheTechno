#include "Model.h"

Model::Model(const char* path, TextureLoader* _textureLoader)
{
	loadModel(path, _textureLoader);
}

void Model::Draw(IShader& shader)
{
	for (GLuint i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}

void Model::loadModel(string path, TextureLoader* _textureLoader)
{
	Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	// Check for errors
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}

	directory = path.substr(0, path.find_last_of('/'));

	// Process ASSIMP's root node recursively
	processNode(scene->mRootNode, scene, _textureLoader);
}

void Model::processNode(aiNode* node, const aiScene* scene, TextureLoader* _textureLoader)
{
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene, _textureLoader));
	}

	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene, _textureLoader);
	}
}


Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene, TextureLoader* _textureLoader)
{
	vector<Vertex> vertices;
	vector<GLuint> indices;
	GLuint texture;

	// Walk through each of the mesh's vertices
	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		vec3 vertexPlaceholderData;

		// Positions
		vertexPlaceholderData.x = mesh->mVertices[i].x;
		vertexPlaceholderData.y = mesh->mVertices[i].y;
		vertexPlaceholderData.z = mesh->mVertices[i].z;
		vertex.Position = vertexPlaceholderData;

		// Normals
		vertexPlaceholderData.x = mesh->mNormals[i].x;
		vertexPlaceholderData.y = mesh->mNormals[i].y;
		vertexPlaceholderData.z = mesh->mNormals[i].z;
		vertex.Normal = vertexPlaceholderData;

		// Texture Coordinates
		if (mesh->mTextureCoords[0])
		{
			vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// Process materials
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		// 1. Diffuse maps
		texture = loadMaterialTextures(material, _textureLoader);
	}

	return Mesh(vertices, indices, texture);
}

GLuint Model::loadMaterialTextures(aiMaterial* mat, TextureLoader* _textureLoader)
{
	aiString str;
	mat->GetTexture(aiTextureType_UNKNOWN, 0, &str);

	str = "planet_texture_by_thunorrad.bmp";

	aiString dirStr(directory);
	dirStr.Append("/");
	dirStr.Append(str.C_Str());

	return _textureLoader->GetTexture(dirStr.C_Str());
}