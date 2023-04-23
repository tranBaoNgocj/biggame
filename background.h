#pragma once

#include "gameInfor.h"
#include "LTexture.h"

class backGround{
    public:
        backGround(const char* backGroundSheet, SDL_Renderer* ren);
        void render();
    private:
        int xpos;
        int ypos;

        SDL_Texture* backGroundTexture;
        SDL_Rect srcRect, desRect;
        SDL_Renderer* renderer;
};
