#include "background.h"

backGround::backGround(const char* backGroundSheet, SDL_Renderer* ren)
{
    renderer =ren;
    backGroundTexture = textureManager::LoadTexture(backGroundSheet,ren);
}

void backGround::render()
{
    srcRect.h = 1200;
    srcRect.w = 1200;
    srcRect.x =0;
    srcRect.y =0;

    desRect.x = 0;
    desRect.y = 20;
    desRect.h = HEIGHT;
    desRect.w =WIDTH;

    SDL_RenderCopy(renderer, backGroundTexture, &srcRect, &desRect);
}