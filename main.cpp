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
        Renderer::ClearBackground(Q_WHITE);
        renderer->EndDrawing();
    }
 
    window.Close();
    return 0;
}
 
 




