#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "math/qmath.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main()
{
    Renderer renderer;
    renderer.InitWindow(1600, 900, "qqlib");
    renderer.Init();
    

    while (!renderer.WindowShouldClose())
    {
        renderer.BeginDrawing();
        
        renderer.DrawRectangle(10, 10, 400, 20);

        renderer.EndDrawing();
    }
 
    glfwTerminate();
    return 0;
}
 
 




