#include "element.h"
#include "run.h"
#include "game.h"
#include "gameInfor.h"
#include <ctime>
#include <SDL.h>
using namespace std;

extern SDL_Renderer *render;
extern SDL_Window *window;	


    Uint32 framStart;
    int frameTime;

    Game *game = nullptr;

int main (int argc, char* args[]){
    srand(time(0));

    // init screen
    game->init("startGame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,400,false);
    
    // running game
    while(game->running()){
        
        game->handleEvents();
        game->update();
        game->render();

        // delay 
        frameTime = SDL_GetTicks()-framStart;
        if(frameDelay> frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    // end game
    game->clean();
    return 0;
}