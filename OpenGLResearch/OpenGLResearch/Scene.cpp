#include "Scene.h"


void Scene::Initialize()
{
	IObject* triangle = new Triangle();
	triangle->Initialize();

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
}

void Scene::Frame()
{
	input();
	render();
	update();
}

void Scene::input()
{

}

void Scene::render()
{
	for each (IObject* sceneObject in renderedObjects)
	{
		sceneObject->Render();
	}
}

void Scene::update()
{

}