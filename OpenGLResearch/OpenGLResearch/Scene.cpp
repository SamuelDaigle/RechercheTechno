#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;
	cursorPosition = new POINT;
	lastCursorPosition = new POINT;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	IObject* triangle = new Triangle();
	triangle->Initialize(textureLoader);

	IObject* triangle2 = new Triangle();
	triangle2->Initialize(textureLoader);
	triangle2->Translate(0, -2, 0);

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
	delete cursorPosition;
	delete lastCursorPosition;
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
	*lastCursorPosition = *cursorPosition;
	GetCursorPos(cursorPosition);

	if (cursorPosition->x > lastCursorPosition->x)
	{
		ptrOpenGL->GetCamera()->rotation.z -= 0.005f;
	}
	else if (cursorPosition->x < lastCursorPosition->x)
	{
		ptrOpenGL->GetCamera()->rotation.z += 0.005f;
	}

	if (cursorPosition->y > lastCursorPosition->y)
	{
		ptrOpenGL->GetCamera()->rotation.x += 0.005f;
	}
	else if (cursorPosition->y < lastCursorPosition->y)
	{
		ptrOpenGL->GetCamera()->rotation.x -= 0.005f;
	}

	if (ptrInputHandler->IsKeyDown(VK_LEFT))
	{
		ptrOpenGL->GetCamera()->translation -= ptrOpenGL->GetCamera()->right * vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown(VK_UP))
	{
		ptrOpenGL->GetCamera()->translation -= ptrOpenGL->GetCamera()->direction* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown(VK_RIGHT))
	{
		ptrOpenGL->GetCamera()->translation += ptrOpenGL->GetCamera()->right* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown(VK_DOWN))
	{
		ptrOpenGL->GetCamera()->translation += ptrOpenGL->GetCamera()->direction* vec3(0.01, 0.01, 0.01);
	}
}

void Scene::render()
{
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());
	rootObject->Render(*basicShader);
}

void Scene::update()
{

}