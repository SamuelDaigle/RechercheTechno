/************************************************************************/
/* Author: Samuel Daigle                                                */
/************************************************************************/

#version 330 core

in vec2 ex_TexCoord;

out vec4 color;

uniform sampler2D textureSample;

void main()
{    
	color = texture(textureSample, ex_TexCoord);
}