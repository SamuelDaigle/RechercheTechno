#pragma once
#include "Manipulation.h"
#include "Triangle.h"

class Translation : public Manipulation
{
public:
	Translation(float _x, float _y, float _z);
	~Translation();

private:
	float matrix[3][3];

	void CreateMatrix(float _x, float _y, float _z);
	void ApplyManipulation(Triangle _triangle);
};

