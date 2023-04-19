#include "Board.h"

board::board(SDL_Renderer* ren,int x, int y)
{
    renderer = ren;
    boardTexture = textureManager::LoadTexture(boardName,ren);
    xpos = x;
    ypos =y;
}

// move board
void board::Update()
{
        ypos -- ;
        srcRect.h = 64;
        srcRect.w = 64;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.x = xpos;
        desRect.y = ypos;
        desRect.w = srcRect.w *2;
        desRect.h = srcRect.h *2;
}

//draw board
void board::Render()
{
    // if(renderer == NULL){
    //     std::cout <<":))"<<" ";
    // }
    SDL_RenderCopy(renderer, boardTexture, &srcRect, &desRect);
    // std::cout <<":))"<<" ";
}

bool board::OutScreen()
{
    if (ypos <= 12); return true;
    return false;
}

void CreatStartBar (vector <board> &boardManager,SDL_Renderer* ren)
{
    for(int i= BOARD_START_POSITION; i> GAME_START_POSITION;i--){
            int a = rand()%(WIDTH - BOARD_WIDTH-20);
            board x(ren,a,i);
            boardManager.push_back(x);
            i-= BOARD_WIDTH;
        }
    }
// void CreatABoard (vector <board> boardManager,SDL_Renderer* ren);
void CreatABoard (vector <board> &boardManager,SDL_Renderer* ren)
{
    int a = boardManager.size() ;
    int n = boardManager[a-1].ypos;

    if(n+BOARD_WIDTH < BOARD_START_POSITION){
            int a = rand()%(WIDTH-BOARD_WIDTH - 20);
            board x(ren,a,BOARD_START_POSITION);
            boardManager.push_back(x);
        }
    }

void UpDate(vector <board> &boardManager)
{
    int n = boardManager.size();
    // std::cout<<n<<" ";
    for(int i =0;i<n;i++){
        boardManager[i].Update();
        // std::cout<<i;
    }
}

void RenDer(vector <board> boardManager){
    int n = boardManager.size();
    for(int i =0;i<n;i++){
        boardManager[i].Render();
    }
}