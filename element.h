#ifndef ELEMENT_H
#define ELEMENT_H

#include "gameInfor.h"

class bar {
    public:
        friend class ball;
        friend class barManager;
        bar(const char* textureSheet, SDL_Renderer* ren,int y);
        void update();
        void Render();
    private:
        
        int xpos;
        int ypos;
        SDL_Texture* objectTexture;
        SDL_Rect srcRect,desRect;
        SDL_Renderer* renderer;
};

class ball{
    public:
        ball(const char* textureSheet, SDL_Renderer* ren,int x, int y);
        void move(barManager &bars_,int type);
        void Render();

        bool ballOut(bar &bar_);
    private:
        int xpos;
        int ypos;
        SDL_Rect srcRect, desRect;
        SDL_Texture* objectTextue;
        SDL_Renderer* renderer;
};

class barManager{
    public:
        friend class ball;
        barManager();
        void move();
        void draw();
        void creatABoard(const char* textureSheet, SDL_Renderer* ren);
        void creatStartBar(const char* textureSheet, SDL_Renderer* ren);
    private:
        vector <bar> bars;
        void clearInlegal();
        int GAP;
        bool isOut( bar &bar_);
};

#endif