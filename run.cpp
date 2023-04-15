#include "run.h"

    game::game()
    {};

    void game:: run()
    {
        bool isquit = false;
        bool isStart = false;
        ball ball(ballSize,{100,100});
        barManager bars;
        int last = SDL_GetTicks();
        int cmd =0;
        while (!isquit){
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT) isquit = true;
            }
            const Uint8* keyStates = SDL_GetKeyboardState(NULL);
            if (keyStates[SDL_SCANCODE_A]) cmd =1, isStart =true;
            else if(keyStates[SDL_SCANCODE_D]) cmd =2, isStart =false;
            else  cmd =0;
            if (isStart) {
                bars.move();
                ball.update(bars, cmd);
                bars.creatABoard(&last, SDL_GetTicks());
            }
            else last = SDL_GetTicks();
            bars.draw();
            ball.printBall();
            SDL_RenderPresent(render);
        }
        }

    void game ::quit()
    {
        SDL_DestroyRenderer(render);
        SDL_Quit();
    }

    bool welcome()
    {
        ball ball(100,{150,200});
        bar bar({150,280},300);
        bool isquit = false;
        while (!isquit)
        {
            /* code */
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT) return false;
            }
            ball.printBall();
            bar.draw();
            SDL_RenderPresent(render);
        }
        return true;
        
    }

    void game:: drawTranigle(int st_, int edgePos_, bool flag_)
    {
        int detY = (flag_ == true) ? 1 : -1;
        int st = st_, ed = st + tranigleSize;
        while (st <= ed){
            SDL_RenderDrawLine(render, st, edgePos_, ed, edgePos_);
            SDL_RenderDrawLine(render, st, edgePos_ +1, ed, edgePos_ +1);
            edgePos_ += detY * 2;
            st++;
            ed--;
        }
    }

    void game:: drawFence()
    {
        int st = 0;
        while (st < WIDTH) {
            drawTranigle(st, up, true);
            drawTranigle(st, down, false);
            st += tranigleSize;
        }
    }
