#include <iostream>
#include <map>
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

//Args: information of barrier
//Result: print barrier

void printBarrier(map <int,int> barrier){
    string firstLine(35,'-');
    cout<<firstLine<<endl;
    for(auto x:barrier){
        for(int i=0;i<35;i++){
            if (i>x.second && i<x.second+4) cout<<"_";
            else cout<<" ";
        }
        cout<<endl;
    }
}