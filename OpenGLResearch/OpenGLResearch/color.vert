#version 130

in  vec3 in_Position;
in  vec3 in_Color;
out vec3 ex_Color;

uniform mat4 transformMatrix;
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
	ex_Color = in_Color;

	gl_Position = transformMatrix * vec4(in_Position, 1.0);
	gl_Position = gl_Position * worldMatrix;
	gl_Position = gl_Position * viewMatrix;
	gl_Position = gl_Position * projectionMatrix;

}