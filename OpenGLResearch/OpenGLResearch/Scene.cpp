#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	planet = new Planet();
	planet->Initialize(textureLoader);
	planet->Translate(0, 0, 15);
	planet->SetRotationSpeed(0.0005f);
	planet->SetColor(1,0.4f,1);

	Composite* planetComposite = new Composite();
	planetComposite->Initialize(textureLoader);
	planetComposite->SetRotationSpeed(0.000005f);
	planetComposite->Translate(10, 0, 0);
	planetComposite->SetColor(0, 1, 0.2f);

	IObject* planet2 = new Planet();
	planet2->Initialize(textureLoader);
	planet2->Scale(0.3f, 0.3f, 0.3f);
	planet2->SetColor(1.0f, 1.0f, 1.0f);
	planet2->SetRotationSpeed(0.001f);
	planet2->Translate(6, 0, 0);
	
	rootObject = new Composite();
	rootObject->Initialize(textureLoader);
	rootObject->Add(planet);
	planetComposite->Add(planet2);
	rootObject->Add(planetComposite);

	basicShader = new Shader();
	skyboxShader = new SkyboxShader();


	vector<const char*> filePaths;
	filePaths.push_back("../Content/skybox/right.bmp");
	filePaths.push_back("../Content/skybox/left.bmp");
	filePaths.push_back("../Content/skybox/top.bmp");
	filePaths.push_back("../Content/skybox/bottom.bmp");
	filePaths.push_back("../Content/skybox/back.bmp");
	filePaths.push_back("../Content/skybox/front.bmp");
	skybox = new Skybox();
	skybox->Initialize(filePaths, textureLoader);

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

	glDepthMask(GL_FALSE);
	skyboxShader->Use();
	skyboxShader->SetViewMatrix(lookAt(vec3(0, 0, 0), ptrOpenGL->GetCamera()->target, vec3(0.0f, 1.0f, 0.0f)));
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