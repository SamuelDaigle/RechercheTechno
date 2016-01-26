#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Window* window;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Window();

	window->Initialize();

	window->Start();

	window->Destroy();

	delete window;

	return 0;
}