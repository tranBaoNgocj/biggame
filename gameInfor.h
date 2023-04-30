#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

static const int HEIGHT = 700;
static const int WIDTH = 400;
static const int FPS = 60;
static const int frameDelay = 1000/FPS;
static const int GAME_START_POSITION = 200;
static const int BOARD_WIDTH = 64;
static const int BOARD_HEIGHT = 7;
static const int BALL_SIZE = 27;
static const int BOARD_START_POSITION = 650;
static const int BOARD_END_POSITION = 20;
static const int BUTTON_SIZE = 72;

static const char* ballName = "draw/ball.png";
static const char* safeBoardName = "draw/safeboard.png";
static const char* dangerBoardName = "draw/dangerboard.png";
static const char* backgroundName = "draw/background.png";
static const char* fontPath = "draw/PixeloidSans-Bold.ttf";

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
};


class textureManager {
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    private:
};