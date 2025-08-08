#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "render/window.h"
#include "qcore/qcore.h"
#include "math/qmath.h"

#include <iostream>

int main()
{
    Window window(1600, 900, "qqlib");

    Renderer* renderer = Renderer::GetInstance();
    Camera* camera = new Camera(
        qmath::Vector3(0, 0, 3.0f),
        qmath::Vector3(0, 0, 0),
        QCameraMode::Perspective);
    renderer->Init(&window);
    renderer->SetCamera(camera);
    
    while (!(window.WindowShouldClose()))
    {
        renderer->BeginDrawing();
        Renderer::ClearBackground(qcore::Color(40, 40, 40, 256));
        renderer->EndDrawing();
    }
 
    window.Close();
    return 0;
}
 
 




