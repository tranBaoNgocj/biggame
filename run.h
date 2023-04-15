#ifndef RUN_H
#define RUN_H

#include <iostream>
#include "element.h"

class game{
    public:
        game();
        void run();
        void quit();
        bool welcome();
        const static int tranigleSize = 10;
        const static int up = 12;
        const static int down = HEIGHT;
        const static int ballSize = 15;
        const static int barWidth = 80;
        const static char *windouName;
    private:
        void drawTranigle(int st_, int edgePos_,bool flag_);
        void drawFence();
};


#endif