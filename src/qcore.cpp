#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace qcore{
    Color::Color(unsigned v0, unsigned v1, unsigned v2, unsigned v3) : r(v0), g(v1), b(v2), a(v3){}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}