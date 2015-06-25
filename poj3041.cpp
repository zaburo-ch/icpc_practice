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
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

const int MAX_N = 500;
const int MAX_V = 2*MAX_N + 2;
struct edge{int to, cap, rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f){
    if (v == t) return f;
    used[v] = true;
    for(int i=0;i<G[v].size();i++){
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}


int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int s = 2*N, t = s+1;
    for(int i=0;i<K;i++){
        int r,c;
        scanf("%d %d",&r,&c);
        r--;c--;
        add_edge(r,N+c,1);
    }
    for(int i=0;i<N;i++){
        add_edge(s,i,1);
        add_edge(N+i,t,1);
    }
    cout << max_flow(s, t) << endl;

    return 0;
}