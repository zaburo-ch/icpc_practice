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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1);

struct team{
    int mis[10];
    int m,n,t;
    team(){
        fill(mis,mis+10,0);
        m = 0;
        n = 0;
        t = 0;
    }
};

bool cmp(const team& left, const team& right){
    if (left.n == right.n){
        if (left.m == right.m){
            return left.t > right.t;
        }else{
            return left.m < right.m;
        }
    }else{
        return left.n > right.n;
    }
}

int main(){
    while(1){
        int M,T,P,R;
        cin >> M >> T >> P >> R;
        if (M==0)break;

        vector<team> g(T);
        for(int i=0;i<T;i++) g[i].t = i+1;
        for(int i=0;i<R;i++){
            int m,t,p,j;
            cin >> m >> t >> p >>j;
            t--;p--;
            //printf("%d %d %d %d\n",m,t,p,j);
            if (j==0){
                g[t].n += 1;
                g[t].m += m + g[t].mis[p]*20;
            }else{
                g[t].mis[p] += 1;
            }
        }

        sort(g.begin(),g.end(),cmp);
        printf("%d",g[0].t);
        for(int i=1;i<T;i++){
            if(g[i].n == g[i-1].n && g[i].m == g[i-1].m){
                printf("=%d",g[i].t);
            }else{
                printf(",%d",g[i].t);
            }
        }
        printf("\n");
    }
}