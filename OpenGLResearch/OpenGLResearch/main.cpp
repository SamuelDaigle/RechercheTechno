#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "ShaderLoader.h"
#include "Window.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

GLfloat translateMatrix[3][3];

// two vertex array objects, one for each object drawn
unsigned int vertexArrayObjID[2];
// three vertex buffer objects in this example
unsigned int vertexBufferObjID[3];

Window* window;
Triangle triangle;
Triangle triangle2;

void update(int _i)
{
	window->Update();
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

	translateMatrix[0][0] = 0.0001f;
	translateMatrix[1][0] = 0.0001f;
	translateMatrix[2][0] = 0.0001f;
	translateMatrix[0][1] = 0.0001f;
	translateMatrix[1][1] = 0.0001f;
	translateMatrix[2][1] = 0.0001f;
	translateMatrix[0][2] = 0.0f;
	translateMatrix[1][2] = 0.0f;
	translateMatrix[2][2] = 0.0f;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Triangle Test");
	glewInit();
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "OpenGL version " << glGetString(GL_VERSION) << " supported" << endl;

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