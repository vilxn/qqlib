#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "qcore/qcore.h"

#include <iostream>


int main()
{
    Renderer* renderer = Renderer::GetInstance();
    renderer->InitWindow(1000, 600, "qqlib");
    renderer->Init();
    
    GLFWwindow* window = renderer->GetWindow();

    while (!renderer->WindowShouldClose())
    {
        renderer->BeginDrawing();
        renderer->ClearBackground(Q_WHITE);
        
        renderer->DrawCircle(100, 100, 100);

        renderer->EndDrawing();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
    }
 
    glfwTerminate();
    return 0;
}
 
 




