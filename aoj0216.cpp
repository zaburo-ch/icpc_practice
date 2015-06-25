#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
#include <complex>
using namespace std;

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef pair<int,P> iP;


int main(){
    while(1){
        int w;
        scanf("%d",&w);
        if(w==-1)break;

        int cost=1150;
        w -= 10;
        if(0<w){
            if(w>10){
                cost += 1250;
            }else{
                cost += w * 125;
            }
        }

        w -= 10;
        if(0<w){
            if(w>10){
                cost += 1400;
            }else{
                cost += w * 140;
            }
        }

        w -= 10;
        if(0<w){
            cost += w * 160;
        }
        cout << 4280-cost << endl;
    }

    return 0;
}
