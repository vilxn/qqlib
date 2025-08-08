#version 460 core
out vec4 vColor;

in vec3 Normal;
in vec3 FragPosition;

uniform vec4 ourColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPositon;

float ambientStrength = 0.2;
float specularStrength = 0.5;

void main(){
    vec3 ambient = lightColor * ambientStrength;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPosition);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffus = diff * lightColor;

    vec3 viewDir = normalize(viewPositon - FragPosition);
    vec3 reflectDir = reflect(lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec4 result = ourColor * vec4(ambient + diffus + specular, 1.0);

    vColor = result;
}