#include "qcore/qcore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace qcore{
    Color::Color(unsigned v0, unsigned v1, unsigned v2, unsigned v3) : r(v0), g(v1), b(v2), a(v3){}

    Color::Color(unsigned r, unsigned g, unsigned b) : r(r), g(g), b(b), a(256) {}

    qmath::Vector4 Color::toGL()
    {
        return {
            r / 256.0f,
            g / 256.0f,
            b / 256.0f,
            a / 256.0f,
        };
    }
}

void ClearBackground(qcore::Color color){
    glClearColor(color.r / 256.0f, color.g / 256.0f, color.b / 256.0f, color.a / 256.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}