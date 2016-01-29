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
	window->Start();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Window();

	window->Initialize();

	glutTimerFunc(1, Frame, 1);

	glutMainLoop();

	window->Destroy();
	delete window;

	return 0;
}