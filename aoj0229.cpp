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
struct edge{int to,cost;};

int main(){

    while(1){
        int b,r,g,c,s,t;
        scanf("%d%d%d%d%d%d",&b,&r,&g,&c,&s,&t);
        if(!b&&!r&&!g&&!c&&!s&&!t)break;
        cout << 100 + b*15 + b*5*13 + r*15 + r*3*13 + g*7 + c*2 - 3*(t - (b*5 + r*3 + s)) << endl;
    }

    return 0;
}
