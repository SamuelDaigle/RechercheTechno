/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include "stdafx.h"

class Text
{
public:
	Text();
	~Text();

	void Draw();
	void NewText(const char * _value, float _x, float _y, float _r, float _g, float _b);
	void Destroy();

private:
	const char * strings;
	float xPosition;
	float yPosition;
	float r;
	float g;
	float b;
};

