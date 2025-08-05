#include "render/camera.h"

Camera::Camera() {
    _position = (qmath::Vector3){0.0f, 0.0f, 3.0f};
    _target = (qmath::Vector3){0.0f, 0.0f, 0.0f};
}

Camera::Camera(qmath::Vector3 Position, qmath::Vector3 Target) {
    _position = Position;
    _target = Target;

    _forward = qmath::Normalize(Position - _target);

    constexpr qmath::Vector3 upWorld{0.0f, 1.0f, 0.0f};
    _right = qmath::Normalize(qmath::Cross(upWorld, _forward));

    _up = qmath::Cross(_forward, _right);
}

qmath::Matrix Camera::getViewMatrix() const {
    qmath::Matrix lookAt(0.0f);
    qmath::Matrix cameraPosMat;

    lookAt[0][0] = _right.x;   lookAt[0][1] = _right.y;   lookAt[0][2] = _right.z;
    lookAt[1][0] = _up.x;      lookAt[1][1] = _up.y;      lookAt[1][2] = _up.z;
    lookAt[2][0] = _forward.x; lookAt[2][1] = _forward.y; lookAt[2][2] = _forward.z;
    lookAt[3][3] = 1.0f;

    cameraPosMat[0][3] = -_position.x;
    cameraPosMat[1][3] = -_position.y;
    cameraPosMat[2][3] = -_position.z;

    lookAt = lookAt.Multiply(cameraPosMat);

    return lookAt;
}

void Camera::setPerspective(float fov, float aspect, float near, float far) {
    _fov = fov;
    _aspect = aspect;
    _near = near;
    _far = far;
}

qmath::Matrix Camera::getPerspectiveMatrix() const {
    qmath::Matrix perspectiveMatrix(0.0f);
    perspectiveMatrix.Perspective(_fov, _aspect, _near, _far);

    return perspectiveMatrix;
}

void Camera::moveX(float delta) {
    _position += _forward * delta;
}

void Camera::moveY(float delta) {
    _position += _right * delta;
}


