#pragma once

#include "gameInfor.h"
#include "Board.h"

class ball{
    public:
        ball(SDL_Renderer* ren, int x, int y);
        void Update(vector <board> boardManager,int choice);
        void Render();
    private:
        int xpos;
        int ypos;
        void ballInBoard(vector <board>  boardManager, int choice);
        SDL_Texture* ballTexture;
        SDL_Rect srcRect, desRect;
        SDL_Renderer* renderer;
};