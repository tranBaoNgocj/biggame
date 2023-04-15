#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <vector>
#include <SDL.h>

using std::cout;
using std::endl;
using std::vector;

SDL_Renderer *render;
SDL_Window *window;	

bool gameRun = true;

const int HEIGHT = 600;
const int WIDTH = 300;
const int FPS = 60;


class ball{
    public:
        ball(int size_,SDL_Point pos_);
        void printBall(SDL_Color color = {0,0,0,0xff});
        bool ballOut(bar &bar_);
        void update(barManager &bars_,int type);

    private:
        SDL_Point pos;
        int size;
};

class bar {
    public:
        friend barManager;
        friend ball;
        bar( SDL_Point pos_,int width_);
        virtual void draw();
        void move();
    private:
        SDL_Point pos;
        int width = 60;
};

class barManager{
    public:
        friend ball;
        barManager();
        void move();
        void draw();
        void creatABoard(int* last, int now);
    private:
        vector <bar> bars;
        void clearInlegal();
        int GAP;
        bool isOut( bar &bar_);
};

#endif