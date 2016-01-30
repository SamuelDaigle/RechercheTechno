#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL, InputHandler* _ptrInputHandler)
{
	ptrOpenGL = _ptrOpenGL;
	ptrInputHandler = _ptrInputHandler;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	planet = new Planet();
	planet->Initialize(textureLoader);

	IObject* cube = new Cube();
	cube->Initialize(textureLoader);

	IObject* triangle = new Triangle();
	triangle->Initialize(textureLoader);
	triangle->Translate(0, 0, 5);
	triangle->Scale(2, 2, 2);

	rootObject = new Composite();
	rootObject->Initialize(textureLoader);
	//rootObject->Add(triangle);
	rootObject->Add(planet);
	//rootObject->Add(cube);

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
	// Rotation
	ptrOpenGL->GetCamera()->rotation.z -= ptrInputHandler->GetCursorDelta().x / 1000;
	ptrOpenGL->GetCamera()->rotation.x += ptrInputHandler->GetCursorDelta().y / 1000;

	// Move with arrow.
	if (ptrInputHandler->IsKeyDown('a'))
	{
		ptrOpenGL->GetCamera()->translation += ptrOpenGL->GetCamera()->right * vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('w'))
	{
		ptrOpenGL->GetCamera()->translation += ptrOpenGL->GetCamera()->direction* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('d'))
	{
		ptrOpenGL->GetCamera()->translation -= ptrOpenGL->GetCamera()->right* vec3(0.01, 0.01, 0.01);
	}
	else if (ptrInputHandler->IsKeyDown('s'))
	{
		ptrOpenGL->GetCamera()->translation -= ptrOpenGL->GetCamera()->direction* vec3(0.01, 0.01, 0.01);
	}
}

void Scene::render()
{
	ptrOpenGL->GetCamera()->LookAt(planet->translation);

	basicShader->Use();
	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

	/*Camera* camera = ptrOpenGL->GetCamera();
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "viewPos"), camera->position.x, camera->position.y, camera->position.z);

	// Point light 1
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights.position"), 5, 5, 5);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights.ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights.specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights.linear"), 0.009);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights.quadratic"), 0.0032);*/

	rootObject->Render(*basicShader);
}

void Scene::update()
{

}