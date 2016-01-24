#pragma once

class IManipulated
{
public:
	virtual void Translate(float _x, float _y, float _z) = 0;
	virtual void Rotate(float _angle) = 0;
};