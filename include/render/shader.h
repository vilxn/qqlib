#pragma once
#include <string>
#incude "qcore/qcore.h"

class Shader{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void SetUniform3f(const std::string& name, float v1, float v2, float v3);

    void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);

    void SetUniform4f(const std::string& name, qcore::Color color);

    void SetUniformMatrix4f(const std::string& name, const float* value);

    void Use();

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};