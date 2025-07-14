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
        renderer->ClearBackground(qcore::Color(20, 20, 20, 256));
        
        renderer->DrawRectangle(10, 10, 300, 300);
        renderer->DrawRectangle(300, 300, 100, 100);

        renderer->EndDrawing();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
    }
 
    glfwTerminate();
    return 0;
}
 
 




