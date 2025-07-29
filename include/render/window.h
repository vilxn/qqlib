#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Window{
private:
    GLFWwindow* _window;

public:
    Window(int width, int height, const char* title);

    int GetWidth();

    int GetHeight();

    void SwapBuffers();

    void PollEvents();

    bool WindowShouldClose();

    bool IsKeyPressed(int key);

    void Close();
};