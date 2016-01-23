#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "ShaderLoader.h"
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Window* window;

void update(int _i)
{
	window->Update();
	glutPostRedisplay();
	glutTimerFunc(0.1f, update, 0.1f);
}

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
	ShaderLoader shaderLoader;
	window = new Window();

	glutInit(&argc, argv);
	window->Initialize();

	shaderLoader.LoadShader("color.vert", ShaderLoader::VERTEX);
	shaderLoader.LoadShader("color.frag", ShaderLoader::FRAGMENTATION);
	shaderLoader.CompileLoadedShaders();

	glutTimerFunc( 0.1f, update, 0.1f);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}