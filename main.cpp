#include <bits/stdc++.h>
#include "element.h"
#include "run.h"
#include <map>
using namespace std;

int main (){
    srand(time(0));
    //start Game
    map <int,int> barrier = creatStartBarrier();
    ball rapid(4,barrier[4]+1,barrier[4]);
    printBarrier(barrier,rapid);
    do{
        // change ball position use player opinion
            changeBallPosition(rapid,barrier);
        //constant update new barrier and move up
            printBarrier(nextBarrier(barrier),rapid);
        
    }
    while(rapid.height >=0 && rapid.height<=8);
    return 0;
}