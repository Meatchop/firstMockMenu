#include "header.h"

void SettingsMenu::playSound() 
{
    Sound select = LoadSound("resources/menu-click-89198.mp3");  
    PlaySound(select);
}
void SettingsMenu::update() 
{   if (selection == 0)
    {
        if (IsKeyPressed(KEY_LEFT)) 
        {
            
            playSound();
            volume -= 0.1f;
            if (volume < 0.0f) 
            {
                volume = 0.0f;
            }
            
            SetMasterVolume(volume);
        }
        if(IsKeyPressed(KEY_RIGHT))
        {
            
            playSound();
            volume += 0.1f;
            if (volume > 1.0f) 
            {
                volume = 1.0f;
            }
            
            SetMasterVolume(volume);
        }
    }
      
    if (IsKeyPressed(KEY_DOWN)) 
    {
        
        
        playSound();
        selection++;
        if (selection > maxSelection) 
        {
            selection = 0;
        }
    }
    if (IsKeyPressed(KEY_UP)) 
    {
        
        
        playSound(); 
        selection--;
        if (selection < 0) 
        {
            selection = maxSelection;
        }
        
    }
    if (IsKeyPressed(KEY_ENTER)) 
    {
        
        playSound();
        if (selection == 1)
        {
            running = false;
            return;
        }
        
    }
    switch (selection) 
    {
        case 0:
            zero = WHITE;
            one = GRAY;
            break;
        case 1:
            zero = GRAY;
            one = WHITE;
            break;
    }
}

void SettingsMenu::draw() 
{
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawText("The Juice Box", WindowWidth/2, WindowHeight/2, 50, WHITE);
    DrawText("Sound", WindowWidth/2, WindowHeight/2+200, 30, zero);
    DrawRectangle(WindowWidth/2, WindowHeight/2+300, 400*volume, 30, zero);
    DrawRectangleLines(WindowWidth/2, WindowHeight/2+300, 400, 30, zero);
    DrawText(TextFormat("%0.2f", volume), WindowWidth/2-100, WindowHeight/2+300, 30, zero);
    DrawText("Back", WindowWidth/2, WindowHeight/2+400, 30, one);
    
    EndDrawing();
}
void SettingsMenu::run()
{
    while (running) 
    {
        
        update();
        draw();
    }
}