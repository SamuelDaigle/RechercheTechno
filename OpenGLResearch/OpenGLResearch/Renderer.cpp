#include "Renderer.h"

void Renderer::Initialize()
{
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
}

void Renderer::AttachDrawableObject(Triangle* _triangle)
{
	renderedObjects.push_back(_triangle);
}

void Renderer::LockRenderer()
{
	const int NB_BUFFER = 2;
	int nbObject = renderedObjects.size();

	vertexArrayObjID = new unsigned int[nbObject];

	glGenVertexArrays(nbObject, vertexArrayObjID);

	for (int i = 0; i < nbObject; i++)
	{
		// Select object array, 
		glBindVertexArray(vertexArrayObjID[i]);
		glGenBuffers(2, vertexBufferObjID[i]);

		// Do not set vertex data nor color data as they will be set during rendering step.
	}	
}

void Renderer::Render()
{
	unsigned int buffer = 0;
	for (int i = 0; i < renderedObjects.size(); i++)
	{
		glBindVertexArray(vertexArrayObjID[i]);

		// Update data.
		setBuffer(i, 0, renderedObjects[i]->vertices);
		setBuffer(i, 1, renderedObjects[i]->colours);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	glBindVertexArray(0);
}

void Renderer::setBuffer(int _objectID, int _bufferID, GLfloat _bufferData[])
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjID[_objectID][_bufferID]);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), _bufferData, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)_bufferID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(_bufferID);
}