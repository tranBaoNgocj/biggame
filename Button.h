#pragma once

#include "game.h"
#include "gameInfor.h"

class button
{
    public:
        button(SDL_Renderer* ren,const char* filename,int x, int y);
        void HandleMouseEvent(SDL_Event *e);
        void Render();
        LButtonSprite mCurrentSprite;
    private:
        int xpos;
        int ypos;
        SDL_Texture* buttonTexture;
        SDL_Rect srcRect, desRect;
        SDL_Renderer* renderer;
};