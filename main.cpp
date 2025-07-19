#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "render/window.h"
#include "qcore/qcore.h"
#include "math/qmath.h"

#include <iostream>


int main()
{
    Window window(1200, 800, "qqlib");

    Renderer* renderer = Renderer::GetInstance();
    renderer->Init(&window);
    
    float r = 80.0f;
    qmath::Vector2 pos{r, r};
    qmath::Vector2 vel{200.0f, 100.0f};

    double current = glfwGetTime();
    double prev = 0;
    while (!(window.WindowShouldClose()))
    {
        int width = window.GetWidth(); 
        int height = window.GetHeight();

        prev = current;
        current = glfwGetTime();
        double delta = current - prev;

        pos += (vel * (float)delta);

        if(pos.x + r > width || pos.x - r < 0) vel.x *= -1;
        if(pos.y + r > height || pos.y - r < 0) vel.y *= -1;

        renderer->BeginDrawing();
        renderer->ClearBackground(Q_WHITE);
        
        renderer->DrawCircle(pos.x, pos.y, r);

        renderer->EndDrawing();
    }
 
    window.Close();
    return 0;
}
 
 




