#include "glad/glad.h"
#include "shapes/circle.h"
#include "render/shader.h"
#include "qcore/qcore.h"
#include <vector>
#include <cmath>
#include <iostream>

void Circle::SetSegments(unsigned int segments){
    if(!_wasInitialized) _segments = segments;
    else{
        std::cout << "Circle was Initialized\n";
    }
}

void Circle::Init(){
    glCreateVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    unsigned VBO;
    glCreateBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    unsigned EBO;
    glCreateBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    SendVertices(VBO, EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);

    _wasInitialized = true;
}

void Circle::SendVertices(unsigned int VBO, unsigned int EBO){
    float vertices[(_segments + 1) * 3];
    unsigned int indices[_segments * 3];

    long double angleOffset = M_PI * 2 / _segments;

    vertices[0] = -1.0f;
    vertices[1] = 1.0f;
    vertices[2] = 1.0f;

    for(int i = 1; i <= _segments; i++){
        float x = (float)(std::cosl(angleOffset * i) / 2.0l - 1.0l);
        float y = (float)(std::sinl(angleOffset * i) / 2.0l + 1.0l);

        vertices[i * 3] = x;
        vertices[i * 3 + 1] = y;
        vertices[i * 3 + 2] = 1.0f;

        indices[(i - 1) * 3] = i;
        indices[(i - 1) * 3 + 1] = (i == _segments ? 1 : i + 1);
        indices[(i - 1) * 3 + 2] = 0;
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Circle::Draw(qmath::Matrix& transformMatrix, Shader* shader){
    SetupShader(transformMatrix, shader);

    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, _segments * 3, GL_UNSIGNED_INT, 0);
}