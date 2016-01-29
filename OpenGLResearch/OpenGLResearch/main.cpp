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

void OnKeyPress(unsigned char _key, int _x, int _y)
{
	window->OnKeyPress(_key, _x, _y);
}

void OnKeyRelease(unsigned char _key, int _x, int _y)
{
	window->OnKeyRelease(_key, _x, _y);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Window();

	window->Initialize();

	glutTimerFunc(1, Frame, 1);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyRelease);

	glutMainLoop();

	window->Destroy();
	delete window;

	return 0;
}