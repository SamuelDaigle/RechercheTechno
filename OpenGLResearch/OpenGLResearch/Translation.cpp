#include "Translation.h"


Translation::Translation(float _x, float _y, float _z)
{
	CreateMatrix(_x, _y, _z);
}


Translation::~Translation()
{
}

void Translation::CreateMatrix(float _x, float _y, float _z)
{
	float values[3] = { _x, _y, _z };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = values[i];
		}
	}
}

void Translation::ApplyManipulation(Triangle _triangle)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_triangle.vertices[count] += matrix[i][j];
			count++;
		}
	}
}