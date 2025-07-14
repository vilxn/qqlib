#version 460 core
out vec4 vColor;

uniform vec3 ourColor;

void main(){
    vColor = vec4(ourColor, 1);
}