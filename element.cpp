#include <bits/stdc++.h>
#include "element.h"
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

struct ball {
    int height;
    int position;
    ball(int _height, int _position){
        height = _height;
        position = _position;
    }
    void printBall(ball a){
        for(int i=0;i<35;i++){
            if(i==a.position) cout<<"o";
            else if(i==0 || i==34) cout<<"|";
            else cout<<" ";
        }
        cout<<endl;
    }
};

void firstLine(){
    string firstLine(35,'-');
    cout<<firstLine<<endl;
}
