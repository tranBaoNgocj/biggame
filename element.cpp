#include "element.h"

// extern SDL_Renderer *gRender;
// extern SDL_Window *gwindow;	

 // --------------barr -----------------
    bar::bar(const char* textureSheet, SDL_Renderer* ren,int y){
        xpos = rand()%35;
        ypos = y;
        renderer = ren;
        objectTexture = textureManager::LoadTexture(textureSheet,ren);
    }

    void bar::update()
    {
        ypos -=1000/FPS;

        srcRect.x = xpos;
        srcRect.y = ypos;
        srcRect.w = BARWIDTH;
        srcRect.h = BARHEIGHT;
    }
    void bar::Render(){
	    SDL_RenderFillRect(renderer, &srcRect);
    }

    // -------------------ball --------------------- 
    //creat ball
    ball::ball(const char* textureSheet, SDL_Renderer* ren,int x, int y){
       renderer = ren;
       objectTextue = textureManager::LoadTexture(textureSheet,ren);
       xpos = x;
       ypos = y;
    }

    bool ball::ballOut(bar &bar_)
    {
    if ((ypos == bar_.ypos) &&  //   o--- like this
		(xpos <= bar_.xpos + BARWIDTH / 2 && xpos >= bar_.xpos - BARWIDTH / 2)) { //--o-- like this
		return true;
	}
	return false;
    }
    

    //update position and height
    void ball::move(barManager &bars_,int type){

        //position of ball
        if (type == 1) xpos -= 1000 / FPS;
	    else if (type == 2) xpos +=  1000 / FPS;


        for(int i =0; i< bars_.bars.size();i++){
            if(ballOut(bars_.bars[i])){

                // IF ball still in bar
                ypos = bars_.bars[i].ypos;
                return;
            }
        }

        //else 
        ypos += 1000/FPS;
    }


    // temp graphic
    void ball::Render(){
        SDL_RenderCopy(renderer, objectTextue, &srcRect, &desRect);
    }

    // 

   

//-----------------Manager--------------------
        barManager::barManager()
        {
            int GAP = 100;
        };

        void barManager::creatStartBar(const char* textureSheet, SDL_Renderer* ren)
        {
            for(int i = HEIGHT; i>= STARTPOSITION; i-= BARHEIGHT){
                int n = rand()%3;
                if(n){
                    bar x(textureSheet,ren,i);
                    bars.push_back(x);
                }
            }

        }

        //erase bar out of scene
    void barManager::clearInlegal()
    {
       for (int i = bars.size() - 1; i >= 0; i--) {
		if (isOut(bars[i])) bars.erase(bars.begin() + i);
	    }
    }

    bool barManager::isOut( bar &bar_)
    {
        if (bar_.ypos <= 12) return true;
	    return false;
    }

    void barManager::move()
    {
        for (int i = 0; i < bars.size(); i++) {
		bars[i].update();
	}
    }

    void barManager::draw()
    {
        for (int i = 0; i < bars.size(); i++) {
		bars[i].Render();
	}
    }

    void barManager::creatABoard(const char* textureSheet, SDL_Renderer* ren)
    {
        clearInlegal();
	    // int gap = now - *last;
	    // if (gap >= GAP - 1000 / FPS * 2 && gap <= GAP + 1000 / FPS * 2) {
		// int st = rand() % WIDTH;
		// GAP = rand() % 300 + 250;
		// *last = now;
        int n = rand()% 3;
        if( n ){
            bar x(textureSheet,ren,280);
            bars.push_back(x);
        }
	}

