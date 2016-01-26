#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;

	IObject* triangle = new Triangle();
	triangle->Initialize();
	triangle->Translate(0, -2, 0);

	/*Triangle* triangle2 = new Triangle();
	triangle2->SetVertices(vec3(-0.5f, -0.5f, 0.0f), 0.25f);
	triangle2->SetColors(RED, TRANSPARENT, BLUE);*/

	renderedObjects.push_back(triangle);
	//renderedObjects.push_back(triangle2);
}

void Scene::Destroy()
{
	for each (IObject* sceneObject in renderedObjects)
	{
		SAFE_DESTROY(sceneObject);
	}
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
	for each (IObject* sceneObject in renderedObjects)
	{
		sceneObject->Rotate(0, 0, 0.0005f);
		//sceneObject->Translate(0, 0.001f, 0);
		//sceneObject->Reshape(0.005f, 0, 0);
		ptrOpenGL->SetShaderParameters(sceneObject->GetWorldMatrix());
		sceneObject->Render();
	}
}

void Scene::update()
{

}