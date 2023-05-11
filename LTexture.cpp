#include "LTexture.h"

Ltexture :: Ltexture()
{
    // Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight =0;
}

Ltexture:: ~Ltexture()
{
    //Deallocate
    free();
}

bool Ltexture::loadFromFile(std:: string path, SDL_Renderer* gRenderer)
{
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;
	
	//Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL)
    {
        std::cout<<"Unable to load image ! SDL_image Error:"<<std::endl;
    }
    else
    {
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
        {
            std::cout<<"Unable to create texture from surface"<<std::endl;
        }
        else
        {
        //Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
    }
    //Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool Ltexture::loadFromRenderedText( SDL_Renderer* gRenderer, TTF_Font *gFont, std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture
	free();

	//Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont,textureText.c_str(), textColor);
    if( textSurface == NULL)
    {
        std::cout<<"Unable to render text surface!"<<std::endl;
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
    }

    //Return success
	return mTexture != NULL;
}

void Ltexture::free()
{
    //Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Ltexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Ltexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void Ltexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}


void Ltexture::render( int x, int y,SDL_Renderer* gRenderer,int width, int height, SDL_Rect* clip, double angle , SDL_Point* center, SDL_RendererFlip flip)
{
    //Set rendering space and render to screen
    if(width && height){
        mWidth = width;
        mHeight = height;
    }
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );

}

int Ltexture::getWidth()
{
	return mWidth;
}

int Ltexture::getHeight()
{
	return mWidth;
}