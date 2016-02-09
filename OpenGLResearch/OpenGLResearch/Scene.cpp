#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	planet = new Planet();
	planet->Initialize(textureLoader);
	planet->Translate(0, 0, 10);
	planet->SetRotationSpeed(0.0005f);
	planet->SetColor(1,0.4f,1);

	Composite* planetComposite = new Composite();
	planetComposite->Initialize(textureLoader);
	planetComposite->SetRotationSpeed(0.000005f);
	planetComposite->Translate(10, 0, 0);
	planetComposite->SetColor(0, 1, 0.2f);

	IObject* moon = new Planet();
	moon->Initialize(textureLoader);
	moon->Scale(0.3f, 0.3f, 0.3f);
	moon->SetColor(1.0f, 1.0f, 1.0f);
	moon->SetRotationSpeed(-0.005f);
	moon->Translate(6, 0, 0);
	
	rootObject = new Composite();
	IObject* sun = new Sun();
	sun->Initialize(textureLoader);
	rootObject->Initialize(sun);
	rootObject->Add(planet);
	planetComposite->Add(moon);
	rootObject->Add(planetComposite);

	basicShader = new Shader();
	skyboxShader = new SkyboxShader();

	skybox = new Skybox();
	skybox->Initialize("../Content/skybox/space3.jpg", textureLoader);

	light = new Light();
	light->Initialize();

	ptrOpenGL->GetCamera()->position.z += 5;

	rootObject->Scale(5, 5, 5);
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
	glDepthMask(GL_FALSE);
	skyboxShader->Use();
	skyboxShader->SetViewMatrix(transpose(orientate4(ptrOpenGL->GetCamera()->rotation)));
	skyboxShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());
	skybox->Render(*skyboxShader);
	glDepthMask(GL_TRUE);
	
	basicShader->Use();
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

	glUniform3f(glGetUniformLocation(basicShader->glProgram, "viewPos"), ptrOpenGL->GetCamera()->position.x, ptrOpenGL->GetCamera()->position.y, ptrOpenGL->GetCamera()->position.z);
	light->Apply(basicShader);
	rootObject->Render(*basicShader);
}

void Scene::update()
{
	rootObject->Update();
}