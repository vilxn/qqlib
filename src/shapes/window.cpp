#include "render/window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <cstdlib>
#include <iostream>

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

int Window::GetWidth(){
    int width, height;
    glfwGetWindowSize(_window, &width, &height);
    return width;
}

int Window::GetHeight(){
    int width, height;
    glfwGetWindowSize(_window, &width, &height);
    return height;
}

void Window::SwapBuffers(){
    glfwSwapBuffers(_window);
}

void Window::PollEvents(){
    glfwPollEvents();
}

bool Window::WindowShouldClose(){
    return glfwWindowShouldClose(_window);
}

void Window::Close(){
    glfwTerminate();
}