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

/************ LCA : binary search ************/
const int MAX_V = 8;
const int MAX_LOG_V = 3;
vector<int> G[MAX_V];
int root;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);
    for(int k=0;k+1<MAX_LOG_V;k++){
        for(int v=0;v<V;v++){
            if(parent[k][v]<0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u]>depth[v]) swap(u, v);
    for(int k=0;k<MAX_LOG_V;k++){
        if((depth[v]-depth[u])>>k&1){
            v = parent[k][v];
        }
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}


int main(){
    int a[] = {0,0,1,1,2,4,4};
    int b[] = {1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    root = 0;
    init(8);

    cout << lca(3,6) << endl;
    cout << lca(7,5) << endl;
    cout << lca(4,7) << endl;

    return 0;
}