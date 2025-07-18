#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "qcore/qcore.h"
#include "math/qmath.h"

#include <iostream>


int main()
{
    Renderer* renderer = Renderer::GetInstance();
    renderer->InitWindow(1000, 600, "qqlib");
    renderer->Init();
    
    GLFWwindow* window = renderer->GetWindow();

    float r = 20.0f;
    qmath::Vector2 pos{r, r};
    qmath::Vector2 vel{200.0f, 100.0f};

    double current = glfwGetTime();
    double prev = 0;
    while (!renderer->WindowShouldClose())
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);

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

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
    }
 
    glfwTerminate();
    return 0;
}
 
 




