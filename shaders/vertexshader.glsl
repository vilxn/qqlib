#version 460 core
layout (location = 0) in vec3 vertexPos;

uniform mat4 transformMat;

void main(){
    gl_Position = transformMat * vec4(vertexPos, 1);
}