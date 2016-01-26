#pragma once

class IObject
{
public:
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;

	virtual void Render() = 0;
	virtual void Translate(float _x, float _y, float _z) = 0;
	virtual void Rotate(float _angle) = 0;
	virtual void Reshape(float _scale) = 0;

protected:
	int vertexCount, indexCount;
	unsigned int vertexArrayId, vertexBufferId, indexBufferId;
};