#include "header.h"



void Menu::update() 
{        
    if (IsKeyPressed(KEY_DOWN)) 
    {
        
        Sound select = LoadSound("resources/menu-click-89198.mp3");  
        selection++;
        if (selection > maxSelection) 
        {
            selection = 0;
        }
        PlaySound(select);
    }
    if (IsKeyPressed(KEY_UP)) 
    {
        
        Sound select = LoadSound("resources/menu-click-89198.mp3");  
        selection--;
        if (selection < 0) 
        {
            selection = maxSelection;
        }
        
        PlaySound(select);
    }
    if (IsKeyPressed(KEY_ENTER)) 
    {
        switch (selection) 
        {
            case 0:
                running = false;
                break;
            case 1:
                {                
                    SettingsMenu settingsMenu;
                    settingsMenu.running = true;
                    settingsMenu.run();
                    break;}
            case 2:
                CloseWindow();
                break;
        }
    }
    switch (selection) 
    {
        case 0:
            zero = WHITE;
            one = GRAY;
            two = GRAY;
            break;
        case 1:
            zero = GRAY;
            one = WHITE;
            two = GRAY;
            break;
        case 2:
            zero = GRAY;
            one = GRAY;
            two = WHITE;
            break;
    }
}

void Menu::draw() 
{
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawText("The Juice Box", WindowWidth/2, WindowHeight/2, 50, WHITE);
    DrawText("Start Game", WindowWidth/2, WindowHeight/2+200, 30, zero);
    DrawText("Settings", WindowWidth/2, WindowHeight/2+300, 30, one);
    DrawText("Exit", WindowWidth/2, WindowHeight/2+400, 30, two);
    
    EndDrawing();
}
void Menu::run()
{
    Music music = LoadMusicStream("resources/drone-atmospheric-ambient-150934.mp3"); 
    SetMasterVolume(volume);
    PlayMusicStream(music);
    while (running||!WindowShouldClose()) 
    {        
        if (WindowShouldClose()) 
        {
            running = false;
        }
        update();
        UpdateMusicStream(music);
        draw();
    }
}