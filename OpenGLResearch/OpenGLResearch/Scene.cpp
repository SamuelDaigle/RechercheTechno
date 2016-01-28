#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	IObject* triangle = new Triangle();
	triangle->Initialize(textureLoader);
	triangle->Translate(0, -2, 0);

	IObject* triangle2 = new Triangle();
	triangle2->Initialize(textureLoader);
	triangle2->Translate(0, 0, 0);

	IObject* planet = new Planet();
	planet->Initialize(textureLoader);


	rootObject = new Composite();
	rootObject->Initialize(textureLoader);

	rootObject->Add(triangle);
	rootObject->Add(triangle2);
	rootObject->Add(planet);

	basicShader = new Shader(ptrOpenGL->GetProgram());
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
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());
	rootObject->Render(*basicShader);
}

void Scene::update()
{

}