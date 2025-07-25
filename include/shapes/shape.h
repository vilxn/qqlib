#pragma once
#include "qcore/qcore.h"
#include "math/qmath.h"
#include "render/shader.h"

class Shape{
protected:    
    qcore::Color _color = Q_WHITE; 

    unsigned int _VAO;

    void SetupShader(qmath::Matrix& transformMatrix, Shader* shader);

public:
    void SetColor(qcore::Color newColor);

    virtual void Init() = 0;

    virtual void Draw(qmath::Matrix& transformMatrix, Shader* shader) = 0;
};