#include "Dependencies/glm/glm.hpp"

using namespace glm;

#pragma once
class Vertex
{
public:
	Vertex(vec3 _position, vec2 _textureCoordinate, vec3 _normal);

	vec3 Position;
	vec2 TextureCoordinate;
	vec3 Normal;
};