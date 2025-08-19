#version 460 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

out vec4 vColor;

in vec3 Normal;
in vec3 FragPosition;

uniform vec4 ourColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPositon;

void main(){
    // ambient
    vec3 ambient = lightColor * material.ambient;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPosition);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = lightColor * (diff * material.diffuse);

    // specular
//    vec3 viewDir = normalize(FragPosition - viewPositon);
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//    vec3 specular = lightColor * (spec * material.specular);

    vec3 viewDir = normalize(viewPositon - FragPosition);
    vec3 reflectDir = reflect(-viewDir, norm);
    float spec = pow(max(dot(lightDir, reflectDir), 0.0), material.shininess);
    vec3 specular = lightColor * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    vColor = vec4(result, 1.0);
}