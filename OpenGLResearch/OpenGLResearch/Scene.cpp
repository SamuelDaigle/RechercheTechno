#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;

	IObject* triangle = new Triangle();
	triangle->Initialize(ptrOpenGL);
	triangle->Translate(0, -2, 0);

	IObject* triangle2 = new Triangle();
	triangle2->Initialize(ptrOpenGL);
	triangle2->Translate(0, 0, 0);

	rootObject = new Composite();
	rootObject->Initialize(ptrOpenGL);
	rootObject->Add(triangle);
	rootObject->Add(triangle2);
}

void Scene::Destroy()
{
	SAFE_DESTROY(rootObject); // destroys its childs.

	// Do not delete ptrOpenGL as the window contains it.
}

void Scene::Frame()
{
	input();
	update();
	render();
}

void Scene::input()
{

}

void Scene::render()
{
	rootObject->Translate(0, 0.001f, 0);
	rootObject->Render();
}

void Scene::update()
{

}