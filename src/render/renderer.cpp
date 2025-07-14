#include "render/renderer.h"
#include "render/shader.h"
#include "math/qmath.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void Renderer::Init(){
    _shader = new Shader("shaders/vertexshader.glsl", "shaders/fragmentshader.glsl");

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

    glCreateVertexArrays(1, &rec_VAO);
    glBindVertexArray(rec_VAO);

    unsigned rec_VBO;
    glCreateBuffers(1, &rec_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, rec_VBO);

    unsigned rec_EBO;
    glCreateBuffers(1, &rec_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rec_EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::DrawRectangle(int posX, int posY, float width, float height, GLFWwindow* window){
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    float xRatio = 2.0f / (float)windowWidth;
    float yRatio = 2.0f / (float)windowHeight;

    float recWidth = width * xRatio;
    float recHeight = height * yRatio;

    float xOffset = posX * xRatio;
    float yOffset = posY * yRatio;

    qmath::Matrix mat;
    mat.Scale(recWidth, recHeight, 1);
    mat.Translate(xOffset, -yOffset, 0.0f);
    mat.Translate(recWidth - 1, 1 - recHeight, 0.0f);
    

    _shader->Use();
    _shader->SetUniformMatrix4f("ourMatrix", mat.GetPointer());
    _shader->SetUniform3f("ourColor", 1, 1, 1);


    glBindVertexArray(rec_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Renderer::~Renderer(){
    delete _shader;
}