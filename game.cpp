#include "game.h"
#include "run.h"

ball* balls;
barManager* bars;

Game::Game()
{}

void Game::init(const char*title, int xpos, int ypos, int width, int height,bool fullscreen)
{
    int flags =0;
        //full screen
        if(fullscreen){
            flags =SDL_WINDOW_FULLSCREEN;
        }

        // initialize sdl
        if( SDL_Init( SDL_INIT_VIDEO ) == 0 )
	    {
		std::cout<< "SDL initialize"<<std::endl ;

        //window
		gWindow = SDL_CreateWindow( title, xpos, ypos, width, height, flags );
        if( gWindow )
		{
			std::cout<< "Window be created"<<std::endl;
		}

        //render
        gRenderer = SDL_CreateRenderer(gWindow,-1,0);
        if(gRenderer){
			std::cout<< "renderer be created"<<std::endl;
            SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
        }
        isRunning = true;
	    }
        balls = new ball("draw/ball.png",gRenderer,55, STARTPOSITION + 15);
        bars = new barManager();
        bars->creatStartBar("draw/barrier.png",gRenderer);
}


void Game::handleEvents()
{
    SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning =false;
            break;
        default:
            break;
        }
}

void Game::update()
{
    // gameRun();
    bool isStart = false;
    int last = SDL_GetTicks();
    int cmd =0;
    const Uint8* keyStates = SDL_GetKeyboardState(NULL);
            if (keyStates[SDL_SCANCODE_A]) cmd =1, isStart =true;
            else if(keyStates[SDL_SCANCODE_D]) cmd =2, isStart =false;
            else  cmd =0;
             if (isStart) {
                bars->move();
                // void move(barManager &bars_,int type)
                // bars.creatABoard(&last, SDL_GetTicks());
                bars->creatABoard("draw/barrier.png",gRenderer);
             }
            else last = SDL_GetTicks();
           
}

void Game::render()
{
    bars->draw();
    balls->Render();
    SDL_RenderPresent(gRenderer);
}

void Game::clean()
{
    // Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gRenderer = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}