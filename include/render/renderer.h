#pragma once
#include "glad/glad.h"
#include "render/shader.h"
#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "glad/glad.h"
#include "qcore/qcore.h"
#include "math/qmath.h"
#include "GLFW/glfw3.h"
#include "render/window.h"


class Renderer{
protected:
    static Renderer* _renderer;

    Window* _window;

    Shader* _shader;

    Circle* _circle;

    Rectangle* _rectangle;

    qmath::Matrix GetTransformMatrix(int posX, int posY, int width, int height);

    Renderer();

public:
    static Renderer* GetInstance();

    void Init(Window* window);

    void BeginDrawing();

    void EndDrawing();

    void ClearBackground(qcore::Color color);

    void DrawRectangle(int posX, int posY, float width, float height, qcore::Color color);

    void DrawCircle(int posX, int posY, int radius, qcore::Color color);

    ~Renderer();

    GLFWwindow* GetWindow() const;
};