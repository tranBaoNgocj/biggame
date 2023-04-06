#ifndef RUN_H
#define RUN_H

#include<bits/stdc++.h>
#include <map>
using namespace std;

map <int,int> creatStartBarrier();
void printBarrier(map <int,int> barrier,ball rapid);
map <int,int> nextBarrier(map <int,int>& barrier);
ball changeBallPosition(ball& rapid, map<int,int> barrier);

#endif