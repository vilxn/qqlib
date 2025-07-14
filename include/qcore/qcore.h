#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define Q_RED qcore::Color(250, 5, 5, 256)

namespace qcore{
    struct Color{
        unsigned r;
        unsigned g;
        unsigned b;
        unsigned a;

        Color(unsigned v0, unsigned v1, unsigned v2, unsigned v3);
    };
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);