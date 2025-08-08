#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "math/qmath.h"

class Window{
private:
    GLFWwindow* _window;

    bool firstMouse = true;

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    double lastMousePosX = 0;
    double lastMousePosY = 0;

    double deltaMousePosX = 0;
    double deltaMousePosY = 0;

public:
    Window(int width, int height, const char* title);

    void update();

    float getDeltaTime() const;

    qmath::Vector2 getDeltaMouse() const;

    int getWidth();

    int getHeight();

    double getMousePosX();

    double getMousePosY();

    void SwapBuffers();

    void PollEvents();

    bool WindowShouldClose();

    bool IsKeyPressed(int key);

    void Close();
};
