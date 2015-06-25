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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int n, m;
int d[251];
vec G[252];
vec rG[252];
bool can_goal[252];
bool visited[252];

void dfs(int v){
    can_goal[v] = true;
    for(int i=0;i<rG[v].size();i++){
        if(!can_goal[rG[v][i]]) dfs(rG[v][i]);
    }
}

bool dfs2(int v){
    visited[v] = true;
    if(!can_goal[v]) return false;
    for(int i=0;i<G[v].size();i++){
        if(!visited[G[v][i]]&&!dfs2(G[v][i])){
            return false;
        }
    }
    return true;
}

void add_edge(int f,int t){
    G[f].push_back(t);
    rG[t].push_back(f);
}

int main(){
    while(cin >> m, m){
        cin >> n;

        for(int i=0;i<n+2;i++){
            G[i].clear();
            rG[i].clear();
        }
        d[0] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &d[i]);
        }
        for(int i=0;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(i+j >= n+1 || i+j+d[i+j] >= n+1){
                    add_edge(i, n+1);
                }else{
                    add_edge(i, max(0, i+j+d[i+j]));
                }
            }
        }

        memset(can_goal, 0, sizeof(can_goal));
        dfs(n+1);
        memset(visited, 0, sizeof(visited));
        if(dfs2(0))cout << "OK" << endl;
        else cout << "NG" << endl;
    }
    return 0;
}
