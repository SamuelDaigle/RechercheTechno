/************************************************************************/
/* Author: Samuel Daigle et Sébastien Rousseau                          */
/************************************************************************/

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Window* window;

void Frame(int timeId)
{
	window->Frame();
	glutTimerFunc(1, Frame, 1);
}

void OnKeyPress(unsigned char _key, int _data1, int _data2)
{
	window->OnKeyPress(_key, _data1, _data2);
}

void OnKeyRelease(unsigned char _key, int _data1, int _data2)
{
	window->OnKeyRelease(_key, _data1, _data2);
}

void OnMouseMove(int _x, int _y)
{
	window->OnMouseMove(_x, _y);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Window();
	window->Initialize();

	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);
	glutPassiveMotionFunc(OnMouseMove);

	glutMainLoop();

	window->Destroy();
	delete window;

	return 0;
}