#include "render/renderer.h"
#include "render/shader.h"
#include "math/qmath.h"
#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <cmath>

void Renderer::Init(Window* window){
    _window = window;

    _shader = new Shader("shaders/vertexshader.glsl", "shaders/fragmentshader.glsl");

    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);
    glGenVertexArrays(1, &_VAO);

    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

    glEnable(GL_DEPTH_TEST);
}

void Renderer::BeginDrawing(){
    glClear(GL_DEPTH_BUFFER_BIT);

    _windowWidth = _window->GetWidth();
    _windowHeight = _window->GetHeight();

    if(_window->IsKeyPressed(GLFW_KEY_W)) cameraPosY += 0.01f;
    if(_window->IsKeyPressed(GLFW_KEY_S)) cameraPosY -= 0.01f;

    if(_window->IsKeyPressed(GLFW_KEY_A)) cameraPosX -= 0.01f;
    if(_window->IsKeyPressed(GLFW_KEY_D)) cameraPosX += 0.01f;

    qmath::Vector3 cameraPos{.x = cameraPosX, .y = cameraPosY, .z = 3.0f};
    qmath::Vector3 cameraTarget{0};
    qmath::Vector3 cameraDirection = qmath::Normalize(cameraPos - cameraTarget);

    qmath::Vector3 up{.x = 0.0f, .y = 1.0f, .z = 0.0f};
    qmath::Vector3 cameraRight = qmath::Normalize(qmath::Cross(up, cameraDirection));
    qmath::Vector3 cameraUp = qmath::Cross(cameraDirection, cameraRight);

    qmath::Matrix lookAt(0.0f);
    qmath::Matrix cameraPosMat;

    lookAt[0][0] = cameraRight.x;     lookAt[0][1] = cameraRight.y;     lookAt[0][2] = cameraRight.z;
    lookAt[1][0] = cameraUp.x;        lookAt[1][1] = cameraUp.y;        lookAt[1][2] = cameraUp.z;
    lookAt[2][0] = cameraDirection.x; lookAt[2][1] = cameraDirection.y; lookAt[2][2] = cameraDirection.z;
    lookAt[3][3] = 1.0f;

    cameraPosMat[0][3] = -cameraPos.x;
    cameraPosMat[1][3] = -cameraPos.y;
    cameraPosMat[2][3] = -cameraPos.z;

    lookAt = lookAt.Multiply(cameraPosMat);

    qmath::Matrix view(lookAt);
    qmath::Matrix projection;

    projection.Perspective(fov, (float)_windowWidth / _windowHeight, 0.1f, 100.0f);
    if(_window->IsKeyPressed(GLFW_KEY_R)) fov += 0.01f;
    if(_window->IsKeyPressed(GLFW_KEY_F)) fov -= 0.01f;

    _shader->Use();
    _shader->SetUniformMatrix4f("view", view.GetPointer());
    _shader->SetUniformMatrix4f("projection", projection.GetPointer());
}

void Renderer::ClearBackground(qcore::Color color){
    glClearColor(color.r / 256.0f, color.g / 256.0f, color.b / 256.0f, color.a / 256.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawRectangle(int posX, int posY, float width, float height, qcore::Color color){
    unsigned int vertixNum = _vertices.size() / 3;

    float horRatio = 2.0f / (float)_windowHeight;
    float verRatio = 2.0f / (float)_windowHeight;
    
    float x = posX * horRatio - 1.0f;
    float y = 1.0f - posY * verRatio;

    // std::cout << x << " " << y << std::endl;
    float w = width * horRatio;
    float h = height * verRatio;

    _vertices.insert(_vertices.end(), {x, y, 1.0f});
    _vertices.insert(_vertices.end(), {x + w, y, 1.0f});
    _vertices.insert(_vertices.end(), {x + w, y - h, 1.0f});
    _vertices.insert(_vertices.end(), {x, y - h, 1.0f});

    _indices.insert(_indices.end(), {vertixNum, vertixNum + 1, vertixNum + 2});
    _indices.insert(_indices.end(), {vertixNum + 2, vertixNum + 3, vertixNum});
}

void Renderer::DrawCircle(int posX, int posY, int radius, qcore::Color color){
    const int segments = 128;
    
    unsigned int vertixNum = _vertices.size() / 3;

    float horRatio = 2.0f / (float)_windowHeight;
    float verRatio = 2.0f / (float)_windowHeight;

    float positionX = posX * horRatio - 1.0f;
    float positionY = 1.0f - posY * verRatio;

    _vertices.insert(_vertices.end(), {positionX, positionY, 1.0f});

    long double angleOffset = M_PI * 2 / segments;
    for(unsigned int i = 1; i <= segments; i++){
        float x = std::cosl(angleOffset * i) * radius * horRatio;
        float y = std::sinl(angleOffset * i) * radius * verRatio;

        _vertices.insert(_vertices.end(), {positionX + x, positionY - y, 1.0f});
        
        _indices.push_back(vertixNum + i);
        _indices.push_back(vertixNum + (i == segments ? 1 : i + 1));
        _indices.push_back(vertixNum);
    }
}

void Renderer::EndDrawing(){
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f, 

        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f,  0.5f, 
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f, 
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _indices.size(), _indices.data(), GL_STATIC_DRAW);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);

    _shader->Use();
    qmath::Matrix mat;
    // mat.RotateY((int)(glfwGetTime() * 25.0f));
    // mat.RotateX((int)(glfwGetTime() * 25.0f));
    _shader->SetUniformMatrix4f("model", mat.GetPointer());
    _shader->SetUniform4f("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);

    glBindVertexArray(_VBO);
    // glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    _window->SwapBuffers();
    _window->PollEvents();

    if(glGetError() != GL_NO_ERROR) std::cout << "Has error";

    _vertices.clear();
    _indices.clear();
}

Renderer* Renderer::_renderer = nullptr;

Renderer* Renderer::GetInstance(){
    if(_renderer == nullptr){
        _renderer = new Renderer();
    }

    return _renderer;
}

qmath::Matrix Renderer::GetTransformMatrix(int posX, int posY, int width, int height){
    int windowWidth = _window->GetWidth(); 
    int windowHeight = _window->GetHeight();

    float xRatio = 2.0f / (float)windowWidth;
    float yRatio = 2.0f / (float)windowHeight;

    float shapeWidth = width * xRatio;
    float shapeHeight = height * yRatio;

    float xOffset = posX * xRatio;
    float yOffset = posY * yRatio;

    static float zOffset = 1.0f;

    if(_window->IsKeyPressed(GLFW_KEY_R)) zOffset += 0.01f;
    if(_window->IsKeyPressed(GLFW_KEY_F)) zOffset -= 0.01f;

    qmath::Matrix mat;
    mat.Scale(shapeWidth, shapeHeight, 1);
    mat.Translate(xOffset, -yOffset, zOffset);
    mat.Translate(shapeWidth - 1, 1 - shapeHeight, 0.0f);

    return mat;
}

Renderer::~Renderer(){
    delete _renderer;
    delete _shader;
}

Renderer::Renderer(){}