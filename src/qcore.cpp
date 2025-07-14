#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace qcore{
    
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}