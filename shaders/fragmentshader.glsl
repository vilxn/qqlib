#version 460 core
out vec4 vColor;

in vec3 Normal;
in vec3 FragPosition;

uniform vec4 ourColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;

float ambientStrength = 0.2;

void main(){
    vec3 ambient = lightColor * ambientStrength;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPosition);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffus = diff * lightColor;

    vec4 result = ourColor * vec4(ambient + diffus, 1.0);

    vColor = result;
}