#include "Scene.h"


void Scene::Initialize(OpenGL* _ptrOpenGL)
{
	ptrOpenGL = _ptrOpenGL;

	TextureLoader* textureLoader = new TextureLoader();
	textureLoader->Initialize();

	IObject* planet = new Planet();
	planet->Initialize(textureLoader);


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
	rootObject->Translate(0, 0.001f, 0);

	basicShader->Use();

	basicShader->SetViewMatrix(ptrOpenGL->GetViewMatrix());
	basicShader->SetProjectionMatrix(ptrOpenGL->GetProjMatrix());

	// Point light 1
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].position"), 5, 5, 5);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].linear"), 0.009);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[0].quadratic"), 0.0032);
	// Point light 2
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].position"), -5, -5, -5);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].linear"), 0.009);
	glUniform1f(glGetUniformLocation(basicShader->glProgram, "pointLights[1].quadratic"), 0.0032);

	rootObject->Render(*basicShader);
}

void Scene::update()
{

}