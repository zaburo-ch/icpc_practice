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

int N;
vector<vector<edge> > g;
vector<bool> is_leaf;

int dfs(int v, int prev){
    int cost = 0;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i].to;
        if(is_leaf[to] || to==prev) continue;
        cost = max(cost, g[v][i].cost + dfs(to, v));
    }
    return cost;
}

int main(){
    while(1){
        scanf("%d",&N);
        if(!N)break;

        g.assign(N, vector<edge>());
        for(int i=0;i<N-1;i++){
            int a, b, t;
            scanf("%d%d%d",&a,&b,&t);
            a--;b--;
            g[a].push_back((edge){b,t});
            g[b].push_back((edge){a,t});
        }

        is_leaf.assign(N, false);
        for(int i=0;i<N;i++){
            if(g[i].size()==1) is_leaf[i] = true;
        }
        is_leaf[0] = false;

        int all_path_twice = 0;
        for(int i=0;i<N;i++){
            if(is_leaf[i]) continue;
            for(int j=0;j<g[i].size();j++){
                if(is_leaf[g[i][j].to]) continue;
                all_path_twice += g[i][j].cost;
            }
        }
        int longest_path = dfs(0, -1);

        cout << all_path_twice-longest_path << endl;
    }

    return 0;
}
