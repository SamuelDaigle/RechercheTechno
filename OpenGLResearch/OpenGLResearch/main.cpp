#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Window* window;

void display(void)
{
	window->Display();
}

void reshape(int _screenWidth, int _screenHeight)
{
	window->Reshape(_screenWidth, _screenHeight);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	window = new Window();

	window->Initialize();

	window->Start();

	window->Destroy();

	delete window;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}