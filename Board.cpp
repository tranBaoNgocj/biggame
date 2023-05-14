#include "Board.h"

using namespace std;
board::board(SDL_Renderer* ren,int x, int y)
{
    renderer = ren;
    kindOfBoard = rand()%5;
    switch (kindOfBoard)
    {
        case 1:
            boardTexture=textureManager::LoadTexture("draw/safe1.png",ren);
            break;
        case 2:
            boardTexture=textureManager::LoadTexture("draw/safe2.png",ren);
            break;
        case 3:
            boardTexture=textureManager::LoadTexture("draw/safe3.png",ren);
            break;
        case 4:
            boardTexture=textureManager::LoadTexture("draw/safe4.png",ren);
            break;
        // case 5:
        //     boardTexture=textureManager::LoadTexture("draw/safe.png",ren);
        //     break;
        // case 6:
        //     boardTexture=textureManager::LoadTexture("draw/safe10.png",ren);
        //     break;
        default:
            boardTexture = textureManager::LoadTexture(dangerBoardName,ren);
            break;
    }
    xpos = x;
    ypos =y;
}

// move board
void board::Update()
{
        ypos -- ;
        srcRect.h = 53;
        srcRect.w = 247;
        srcRect.x = 0;
        srcRect.y = 0;

        desRect.x = xpos;
        desRect.y = ypos;
        desRect.w = BOARD_WIDTH;
        desRect.h = BOARD_HEIGHT;
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
    if (ypos <= BOARD_END_POSITION) return true;
    return false;
}

void ClearIlegal (vector <board> &boardManager)
{
    for (int i =  boardManager.size() - 1; i >=0 ; i--) {
		if (boardManager[i].OutScreen()) {
            boardManager.erase(boardManager.begin() + i);
            return;
        }
	}
}


void CreatStartBar (vector <board> &boardManager,SDL_Renderer* ren)
{
    for(int i= GAME_START_POSITION; i< BOARD_START_POSITION;i++){
            int a = rand()%(WIDTH - BOARD_WIDTH);
            board x(ren,a,i);
            boardManager.push_back(x);
            i+= BOARD_WIDTH;
        }
    }
// void CreatABoard (vector <board> boardManager,SDL_Renderer* ren);
void CreatABoard (vector <board> &boardManager,SDL_Renderer* ren)
{
    int a = boardManager.size() ;
    int n = boardManager[a-1].ypos;

    if(n+BOARD_WIDTH < BOARD_START_POSITION)
    {
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
    ClearIlegal(boardManager);
    // std::cout<<boardManager.size()<<std::endl;
}

void RenDer(vector <board> boardManager){
    int n = boardManager.size();
    for(int i =0;i<n;i++){
        boardManager[i].Render();
    }
}