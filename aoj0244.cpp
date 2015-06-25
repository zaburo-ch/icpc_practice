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
typedef vector<vec> mat;
typedef pair<int,int> P;
struct edge{int to,cost;};

struct State{
    int d,n,t;
    bool operator<(const State& right) const{
        return d == right.d ? t < right.t : d > right.d;
    }
};

int main(){
    int n, m;
    while(cin >> n >> m, n){
        vector<vector<edge> > g(n);
        for(int i=0;i<m;i++){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            g[a].push_back((edge){b,c});
            g[b].push_back((edge){a,c});
        }

        vector<vec> d(2, vec(n, INF));
        d[1][0] = 0;
        priority_queue<State> que;
        que.push((State){0,0,1});
        while(que.size()){
            State p = que.top(); que.pop();
            if(d[p.t][p.n]<p.d) continue;
            if(p.n==n-1){
                cout << p.d << endl;
                break;
            }
            if(p.t){
                for(int i=0;i<g[p.n].size();i++){
                    int nn1 = g[p.n][i].to;
                    for(int j=0;j<g[nn1].size();j++){
                        int nn2 = g[nn1][j].to;
                        if(d[0][nn2] > p.d){
                            d[0][nn2] = p.d;
                            que.push((State){p.d,nn2,0});
                        }
                    }
                }
            }
            for(int i=0;i<g[p.n].size();i++){
                int nn = g[p.n][i].to, nd = p.d + g[p.n][i].cost;
                if(d[p.t][nn] > nd){
                    d[p.t][nn] = nd;
                    que.push((State){nd,nn,p.t});
                }
            }
        }
    }

    return 0;
}
