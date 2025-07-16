#include "shapes/rectangle.h"
#include "glad/glad.h"

void Rectangle::Init(){
    float vertices[] = {
        0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        -1.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f
    };

    unsigned indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    glCreateVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    unsigned VBO;
    glCreateBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    unsigned EBO;
    glCreateBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);
}

void Rectangle::Draw(qmath::Matrix& transformMatrix, Shader* shader){
    shader->Use();
    shader->SetUniformMatrix4f("ourMatrix", transformMatrix.GetPointer());
    shader->SetUniform4f("ourColor", _color.r / 256.0f, _color.g / 256.0f, _color.b / 256.0f, _color.a / 256.0f);


    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}