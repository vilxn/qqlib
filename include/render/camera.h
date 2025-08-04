#pragma once

#include "math/qmath.h"

class Camera {
private:
    qmath::Vector2 position;

    float _fov;
    float _aspect;
    float _near;
    float _far;

public:
    Camera(const float& fov, const float& aspect, const float& near, const float& far) :
    _fov(fov), _aspect(aspect), _near(near), _far(far) {};


};
