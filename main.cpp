#include "game.h"
#include "gameInfor.h"
using namespace std;

    Uint32 framStart;
    int frameTime;

Game *game = nullptr;

int main(int argv, char* args[] ){
    int frameDelay;
    game = new Game();
    game->init("startGame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,false);

    while(!game->running()){
        
        framStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameDelay = 1000/game->FPS;

        frameTime = SDL_GetTicks()-framStart;
        if(frameDelay> frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
}