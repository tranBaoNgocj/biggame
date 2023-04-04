#include <bits/stdc++.h>
#include "element.h"
#include "run.h"
#include <map>
using namespace std;


int main (){
    srand(time(0));
    map <int,int> barrier = creatStartBarrier();
   printBarrier(barrier);
//   ball rapid(4,barrier[4],barrier[4]);
//   cout<<rapid.height<<" "<<rapid.position<<" "<<rapid.currentBarrierPosition;
   return 0;
}