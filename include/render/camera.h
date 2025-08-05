#pragma once

#include "math/qmath.h"

class Camera {
private:
    qmath::Vector3 _position;
    qmath::Vector3 _target;

    qmath::Vector3 _up;
    qmath::Vector3 _right;
    qmath::Vector3 _forward;

    float _fov = 45.0f;
    float _aspect = 4.0f / 3.0f;
    float _near = 0.1f;
    float _far = 100.0f;

public:
    Camera();

    Camera(qmath::Vector3 position, qmath::Vector3 target);

    [[nodiscard]] qmath::Matrix getViewMatrix() const;

    void setPerspective(float fov, float aspect, float near, float far);

    [[nodiscard]] qmath::Matrix getPerspectiveMatrix() const;

    void moveX(float delta);

    void moveY(float delta);
};
