#include "render/renderer.h"
#include "render/shader.h"
#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "math/qmath.h"
#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void Renderer::Init(Window* window){
    _window = window;

    _shader = new Shader("shaders/vertexshader.glsl", "shaders/fragmentshader.glsl");

    _rectangle = new Rectangle();
    _rectangle->Init();    

    _circle = new Circle();
    _circle->Init();
}

void Renderer::DrawRectangle(int posX, int posY, float width, float height){
    qmath::Matrix transformMat = GetTransformMatrix(posX, posY, width, height);

    _rectangle->Draw(transformMat, _shader);
}

void Renderer::DrawCircle(int posX, int posY, int radius){
    qmath::Matrix transformMat = GetTransformMatrix(posX, posY, radius * 2, radius * 2);

    _circle->Draw(transformMat, _shader);
}

void Renderer::BeginDrawing(){
    
}

Renderer* Renderer::_renderer = nullptr;

Renderer* Renderer::GetInstance(){
    if(_renderer == nullptr){
        _renderer = new Renderer();
    }

    return _renderer;
}


void Renderer::EndDrawing(){
    _window->SwapBuffers();
    _window->PollEvents();
}

void Renderer::ClearBackground(qcore::Color color){
    glClearColor(color.r / 256.0f, color.g / 256.0f, color.b / 256.0f, color.a / 256.0f);
    glClear(GL_COLOR_BUFFER_BIT);
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

    qmath::Matrix mat;
    mat.Scale(shapeWidth, shapeHeight, 1);
    mat.Translate(xOffset, -yOffset, 0.0f);
    mat.Translate(shapeWidth - 1, 1 - shapeHeight, 0.0f);

    return mat;
}

Renderer::~Renderer(){
    delete _renderer;
    delete _shader;
    delete _rectangle;
}

Renderer::Renderer(){}