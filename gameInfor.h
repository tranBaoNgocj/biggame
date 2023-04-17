#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using std::cout;
using std::endl;
using std::vector;

static const int HEIGHT = 600;
static const int WIDTH =300;
static const int FPS = 60;
static const int frameDelay = 1000/FPS;

static const int BARWIDTH = 80;
static const int BARHEIGHT = 20;
static const int BALLSIZE = 15;
static const int STARTPOSITION = 300;
const std::string BARIMAGE = "draw/barrier.png";
const std::string BALLIMAGE = "draw/ball.png";

static SDL_Window *gWindow;
static SDL_Renderer *gRenderer;
static SDL_Texture *gTexture;

class textureManager{
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    private:
};