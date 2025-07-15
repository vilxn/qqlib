#pragma once
#include "glad/glad.h"
#include "render/shader.h"
#include "glad/glad.h"
#include "qcore/qcore.h"
#include "math/qmath.h"
#include "GLFW/glfw3.h"
#include "shapes/circle.h"

class Renderer{
protected:
    static Renderer* _renderer;

    GLFWwindow* window;

    Shader* _shader;

    Circle* _circle;

    unsigned rec_VAO;

    qmath::Matrix GetTransformMatrix(int posX, int posY, int width, int height);

    Renderer();

public:
    static Renderer* GetInstance();

    void InitWindow(int width, int height, const char* title);

    void Init();

    bool WindowShouldClose();

    void BeginDrawing();

    void EndDrawing();

    void ClearBackground(qcore::Color color);

    void DrawRectangle(int posX, int posY, float width, float height);

    void DrawCircle(int posX, int posY, int radius);

    ~Renderer();

    GLFWwindow* GetWindow() const;
};