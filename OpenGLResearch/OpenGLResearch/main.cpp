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

void init(void)
{
	Vector3 position(0,0,0);
	triangle2.SetVertices(position, 0.25f);
	triangle.SetColors(RED, GREEN, BLUE);

	// Allocate Vertex Array Objects
	glGenVertexArrays(2, &vertexArrayObjID[0]);
	// Setup first Vertex Array Object
	glBindVertexArray(vertexArrayObjID[0]);
	glGenBuffers(2, vertexBufferObjID);

	// VBO for vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[0]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle.vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	// VBO for colour data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[1]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle.colours, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	// Setup second Vertex Array Object
	glBindVertexArray(vertexArrayObjID[1]);
	glGenBuffers(1, &vertexBufferObjID[2]);

	// VBO for vertex data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[2]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle2.vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void update(int _i)
{
	window->Update();
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			triangle.vertices[count] += translateMatrix[i][j];
			count++;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(1, update, 1);
}

void display(void)
{
	// clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[0]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), triangle.vertices, GL_STATIC_DRAW);
	glBindVertexArray(vertexArrayObjID[0]);	// First VAO
	glDrawArrays(GL_TRIANGLES, 0, 3);	// draw first object

	glBindVertexArray(vertexArrayObjID[1]);		// select second VAO
	glVertexAttrib3f((GLuint)1, 1.0, 0.0, 0.0); // set constant color attribute
	glDrawArrays(GL_TRIANGLES, 0, 3);	// draw second object

	glBindVertexArray(0);

	glutSwapBuffers();
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
	glutTimerFunc( 1, update, 1);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;

}