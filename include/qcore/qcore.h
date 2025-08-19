#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "math/qmath.h"

#define Q_RED qcore::Color(250, 5, 5, 256)
#define Q_BLACK qcore::Color(10, 10, 10, 256)
#define Q_WHITE qcore::Color(250, 250, 250, 256)

enum class QCameraMode {
    Perspective,
    Orthographic
};

namespace qcore{
    struct Color{
        unsigned r;
        unsigned g;
        unsigned b;
        unsigned a;

        Color(unsigned v0, unsigned v1, unsigned v2, unsigned v3);

        Color(unsigned r, unsigned g, unsigned b);

        qmath::Vector4 toGL();
    };
}

void ClearBackground(qcore::Color color);