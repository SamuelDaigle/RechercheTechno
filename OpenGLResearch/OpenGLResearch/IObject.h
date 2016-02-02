#pragma once

#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtx\euler_angles.hpp"
#include "Dependencies\glm\gtx\transform.hpp"
#include "TextureLoader.h"
#include "IShader.h"

using namespace glm;

class IObject
{
public:
	virtual void Initialize(TextureLoader* _textureLoader) = 0;
	virtual void Destroy() = 0;

	virtual void Render(IShader& _shader) = 0;

	virtual void Translate(float _x, float _y, float _z)
	{
		translation.x += _x;
		translation.y += _y;
		translation.z += _z;
	}

	virtual void Rotate(float _angleX, float _angleY, float _angleZ)
	{
		rotation.x += _angleX;
		rotation.y += _angleZ;
		rotation.z += _angleY;
	}

	virtual void Scale(float _scaleX, float _scaleY, float _scaleZ)
	{
		scaling.x += _scaleX;
		scaling.y += _scaleY;
		scaling.z += _scaleZ;
	}

	virtual mat4 GetWorldMatrix()
	{
		return GetRotationMatrix() * GetScalingMatrix() * GetTranslateMatrix();
	}

	vec3 translation;
protected:
	int vertexCount, indexCount;
	unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	vec3 scaling;
	vec3 rotation;

private:
	virtual mat4 GetRotationMatrix()
	{
		return orientate4(rotation);
	}

	virtual mat4 GetScalingMatrix()
	{
		return scale(scaling);
	}

	virtual mat4 GetTranslateMatrix()
	{
		return translate(translation);
	}
};