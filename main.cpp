#include "header.h"

using namespace std;

Menu menu;
GameLoop gameLoop;
float volume = 0.5f;

int main () {
    InitWindow(WindowWidth, WindowHeight, "The Juice Box");
    SetTargetFPS(60);
    InitAudioDevice();
    while (WindowShouldClose() == false){
        if (menu.running == true){
            menu.run();
        }
        if (gameLoop.running == true){
            gameLoop.run();
        }       
    }

    CloseWindow();
}