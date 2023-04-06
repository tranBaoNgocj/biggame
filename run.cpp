#include <iostream>
#include <map>
#include "element.h"
#include "run.h"
using namespace std;

// Args:  
//Return:  start barrier
map <int,int> creatStartBarrier(){
    map<int,int> lineBarrier;
    for(int i=1;i<=8;i++){
            int n = rand()%30;
            lineBarrier.insert({i,n});
    }
    return lineBarrier;
}

//Args: information of barrier and ball
//Result: print barrier and ball

void printBarrier(map <int,int> barrier, ball rapid){
    string firstLine(35,'-');
    cout<<firstLine<<endl;
    for(auto x:barrier){
        if(x.first == rapid.height){
            for(int i=0;i<35;i++){
                if(i==rapid.currentBarrierPosition+1) cout<<"o";
                else cout<<" ";
            }
        cout<<endl;
        }
        for(int i=0;i<35;i++){
            if (i>x.second && i<x.second+4) cout<<"_";
            else cout<<" ";
        }
        cout<<endl;
    }
}

//Args: current barrier
// Return: barrier move up 1 step
map <int,int> nextBarrier(map <int,int>& barrier){
    int n= rand()%30;
    for(int i=0; i<7;i++){
        barrier[i] = barrier[i+1];
    }
    barrier[7]=n;
    return barrier;
}

//Args:
// Return: player choice
int getPlayerChoice(){
    char answer;
    cin>>answer;
    if(answer == 'a') return -1;
    else if(answer == 'd') return 1;
    return 0;
}

//Args: playerChoice
// Return: change ball position
ball changeBallPosition(ball& rapid, map<int,int> barrier){
    rapid.position +=getPlayerChoice();
    if(rapid.position< rapid.currentBarrierPosition || rapid.position> rapid.currentBarrierPosition+2) {
        //ball down
        rapid.height ++;
        if(rapid.position < barrier[rapid.height] || rapid.position > barrier[rapid.height]+1) rapid.height ++;
    }
    else rapid.height--
    ;
    return rapid;
}