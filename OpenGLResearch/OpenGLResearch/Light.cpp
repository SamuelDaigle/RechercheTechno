#include "Light.h"


void Light::Initialize()
{
	Ambiant = vec3(0.5f, 0.5f, 0.5f);
	Diffuse = vec3(1.0f, 1.0f, 1.0f);
	Specular = vec3(1.0f, 1.0f, 1.0f);
	Constant = 1.0f;
	Linear = 0.009f;
	Quadratic = 0.0032f;
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
	glUniform1f(glGetUniformLocation(_shader->glProgram, "pointLight.constant"), Constant);
	glUniform1f(glGetUniformLocation(_shader->glProgram, "pointLight.linear"), Linear);
	glUniform1f(glGetUniformLocation(_shader->glProgram, "pointLight.quadratic"), Quadratic);
}