#version 460 core
layout (location = 0) in vec3 vertexPos;

uniform mat4 ourMatrix;

void main(){
    gl_Position = ourMatrix * vec4(vertexPos, 1);
}