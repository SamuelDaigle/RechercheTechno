#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}

void Text::DrawTexts()
{
	glDepthFunc(GL_FALSE);
	for (int i = 0; i < strings.size(); i++)
	{
		int j = strlen(strings[i]);
		
		glColor3f(r[i], g[i], b[i]);
		glRasterPos2f(xPosition[i], yPosition[i]);
		for (int k = 0; k < j; k++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strings[i][k]);
		}
	}
	glDepthFunc(GL_TRUE);
}

void Text::NewText(const char * _value, float _x, float _y, float _r, float _g, float _b)
{
	strings.push_back(_value);
	xPosition.push_back(_x);
	yPosition.push_back(_y);
	r.push_back(_r);
	g.push_back(_g);
	b.push_back(_b);
}
