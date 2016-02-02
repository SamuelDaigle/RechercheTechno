#version 330 core

struct PointLight {
	vec3 position;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 ex_Normal;
in vec3 ex_FragPos;
in vec2 ex_TexCoord;
in vec4 ex_Color;

out vec4 color;

uniform vec3 viewPos;
uniform PointLight pointLight;
uniform sampler2D textureSample;

void main()
{    
	vec3 texture = vec3(texture(textureSample, ex_TexCoord));

	// Ambient
    vec3 ambient = pointLight.ambient * texture;
  	
    // Diffuse 
    vec3 norm = normalize(ex_Normal);
    vec3 lightDir = normalize(pointLight.position - ex_FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * pointLight.diffuse * texture;
    
    // Specular
    vec3 viewDir = normalize(viewPos - ex_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = pointLight.specular * spec * texture;

	// Combine results
	vec3 result = ambient + diffuse + specular;

    color = vec4(result, 1.0f) * ex_Color;
}