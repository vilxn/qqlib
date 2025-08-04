#pragma once

#include "math/qmath.h"

class Camera {
private:
    qmath::Vector3 _position;
    qmath::Vector3 _target;

    qmath::Vector3 _up;
    qmath::Vector3 _right;
    qmath::Vector3 _forward;

    float _fov;
    float _aspect;
    float _near;
    float _far;

public:
    Camera();

    Camera(qmath::Vector3 position, qmath::Vector3 target);

    qmath::Matrix getViewMatrix() const;
};
