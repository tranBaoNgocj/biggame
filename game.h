#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Ball.h"
#include "LTexture.h"
#include "background.h"
#include "Button.h"

using std::string;

class Game {
    private:
        bool isQuit;
        bool isStarted;
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
    public:
        Game();
        void init (const char* title, int xpos, int ypos, int width,int height, bool fullscreen);
        void handleEvents();
        void handleButton();
        void update();
        void render();
        void clean();
        int cnt;
        float FPS = 60;
        long long score =0;
        string scorer;
        bool running(){return isQuit;};
};