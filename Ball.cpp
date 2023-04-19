#include "Ball.h"

ball::ball(SDL_Renderer* ren,int x, int y)
    {
        renderer = ren;
        ballTexture = textureManager::LoadTexture(ballName, ren);
        xpos =x;
        ypos =y;
    }

void ball::ballInBoard(vector <board>  boardManager, int choice)
{
    xpos+=choice* 10;
    for(int i =0; i< (int)boardManager.size();i++)
    {
    if( (ypos == boardManager[i].ypos) && 
        ((xpos <= boardManager[i].xpos+BOARD_WIDTH) && (xpos>= boardManager[i].xpos - BOARD_WIDTH/2 )))
        {
            ypos --;
            return;
        }
    }
    ypos++;
}

void ball::Update (vector <board> boardManager,int choice)
{
        ballInBoard(boardManager,choice);
        srcRect.h = 64;
        srcRect.w =64;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.x = xpos;
        desRect.y = ypos;
        desRect.w = srcRect.w / 2;
        desRect.h = srcRect.h /2;
}

void ball::Render()
{
            SDL_RenderCopy(renderer, ballTexture, &srcRect, &desRect);
}
