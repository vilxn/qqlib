#include "render/renderer.h"
#include "render/shader.h"
#include "math/qmath.h"
#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void Renderer::InitWindow(int width, int height, const char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

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

    _circle = new Circle();
    _circle->Init();
}

void Renderer::DrawRectangle(int posX, int posY, float width, float height){
    qmath::Matrix transformMat = GetTransformMatrix(posX, posY, width, height);

    _shader->Use();
    _shader->SetUniformMatrix4f("ourMatrix", transformMat.GetPointer());
    _shader->SetUniform4f("ourColor", 1, 1, 1, 1);


    glBindVertexArray(rec_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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

Renderer::Renderer(){}

Renderer::~Renderer(){
    delete _renderer;
    delete _shader;
}

bool Renderer::WindowShouldClose(){
    return glfwWindowShouldClose(window);
}

void Renderer::EndDrawing(){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Renderer::ClearBackground(qcore::Color color){
    glClearColor(color.r / 256.0f, color.g / 256.0f, color.b / 256.0f, color.a / 256.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

qmath::Matrix Renderer::GetTransformMatrix(int posX, int posY, int width, int height){
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

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

GLFWwindow* Renderer::GetWindow() const{
    return window;
}