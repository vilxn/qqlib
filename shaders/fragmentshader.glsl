#version 460 core
out vec4 vColor;

uniform vec4 ourColor;

void main(){
    vColor = ourColor;
}