#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtx\euler_angles.hpp"
#include "Dependencies\glm\gtx\transform.hpp"

#pragma once

using namespace glm;

class IObject
{
public:
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;

	virtual void Render() = 0;
	virtual void Translate(float _x, float _y, float _z) = 0;
	virtual void Rotate(float _angleX, float _angleY, float _angleZ) = 0;
	virtual void Reshape(float _scaleX, float _scaleY, float _scaleZ) = 0;

	virtual mat4 GetWorldMatrix()
	{
		return GetTranslateMatrix() * GetRotationMatrix() * GetScalingMatrix();
	}

protected:
	int vertexCount, indexCount;
	unsigned int vertexArrayId, vertexBufferId, indexBufferId;
	vec3 translation;
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