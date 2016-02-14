#include "Light.h"


void Light::Initialize()
{
	Position = vec3(-5, 0, 0);
	Ambiant = vec3(0.01f, 0.01f, 0.01f);
	Diffuse = vec3(1.0f, 1.0f, 1.0f);
	Specular = vec3(1.0f, 1.0f, 1.0f);
}

void Light::Destroy()
{

}

void Light::Apply(IShader* _shader)
{
	glUniform3f(glGetUniformLocation(_shader->glProgram, "pointLight.position"), Position.x, Position.y, Position.z);
	glUniform3f(glGetUniformLocation(_shader->glProgram, "pointLight.ambient"), Ambiant.x, Ambiant.y, Ambiant.z);
	glUniform3f(glGetUniformLocation(_shader->glProgram, "pointLight.diffuse"), Diffuse.x, Diffuse.y, Diffuse.z);
	glUniform3f(glGetUniformLocation(_shader->glProgram, "pointLight.specular"), Specular.x, Specular.y, Specular.z);
}