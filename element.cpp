#include "element.h"
    

    // -------------------ball --------------------- 
    //creat ball
    ball::ball(int size_,SDL_Point pos_){
       pos = pos_;
       size = size_;
    }

    bool ball::ballOut(bar & bar_)
    {
    if ((pos.y == bar_.pos.y) &&  //   o--- like this
		(pos.x <= bar_.pos.x + bar_.width / 2 && pos.x >= bar_.pos.x - bar_.width / 2)) { //--o-- like this
		return true;
	}
	return false;
    }
    

    //update position and height
    void ball::update(barManager &bars_,int type){
        //position of ball
    if (type == 1) pos.x -= 1000 / FPS;
	else if (type == 2) pos.x +=  1000 / FPS;
        for(int i =0; i< bars_.bars.size();i++){
            if(ballOut(bars_.bars[i])){
                // if(!game::isBump){
                //     game::isBump = true;
                // }
                pos.y = bars_.bars[i].pos.y;
                return;
            }
        }
        //update ball height
        pos.y += 1000/FPS;
        if(pos.y >= HEIGHT || pos.y <= 0){
            gameRun == false;
        }
    }


    // temp graphic
    void ball::printBall(SDL_Color color = {0,0,0,0xff}){
        SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
        int posX = pos.x;
        int posY = pos.y;
        SDL_Rect rects[3];
        rects[0] = { posX -30/ 2,posY-30/ 6,30,10 };
	    rects[1] = { posX -30/ 6,posY-30/ 2,10,30 };
	    rects[2] = { posX-30 / 3,posY-30/ 3,2 * 30 / 3,2 * 10 / 3 };
        SDL_RenderFillRects(render,rects, 3);
    }

    // 

    // --------------barr -----------------
    bar::bar( SDL_Point pos_, int width_){
        pos = pos_;
        width = width_;
    }

    void bar::draw()
    {
        SDL_Rect _bar;
        _bar.x = pos.x - width/2;
        _bar.y = pos.y;
        _bar.w = width;
        _bar.h = 10;
	    SDL_RenderFillRect(render, &_bar);
    }

    void bar:: move(){
        pos.x += 1000/FPS;
       }

// -----------------Manager--------------------
        //erase bar out of scene
    void barManager::clearInlegal()
    {
       for (int i = bars.size() - 1; i >= 0; i--) {
		if (isOut(bars[i])) bars.erase(bars.begin() + i);
	    }
    }

    bool barManager::isOut( bar &bar_)
    {
        if (bar_.pos.y <= 12) return true;
	    return false;
    }

    void barManager::move()
    {
        for (int i = 0; i < bars.size(); i++) {
		bars[i].move();
	}
    }

    void barManager::draw()
    {
        for (int i = 0; i < bars.size(); i++) {
		bars[i].draw();
	}
    }

    void barManager::creatABoard(int* last, int now)
    {
        clearInlegal();
	int gap = now - *last;
	if (gap >= GAP - 1000 / FPS * 2 && gap <= GAP + 1000 / FPS * 2) {
		srand(now);
		int st = rand() % WIDTH;
		GAP = rand() % 300 + 250;
		*last = now;
	}
    }


