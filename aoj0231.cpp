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
        int n;
        scanf("%d",&n);
        if(!n)break;

        vector<P> change;
        for(int i=0;i<n;i++){
            int m,a,b;
            scanf("%d%d%d",&m,&a,&b);
            change.push_back(P(a,m));
            change.push_back(P(b,-m));
        }

        //同じ時刻に渡り始める人と渡り終わる人が居ても
        //渡り終わる時の重さの変動が負なのでソートによって渡り始める人より先にくるため題意に合う
        sort(change.begin(),change.end());
        int sum_m = 0;
        bool is_broken = false;
        for(int i=0;i<change.size();i++){
            sum_m += change[i].second;
            if(sum_m>150){
                is_broken = true;
                break;
            }
        }
        if(is_broken)cout << "NG" << endl;
        else cout << "OK" << endl;
    }

    return 0;
}
