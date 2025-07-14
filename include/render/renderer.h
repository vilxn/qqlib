#pragma once
#include "glad/glad.h"
#include "render/shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Renderer{
private:
    Shader* _shader;

    unsigned rec_VAO;

public:
    void Init();

    void DrawRectangle(int posX, int posY, float width, float height, GLFWwindow* window);

    ~Renderer();
};