#include "game.h"

Game::Game()
{}
ball* balls;
vector <board> barManager;
Ltexture  *gTextTexture;
backGround *background;
button *playButton;
// button *rePlayButton;

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
        
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( (IMG_Init(imgFlags) & imgFlags ) )
        {
            std::cout<<"sdl_image be initialized!"<<std::endl;
        }

        // //Initialize SDL-ttf
        if( TTF_Init() == -1) std::cout<< "sdl_ttf could not be creat";
        font = TTF_OpenFont(fontPath,50);
        if( font )
        {
            std::cout<<"game over ok!"<<std::endl;
        }
        
    }

    
    isQuit = false;
    balls = new ball(renderer,WIDTH/2,GAME_START_POSITION-BALL_SIZE);

    background = new backGround(backgroundName,renderer);

    playButton = new button(renderer, "draw/Play.png", 150, 350);
    // rePlayButton = new button(renderer, "draw/RePlay.png", 100,100);

    gTextTexture = new Ltexture;

    CreatStartBar (barManager,renderer);

    isStarted = false;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        //close window
        case SDL_QUIT:
            isQuit = true;

        //game run
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
                    break;
            }
            break;
        default:
                playButton->HandleMouseEvent(&event);
                if(playButton->mCurrentSprite == BUTTON_SPRITE_MOUSE_DOWN) 
                    isStarted = true;
                cnt = 0;
                break;
    }
}
void Game::update()
{
    if(isStarted){
        UpDate(barManager);
        balls->Update(barManager,cnt);
        CreatABoard(barManager,renderer);
    }
    if(!balls->isRunning())
    {
        isStarted = false;
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    if(isStarted)
    {
        SDL_RenderClear(renderer);
        background->render();
        RenDer(barManager);
        balls->Render();
    }

    if(!isStarted)
    {
        SDL_Color textColor = { 0, 0, 0 };
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        if( !gTextTexture->loadFromRenderedText(renderer,font,"Rapid RoLL",textColor))
        {
            std::cout<< "Failed to render text texture!\n"<<std::endl;
        }
        //Render current frame


        background->render();
        gTextTexture->render( 25, 200,renderer);
        playButton->Render();
    }

    // if(!balls->isRunning())
    // {
    //     SDL_RenderClear (renderer);
    //     rePlayButton->Render();
    // }

    SDL_RenderPresent(renderer);
}

void Game::clean()
{

    // clean window
    SDL_DestroyWindow(window);


    TTF_CloseFont( font );
    TTF_Quit();


    //quit screen
    SDL_Quit();

    std::cout<< "game clean"<<std::endl;
}
