#include "Dependencies/glm/gtc/matrix_transform.hpp"

using namespace glm;

#pragma once
class Camera
{
public:
	void Initialize();
	void Destroy();

	void Update();
	void LookAt(vec3 _position);

	mat4 view;

	vec3 position;
	vec3 target;
	vec3 direction;
	vec3 up;
	vec3 right;
};

