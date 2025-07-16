#pragma once
#include "shapes/shape.h"

class Rectangle : Shape{
public:
    void Init() override;

    void Draw(qmath::Matrix& transformMatrix, Shader* shader) override;
};