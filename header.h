#pragma once
#include <iostream>
#include <raylib.h>

constexpr int WindowWidth = 1800;
constexpr int WindowHeight = 1200;
extern float volume;
class Menu
{   private:
        int selection = 0;
        int maxSelection = 2;
        
        Color zero = WHITE;
        Color one = GRAY;
        Color two = GRAY;
        void update();
        void draw();
        
    public:
        bool running = true;
        void run();
};
class SettingsMenu
{   private:
        int selection = 0;
        int maxSelection = 1;
        
        Color zero = WHITE;
        Color one = GRAY;
        void update();
        void draw();
        void playSound();
        
    public:
        bool running = false;
        void run();
};
class GameLoop {
    public:
        bool running = false;
        bool paused = false;
        
        void run(); 
    private:
        void pause();
        void resume();
        void update();
        void draw();
};