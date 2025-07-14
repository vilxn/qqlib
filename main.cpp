#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "render/renderer.h"
#include "math/qmath.h"
#include "qcore/qcore.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main()
{
    Renderer renderer;
    renderer.InitWindow(1000, 600, "qqlib");
    renderer.Init();
    

    while (!renderer.WindowShouldClose())
    {
        renderer.BeginDrawing();
        renderer.ClearBackground((qcore::Color){20, 20, 20, 256});
        
        renderer.DrawRectangle(10, 10, 400, 20);

        renderer.EndDrawing();
    }
 
    glfwTerminate();
    return 0;
}
 
 




