#include "game.h"
#include "gameInfor.h"
using namespace std;

    Uint32 framStart;
    int frameTime;

Game *game = nullptr;

int main(int argv, char* args[] ){
    game = new Game();
    game->init("startGame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,false);

    while(game->running()){
        
        framStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks()-framStart;
        if(frameDelay> frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        // cout<< 1<<endl;
        //SDL_Delay(50000);
    }
    game->clean();
    return 0;
}