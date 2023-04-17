// #include "run.h"

// // extern SDL_Renderer *gRender;
// // extern SDL_Window *gwindow;	

    

//     void gameRun()
//     {
//         // bool isquit = false;
//         bool isStart = false;
//         barManager bars;
//         int last = SDL_GetTicks();
//         int cmd =0;
//         // while (!isquit){
//         //     SDL_Event event;
//         //     while(SDL_PollEvent(&event)){
//         //         if(event.type == SDL_QUIT) isquit = true;
//         //     }
//             const Uint8* keyStates = SDL_GetKeyboardState(NULL);
//             if (keyStates[SDL_SCANCODE_A]) cmd =1, isStart =true;
//             else if(keyStates[SDL_SCANCODE_D]) cmd =2, isStart =false;
//             else  cmd =0;
//              if (isStart) {
//                 bars.move();
//                 // void move(barManager &bars_,int type);
//                 ball.move(bars, cmd);
//                 bars.creatABoard(&last, SDL_GetTicks());
//              }
//             else last = SDL_GetTicks();
//             // bars.draw();
//             ball.
//             SDL_RenderPresent(gRender);
//         }

//     // void game ::quit()
//     // {
//     //     SDL_DestroyRenderer(render);
//     //     SDL_Quit();
//     // }

//     // bool game::welcome()
//     // {
//     //     ball ball({150,200},ballSize);
//     //     bar bar({150,280},300);
//     //     bool isquit = false;
//     //     while (!isquit)
//     //     {
//     //         /* code */
//     //         SDL_Event event;
//     //         while(SDL_PollEvent(&event)){
//     //             if(event.type == SDL_QUIT) return false;
//     //         }
//     //         ball.printBall();
//     //         bar.draw();
//     //         SDL_RenderPresent(render);
//     //     }
//     //     return true;
//     // }

//     // void game:: drawTranigle(int st_, int edgePos_, bool flag_)
//     // {
//     //     int detY = (flag_ == true) ? 1 : -1;
//     //     int st = st_, ed = st + tranigleSize;
//     //     while (st <= ed){
//     //         SDL_RenderDrawLine(render, st, edgePos_, ed, edgePos_);
//     //         SDL_RenderDrawLine(render, st, edgePos_ +1, ed, edgePos_ +1);
//     //         edgePos_ += detY * 2;
//     //         st++;
//     //         ed--;
//     //     }
//     // }

//     // void game:: drawFence()
//     // {
//     //     int st = 0;
//     //     while (st < WIDTH) {
//     //         drawTranigle(st, up, true);
//     //         drawTranigle(st, down, false);
//     //         st += tranigleSize;
//     //     }
//     // }
