#version 330 core

in vec3 in_Position;
in vec3 in_Normal;
in vec3 in_TexCoord;

out vec3 ex_Normal;
out vec3 ex_FragPos;
out vec3 ex_TexCoord;

uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
	gl_Position = vec4(in_Position, 1.0) * worldMatrix;
	gl_Position = gl_Position * viewMatrix;
	gl_Position = gl_Position * projectionMatrix;

	ex_FragPos = vec3(worldMatrix * vec4(in_Position, 1.0f));

	ex_Normal = mat3(transpose(inverse(worldMatrix))) * in_Normal;

	ex_TexCoord = in_TexCoord;
}