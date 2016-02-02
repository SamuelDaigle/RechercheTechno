#pragma once

#include "stdafx.h"

class Light
{
public:
	void Initialize();
	void Destroy();

	void Apply(IShader* _shader);

	vec3 Position;
	vec3 Ambiant;
	vec3 Diffuse;
	vec3 Specular;
	float Constant;
	float Linear;
	float Quadratic;
};

