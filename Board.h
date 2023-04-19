#include "gameInfor.h"
#include <vector>

using std::vector;

class board{
    public:
        board(SDL_Renderer* ren,int x, int y);
        void Update();
        void Render();
        bool OutScreen();
        SDL_Renderer* renderer;
// private:
        int xpos;
        int ypos;

        SDL_Texture* boardTexture;
        SDL_Rect srcRect, desRect;
};

void CreatStartBar (vector <board> &boardManager, SDL_Renderer* ren);
void CreatABoard (vector <board> &boardManager,SDL_Renderer* ren);
void UpDate(vector <board> &boardManager);
void RenDer(vector <board> boardManager);