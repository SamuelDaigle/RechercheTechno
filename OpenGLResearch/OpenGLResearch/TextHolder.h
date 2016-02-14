/************************************************************************/
/* Author: Sébastien Rousseau                                           */
/************************************************************************/

#pragma once
#include "Text.h"

class TextHolder
{
public:
	TextHolder();
	~TextHolder();

	void DrawTexts();
	void NewText(const char * _value, float _x, float _y, float _r, float _g, float _b);

private:
	vector<Text *> texts;
};

