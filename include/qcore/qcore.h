#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace qcore{
    struct Color{
        unsigned r;
        unsigned g;
        unsigned b;
        unsigned a;
    };
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);