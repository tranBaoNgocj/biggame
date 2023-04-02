#include <bits/stdc++.h>
#include "drawBG.h"
using namespace std;

struct barrier {
    int height; int position;
    barrier(int _height, int _position){
        height = _height;
        position = _position;
    }
    void printBar (barrier a){
        for(int i=0;i<35;i++){
            if(i==0 || i==34) cout<<"|";
            else {
                if(i>=a.position && i<=a.position+4) cout<<"_";
                else cout<<" ";
            }
        }
        cout<<endl;
    }
};
