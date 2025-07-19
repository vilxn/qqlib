#pragma once
#include "shapes/shape.h"
#include "qcore/qcore.h"
#include "render/shader.h"

class Circle : Shape{
private:
    unsigned int _segments = 128;
    
    bool _wasInitialized = false;

    void SendVertices(unsigned int VBO, unsigned int EBO);

public:
    void SetSegments(unsigned int segments);

    void Init() override;

    void Draw(qmath::Matrix& transformMatrix, Shader* shader) override;
};