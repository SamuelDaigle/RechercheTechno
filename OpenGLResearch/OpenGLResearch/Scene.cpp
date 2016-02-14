#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	MeshLoader* meshLoader = new MeshLoader();
	meshLoader->Initialize(textureLoader);

	planet = new Planet();
	planet->Initialize(meshLoader);
	planet->Translate(10, 0, 0);
	planet->SetRotationSpeed(0.0005f);
	planet->SetColor(1,0.4f,1);

	Composite* planetComposite = new Composite();
	planetComposite->Initialize(meshLoader);
	planetComposite->SetRotationSpeed(0.000005f);
	planetComposite->Translate(6, 0, 0);
	planetComposite->SetColor(0, 1, 0.2f);

	IObject* moon = new Planet();
	moon->Initialize(meshLoader);
	moon->Scale(0.3f, 0.3f, 0.3f);
	moon->SetColor(1.0f, 1.0f, 1.0f);
	moon->SetRotationSpeed(-0.005f);
	moon->Translate(6, 0, 0);
	
	rootObject = new Composite();
	rootObject->Add(planet);
	planetComposite->Add(moon);
	rootObject->Add(planetComposite);

	sun = new Sun();
	sun->Initialize(meshLoader);
	sun->SetRotationSpeed(0.0001f);

	basicShader = new BasicShader();
	skyboxShader = new SkyboxShader();
	advancedShader = new AdvancedShader();

	skybox = new Skybox();
	skybox->Initialize("../Content/skybox/space.bmp", textureLoader);

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
		ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->right * vec3(0.05, 0.05, 0.05);
	}
	else if (ptrInputHandler->IsKeyDown('w'))
	{
		ptrOpenGL->GetCamera()->position -= ptrOpenGL->GetCamera()->forward * vec3(0.05, 0.05, 0.05);
	}
	else if (ptrInputHandler->IsKeyDown('d'))
	{
		ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->right * vec3(0.05, 0.05, 0.05);
	}
	else if (ptrInputHandler->IsKeyDown('s'))
	{
		ptrOpenGL->GetCamera()->position += ptrOpenGL->GetCamera()->forward * vec3(0.05, 0.05, 0.05);
	}
}

void Scene::render()
{
	// Draw skybox.
	glDepthMask(GL_FALSE);
	skyboxShader->Use();
	mat4 proj = perspective<float>(90.0f, (float)glutGet(GLUT_SCREEN_WIDTH) / (float)glutGet(GLUT_SCREEN_HEIGHT), 0.1f, 100000.0f);
	mat4 view = orientate4(vec3(-ptrOpenGL->GetCamera()->rotation.x, ptrOpenGL->GetCamera()->rotation.y, ptrOpenGL->GetCamera()->rotation.z));
	skyboxShader->SetViewMatrix(view);
	skyboxShader->SetProjectionMatrix(proj);
	skybox->Render(*skyboxShader);
	glDepthMask(GL_TRUE);
	
	// Draw sun.
	basicShader->Use();
	basicShader->SetWorldMatrix(sun->GetWorldMatrix());
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());
	sun->Render(*basicShader);

	// Draw every planets.
	advancedShader->Use();
	advancedShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	advancedShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

	glUniform3f(glGetUniformLocation(advancedShader->glProgram, "viewPos"), ptrOpenGL->GetCamera()->position.x, ptrOpenGL->GetCamera()->position.y, ptrOpenGL->GetCamera()->position.z);
	light->Apply(advancedShader);
	rootObject->Render(*advancedShader);
}

void Scene::update()
{
	rootObject->Update();
}