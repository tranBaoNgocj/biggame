#include "Button.h"

button::button(SDL_Renderer* ren,const char* filename,int x, int y)
{
    renderer = ren;
    buttonTexture = textureManager::LoadTexture(filename,ren);
    xpos =  x;
    ypos = y;

	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void button::HandleMouseEvent(SDL_Event *e)
{
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		int button_width = BUTTON_SIZE, button_height = BUTTON_SIZE ;
		

		SDL_GetMouseState(&x, &y);

		bool inside = true;
		if (x < xpos)
		{
			inside = false;
		}
		else if (x > xpos + button_width)
		{
			inside = false;
		}
		else if (y < ypos)
		{
			inside = false;
		}
		else if (y > ypos + button_height)
		{
			inside = false;
		}
		if(!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				// case SDL_MOUSEMOTION:
				// mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				// break;
			
				case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

				default:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
				break;
			}	
		}
	}
}


void button::Render()
{
	srcRect.x = 0;
    srcRect.y =0;
    srcRect.h = BUTTON_SIZE;
    srcRect.w = BUTTON_SIZE;

    desRect.h = BUTTON_SIZE;
    desRect.w = BUTTON_SIZE;
    desRect.x = xpos;
    desRect.y = ypos;
    SDL_RenderCopy(renderer, buttonTexture,&srcRect,&desRect);
}