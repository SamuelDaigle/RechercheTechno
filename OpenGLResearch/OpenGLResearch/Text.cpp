#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}

void Text::Draw()
{
	int j = strlen(strings);

	glColor3f(r, g, b);
	glRasterPos2f(xPosition, yPosition);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strings[i]);
	}
}

void Text::Destroy()
{
	delete strings;
	strings = NULL;
}

void Text::NewText(const char * _value, float _x, float _y, float _r, float _g, float _b)
{
	strings = _value;
	xPosition = _x;
	yPosition = _y;
	r = _r;
	g = _g;
	b = _b;
}