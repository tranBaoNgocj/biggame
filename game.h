#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Ball.h"
// #include "Board.h"

class Game {
    private:
        bool isRunning;
        bool isStarted;
        SDL_Window *window;
        SDL_Renderer *renderer;
    public:
        Game();
        void init (const char* title, int xpos, int ypos, int width,int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        int cnt;
        bool running(){return isRunning;};
};