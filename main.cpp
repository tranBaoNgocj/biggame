#include "element.h"
#include "run.h"
#include <map>
#include <ctime>
#include <SDL.h>
using namespace std;

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}
    window = SDL_CreateWindow("started", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (window == NULL ||render == NULL){
        cout<< SDL_GetError()<<endl;
    }
    return true;
}


int main (int argc, char* args[]){
    srand(time(0));
    if(!init()) return -1;
    game game;
    bool isLegal = game.welcome();
    if (!isLegal) {
        game.quit();
        return -1;
    }
    game.run();
    game.quit();
    return 0;
}