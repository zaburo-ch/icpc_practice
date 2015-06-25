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

struct node{
    int d,c,n;
    bool operator<( const node& right ) const {
        return d == right.d ? c < right.c : d > right.d;
    }
};

int main(){
    while(1){
        int c, n, m, s, goal;
        scanf("%d%d%d%d%d",&c,&n,&m,&s,&goal);
        if(!c)break;
        s--;goal--;

        vector<vector<edge> > g(n);
        for(int i=0;i<m;i++){
            int a, b, f;
            scanf("%d%d%d",&a,&b,&f);
            a--;b--;
            g[a].push_back((edge){b,f});
            g[b].push_back((edge){a,f});
        }

        vector<vec> d(c+1,vec(n,INF));
        d[c][s] = 0;
        priority_queue<node> que;
        que.push((node){0,c,s});

        int ans = INF;
        while(que.size()){
            node p = que.top(); que.pop();
            //printf("n=%d d=%d c=%d\n",p.n,p.d,p.c);
            if(d[p.c][p.n] < p.d) continue;
            if(p.n == goal){
                ans = p.d;
                break;
            }
            for(int i=0;i<g[p.n].size();i++){
                int to = g[p.n][i].to;
                if(p.c > 0){
                    int dist_to_use_c = p.d + g[p.n][i].cost/2;
                    if(d[p.c-1][to] > dist_to_use_c){
                        d[p.c-1][to] = dist_to_use_c;
                        //printf("pushed d=%d c=%d n=%d\n",dist_to_use_c,p.c-1,to);
                        que.push((node){dist_to_use_c,p.c-1,to});
                    }
                }
                int dist_to = p.d + g[p.n][i].cost;
                if(d[p.c][to] > dist_to){
                    d[p.c][to] = dist_to;
                    //printf("pushed d=%d c=%d n=%d\n",dist_to,p.c,to);
                    que.push((node){dist_to,p.c,to});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
