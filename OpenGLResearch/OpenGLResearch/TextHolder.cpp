#include "TextHolder.h"


TextHolder::TextHolder()
{
}


TextHolder::~TextHolder()
{
	for each (Text * text in texts)
	{
		SAFE_DESTROY(text);
	}
}

void TextHolder::DrawTexts()
{
	glDepthFunc(GL_FALSE);
	for each (Text * text in texts)
	{
		text->Draw();
	}
	glDepthFunc(GL_TRUE);
}

void TextHolder::NewText(const char * _value, float _x, float _y, float _r, float _g, float _b)
{
	Text * text = new Text();
	text->NewText(_value, _x, _y, _r, _g, _b);
	texts.push_back(text);
}

