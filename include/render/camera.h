#pragma once

#include "math/qmath.h"
#include "qcore/qcore.h"

class Camera {
private:
    QCameraMode _mode;

    qmath::Vector3 _position;
    qmath::Vector3 _target;

    qmath::Vector3 _up;
    qmath::Vector3 _right;
    qmath::Vector3 _forward;

    float _sensivity = 0.05f;

    float _fov = 45.0f;
    float _aspect = 4.0f / 3.0f;
    float _near = 0.1f;
    float _far = 100.0f;

    float yaw = 90.0f;
    float pitch = 0.0f;

    qmath::Matrix getPerspectiveMatrix() const;

public:
    Camera();

    Camera(qmath::Vector3 position, qmath::Vector3 target, QCameraMode cameraMode);

    qmath::Matrix getViewMatrix() const;

    qmath::Matrix getProjectionMatrix() const;

    void setPerspective(float fov, float aspect, float near, float far);

    void setAspect(float aspect);

    void setSensivity(float sensivity);

    void moveX(float delta);

    void moveZ(float delta);

    void processMouseMovement(const qmath::Vector2 &deltaMouse);

    qmath::Vector3 getPosition();
};
