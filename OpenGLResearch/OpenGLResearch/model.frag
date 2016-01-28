#version 330 core

struct Material {
    sampler2D diffuse1;
    sampler2D specular1;
    float shininess;
}; 

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 ex_FragPos;
in vec3 ex_Normal;
in vec2 ex_TexCoord;

out vec4 color;

//uniform vec3 viewPos;
//uniform PointLight pointLights;
//uniform Material material;

// Function prototypes
vec3 CalcPointLight(PointLight light, Material mat, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{    
    //vec3 result;
    //vec3 viewDir = normalize(viewPos - ex_FragPos);
    //vec3 norm = normalize(ex_Normal);
    
    //result = CalcPointLight(pointLights, material, norm, ex_FragPos, viewDir);
        
    color = vec4(1.0f, 50.0f, 0.0f, 1.0f);
}


// Calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, Material mat, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), mat.shininess);

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    // Combine results
    vec3 ambient = light.ambient * vec3(texture(mat.diffuse1, ex_TexCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(mat.diffuse1, ex_TexCoord));
    vec3 specular = light.specular * spec * vec3(texture(mat.diffuse1, ex_TexCoord));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}