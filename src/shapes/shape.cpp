#include "shapes/shape.h"
#include "qcore/qcore.h"

void Shape::SetColor(qcore::Color newColor){
    _color = newColor;
}

void Shape::SetupShader(qmath::Matrix& transformMatrix, Shader* shader){
    shader->Use();
    shader->SetUniformMatrix4f("transformMat", transformMatrix.GetPointer());
    shader->SetUniform4f("ourColor", _color.r / 256.0f, _color.g / 256.0f, _color.b / 256.0f, _color.a / 256.0f);
}