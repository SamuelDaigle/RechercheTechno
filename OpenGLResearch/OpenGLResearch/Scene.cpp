#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	IObject* planet = new Planet();
	planet->Initialize(textureLoader);
	planet->Scale(0.2f, 0.2f, 0.2f);


	rootObject = new Composite();
	rootObject->Initialize(textureLoader);

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