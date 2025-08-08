#version 460 core
layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    gl_Position = projection * view * model * vec4(vertexPos, 1);

    mat3 normalMatrix = transpose(inverse(mat3(model)));
    Normal = normalize(normalMatrix * aNormal);

    FragPosition = vec3(model * vec4(vertexPos, 1));
}