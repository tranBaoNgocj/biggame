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
    desRect.y = 0;
    desRect.h = HEIGHT;
    desRect.w = WIDTH;

    SDL_RenderCopy(renderer, backGroundTexture, &srcRect, &desRect);
}

void backGround::drawFence()
{
    int st = 0;
	while (st < WIDTH) {
		drawTranigle(st, 40, true);
		st += thornSixe;
	}
}

void backGround::drawTranigle(int st_, int edgePos_, bool flag_)
{
    int detY = (flag_ == true) ? 1 : -1;
	int st = st_, ed = st + thornSixe;
	while (st <= ed) {
		SDL_RenderDrawLine(renderer, st, edgePos_, ed, edgePos_);
		SDL_RenderDrawLine(renderer, st, edgePos_ + 1, ed, edgePos_ + 1);
		edgePos_ += detY * 2;
		st++, ed--;
	}
}
