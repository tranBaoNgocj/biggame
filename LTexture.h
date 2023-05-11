#pragma once

#include "gameInfor.h"


class Ltexture {
    public:
        //Initializes variables
        Ltexture();

        //Deallocates memory
        ~Ltexture();

        //Loads image at specified path
        bool loadFromFile( std :: string path, SDL_Renderer* gRenderer);

        //Creats image from font string
        bool loadFromRenderedText( SDL_Renderer* gRenderer, TTF_Font *gFont, std::string textureText, SDL_Color textColor);
        
        // Deallocates texture
        void free();

        //Set color modulation
        void setColor ( Uint8 red, Uint8 green, Uint8 blue);
        
        //Set blending
        void setBlendMode (SDL_BlendMode blending);
        
        //Set alpha modulation
        void setAlpha( Uint8 alpha);

        //Renders texture at given point
        void render( int x, int y, SDL_Renderer* gRenderer,int width = 0, int height = 0 , SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        
        // Gets image dimensions
        int getWidth();
        int getHeight();
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        int mWidth;
        int mHeight;
};      