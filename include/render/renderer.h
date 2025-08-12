#pragma once
#include "glad/glad.h"
#include "render/shader.h"
#include "glad/glad.h"
#include "qcore/qcore.h"
#include "math/qmath.h"
#include "GLFW/glfw3.h"
#include "render/window.h"
#include <vector>

#include "camera.h"

enum class RenderMode{ Perspective, CameraNone};

class Renderer{
protected:
    static Renderer* _renderer;
    Window* _window;

    Shader* _shader;
    Shader* _lightingShader;

    Camera* _camera;

    int _windowWidth;
    int _windowHeight;

    unsigned int _VAO = 0;
    unsigned int _VBO = 0;
    unsigned int _EBO = 0;

    std::vector<float> _vertices;
    std::vector<unsigned int> _indices;

    qmath::Vector3 lightPosition;
    qmath::Vector3 lightColor;
    qmath::Vector3 diffuseColor;
    qmath::Vector3 ambientColor;

    Renderer();

public:
    static Renderer* GetInstance();

    void Init(Window* window);

    void SetCamera(Camera* camera);

    void BeginDrawing();

    void EndDrawing();

    static void ClearBackground(qcore::Color color);

    void DrawRectangle(int posX, int posY, float width, float height, qcore::Color color);

    void DrawCircle(int posX, int posY, int radius, qcore::Color color);

    void MouseCallback(double xpos, double ypos);

    ~Renderer();
};