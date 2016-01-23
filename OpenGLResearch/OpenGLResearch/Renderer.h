#include "stdafx.h"
#include "Triangle.h"

#include <iostream>
#include <vector>

using namespace std;

class Renderer
{
public:
	void Initialize();
	void AttachDrawableObject(Triangle* _triangle);
	void LockRenderer();
	void Render();

	vector<Triangle*> renderedObjects;
private:
	void setBuffer(int _objectID, int _bufferID, GLfloat* _bufferData);

	unsigned int* vertexArrayObjID;
	unsigned int vertexBufferObjID[2][2];
};