#include "render/window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <cstdlib>
#include <iostream>

#include "render/renderer.h"

Window::Window(int width, int height, const char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        abort();
    }
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(_window);

    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    });
 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        abort();
    }
}

void Window::update() {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    double currentMousePosX = getMousePosX();
    double currentMousePosY = getMousePosY();

    if (firstMouse) {
        lastMousePosX = currentMousePosX;
        lastMousePosY = currentMousePosY;
        firstMouse = false;
    }

    deltaMousePosX = currentMousePosX - lastMousePosX;
    deltaMousePosY = currentMousePosY - lastMousePosY;

    lastMousePosX = currentMousePosX;
    lastMousePosY = currentMousePosY;
}

float Window::getDeltaTime() const{
    return deltaTime;
}

qmath::Vector2 Window::getDeltaMouse() const {
    return {
        static_cast<float>(deltaMousePosX),
        static_cast<float>(deltaMousePosY)
    };
}

int Window::getWidth(){
    int width, height;
    glfwGetWindowSize(_window, &width, &height);
    return width;
}

int Window::getHeight(){
    int width, height;
    glfwGetWindowSize(_window, &width, &height);
    return height;
}

double Window::getMousePosX() {
    double x, y;
    glfwGetCursorPos(_window, &x, &y);
    return x;
}

double Window::getMousePosY() {
    double x, y;
    glfwGetCursorPos(_window, &x, &y);
    return y;
}

void Window::SwapBuffers(){
    glfwSwapBuffers(_window);
}

void Window::PollEvents(){
    glfwPollEvents();
}

bool Window::WindowShouldClose(){
    if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) return true;

    return glfwWindowShouldClose(_window);
}

bool Window::IsKeyPressed(int key){
    return (glfwGetKey(_window, key) == GLFW_PRESS);
}

void Window::Close(){
    glfwTerminate();
}