#pragma once
#include "Triangle.h"

class Manipulation
{
public:
	Manipulation();
	~Manipulation();

	virtual void ApplyManipulation(Triangle _triangle) = 0;
};

