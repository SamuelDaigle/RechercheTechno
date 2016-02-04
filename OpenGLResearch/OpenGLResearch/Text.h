#pragma once
#include "stdafx.h"

class Text
{
public:
	Text();
	~Text();

	void DrawTexts();
	void NewText(const char * _value, float _x, float _y, float _r, float _g, float _b);

private:
	vector<const char*> strings;
	vector<float> xPosition;
	vector<float> yPosition;
	vector<float> r;
	vector<float> g;
	vector<float> b;
};

