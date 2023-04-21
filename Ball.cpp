#include "Ball.h"

ball::ball(SDL_Renderer* ren,int x, int y)
    {
        renderer = ren;
        ballTexture = textureManager::LoadTexture(ballName, ren);
        xpos =x;
        ypos =y;
    }
using namespace std;
void ball::ballInBoard(vector <board>  boardManager, int choice)
{
    xpos+=choice* 10;
    for(int i =0; i < (int)boardManager.size();i++)
    {
        // cout<< i<< " ";
        if( (ypos + BALL_SIZE <= boardManager[i].ypos ) && 
            (ypos + BALL_SIZE >=boardManager[i].ypos - BOARD_HEIGHT/2) &&
            (xpos <= boardManager[i].xpos + BOARD_WIDTH - BALL_SIZE/2) && 
            (xpos>= boardManager[i].xpos - BALL_SIZE/2))
        {
            ypos--;
            return;
        }
    }
    ypos++;
}

void ball::Update (vector <board> boardManager,int choice)
{
        ballInBoard(boardManager,choice);
        srcRect.h = BALL_SIZE;
        srcRect.w =BALL_SIZE;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.x = xpos;
        desRect.y = ypos;
        desRect.w = srcRect.w;
        desRect.h = srcRect.h;
}

void ball::Render()
{
            SDL_RenderCopy(renderer, ballTexture, &srcRect, &desRect);
            //desRect : vị trí, tỷ lệ hình, số không gian chiếm
            // srcRect : vị trí bắt đầu cắt của hình, số khônng gian muốn chiếm
}

bool ball::isRunning(){
    if(ypos>BOARD_START_POSITION +5 || ypos <=BOARD_END_POSITION) return false;
    return true;
}