#pragma once
#include "glad/glad.h"
#include "render/shader.h"
#include "glad/glad.h"
#include "qcore/qcore.h"
#include "GLFW/glfw3.h"

class Renderer{
private:
    GLFWwindow* window;

    Shader* _shader;

    unsigned rec_VAO;

    

public:
    void InitWindow(int width, int height, const char* title);

    void Init();

    bool WindowShouldClose();

    void BeginDrawing();

    void EndDrawing();

    void ClearBackground(qcore::Color color);

    void DrawRectangle(int posX, int posY, float width, float height);

    ~Renderer();
};