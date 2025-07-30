#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "render/window.h"
#include "qcore/qcore.h"
#include "math/qmath.h"

#include <iostream>


int main()
{
    Window window(800, 600, "qqlib");

    Renderer* renderer = Renderer::GetInstance();
    renderer->Init(&window);
    
    while (!(window.WindowShouldClose()))
    {
        renderer->BeginDrawing();
        renderer->ClearBackground(Q_WHITE);
        renderer->DrawRectangle(200, 200, 100, 100, Q_RED);
        renderer->DrawRectangle(0, 0, 200, 200, Q_BLACK);
        renderer->DrawCircle(400, 300, 100, Q_BLACK);
        renderer->EndDrawing();
    }
 
    window.Close();
    return 0;
}
 
 




