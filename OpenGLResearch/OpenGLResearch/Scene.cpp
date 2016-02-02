#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	planet = new Planet();
	planet->Initialize(textureLoader);
	planet->Translate(0, 1, 5);

	IObject* planet2 = new Planet();
	planet2->Initialize(textureLoader);
	planet2->Translate(10, -2, 0);

	Composite* planetComposite = new Composite();
	planetComposite->Initialize(textureLoader);
	planetComposite->Translate(13, 2, 5);
	
	rootObject = new Composite();
	rootObject->Initialize(textureLoader);
	rootObject->Add(planet);
	planetComposite->Add(planet2);
	rootObject->Add(planetComposite);

	basicShader = new Shader(ptrOpenGL->GetProgram());

	light = new Light();
	light->Initialize();
}

void Scene::Destroy()
{
	SAFE_DESTROY(light);
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
	// Rotation
	ptrOpenGL->GetCamera()->rotation.z -= ptrInputHandler->GetCursorDelta().x / 500;
	ptrOpenGL->GetCamera()->rotation.x += ptrInputHandler->GetCursorDelta().y / 500;

	// Move with arrow.
	if (ptrInputHandler->IsKeyDown('a'))
	{
		ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->right * vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('w'))
	{
		ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->forward* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('d'))
	{
		ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->right* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('s'))
	{
		ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->forward* vec3(0.01, 0.01, 0.01);
	}
}

void Scene::render()
{
	basicShader->Use();
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

	glUniform3f(glGetUniformLocation(basicShader->glProgram, "viewPos"), ptrOpenGL->GetCamera()->position.x, ptrOpenGL->GetCamera()->position.y, ptrOpenGL->GetCamera()->position.z);
	light->Apply(basicShader);
	rootObject->Render(*basicShader);

}

void Scene::update()
{
	rootObject->Rotate(0, 0.0005f, 0);
	planet->Rotate(0, 0.001f, 0);
}