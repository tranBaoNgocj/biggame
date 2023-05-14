#pragma once

#include "gameInfor.h"
#include "LTexture.h"

class backGround{
    public:
        backGround(const char* backGroundSheet, SDL_Renderer* ren);
        void render();
        void drawFence();

    private:
        int xpos;
        int ypos;

        void drawTranigle(int st_, int edgePos_, bool flag_);

        SDL_Texture* backGroundTexture;
        SDL_Rect srcRect, desRect;
        SDL_Renderer* renderer;
};
