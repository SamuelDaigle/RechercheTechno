/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#pragma once

#include "Mesh.h"

#include <map>
#include <vector>

using namespace std;

class MeshBank
{
public:
	void Initialize();
	void Destroy();

	bool HasMesh(const char* _path);
	void AddMesh(const char* _path, vector<Mesh*>& _mesh);
	vector<Mesh*> GetMesh(const char* _path);

private:
	map<string, vector<Mesh*>> meshs;
};

