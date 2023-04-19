#include "game.h"

Game::Game()
{}
ball* balls;
vector <board> barManager;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // sdl init
    if( SDL_Init(SDL_INIT_VIDEO) ==0 )
    {
        std::cout <<"SDL initialize"<< std:: endl;

        // creat window
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if( window )
        {
            std::cout<<" Window be created"<< std::endl;
        }

        //creat renderer
        renderer = SDL_CreateRenderer(window,-1,0);
        if( renderer )
        {
            std::cout<<"renderer be created"<<std::endl;
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
    }

    
    isRunning = true;
    balls = new ball(renderer,5,5);
    // boards = new board(renderer,5,300);
    CreatStartBar (barManager,renderer);
    isStarted = false;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
        isRunning = false;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
            isStarted = true;
                cnt =1;
                break;
            case SDLK_LEFT:
            isStarted = true;
                cnt = -1;
                break;
            default:
                // std::cout<< 3;
                break;
            }
            break;
        default:
            cnt =0;
            break;
    }
    // std::cout<< std::endl<<cnt<<std::endl;
}
void Game::update()
{
    if(isStarted){
    balls->Update(barManager,cnt);
    // boards->Update();
    UpDate(barManager);
    CreatABoard(barManager,renderer);
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);

    balls->Render();
    RenDer(barManager);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{

    // clean window
    SDL_DestroyWindow(window);

    //quit screen
    SDL_Quit();

    std::cout<< "game clean"<<std::endl;
}
