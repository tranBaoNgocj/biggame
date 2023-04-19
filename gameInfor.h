#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>

static const int HEIGHT = 600;
static const int WIDTH = 400;
static const int FPS = 60;
static const int frameDelay = 1000/FPS;
static const int GAME_START_POSITION = 200;
static const int BOARD_WIDTH = 64;
static const int BOARD_HEIGHT = 20;
static const int BOARD_START_POSITION = 500;

static const char* ballName = "draw/ball.png";
static const char* boardName = "draw/barrier.png";

class textureManager {
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    private:
};