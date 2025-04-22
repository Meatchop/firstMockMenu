#include "header.h"

void GameLoop::run() 
{
    while (running) 
    {
        if (WindowShouldClose()) 
        {
            running = false;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}